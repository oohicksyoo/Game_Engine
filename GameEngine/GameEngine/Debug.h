#pragma once
#include "Singleton.h"
#include <iostream>
#include <string>
#include <string.h>

//Dear Im GUI
#include "imgui.h"
#include "imgui-sfml.h"

using namespace std;
using namespace ImGui;

namespace Utility {
#pragma region Structs
	struct ConsoleLog {
		ImGuiTextBuffer Buf;
		ImGuiTextFilter Filter;
		ImVector<int> LineOffsets;        // Index to lines offset
		bool ScrollToBottom;

		void Clear() { 
			Buf.clear(); 
			LineOffsets.clear(); 
		}

		void AddLog(const char* fmt, ...) IM_FMTARGS(2) {
			int old_size = Buf.size();
			va_list args;
			va_start(args, fmt);
			Buf.appendfv(fmt, args);
			va_end(args);
			for (int new_size = Buf.size(); old_size < new_size; old_size++) {
				if (Buf[old_size] == '\n') {
					LineOffsets.push_back(old_size);
				}					
			}
				
			ScrollToBottom = true;
		}

		void Draw(const char* title, bool* p_open = NULL) {
			//Position and setup window
			ImVec2 windowPosition = ImVec2(GetIO().DisplaySize.x, GetIO().DisplaySize.y);
			ImVec2 windowPivot = ImVec2(1.0f, 1.0f);
			SetNextWindowPos(windowPosition, ImGuiCond_Always, windowPivot);
			SetNextWindowSize(ImVec2(700, 150));
			//PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.3f)); //Transparent background
			Begin(title, p_open, ImGuiWindowFlags_NoCollapse| ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
			if (Button("Clear")) {
				Clear();
			}
			SameLine();
			bool copy = Button("Copy");
			SameLine();
			Filter.Draw("Filter", -100.0f);
			Separator();
			BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
			if (copy) {
				ImGui::LogToClipboard();
			}

			if (Filter.IsActive()) {
				const char* buf_begin = Buf.begin();
				const char* line = buf_begin;
				for (int line_no = 0; line != NULL; line_no++) {
					const char* line_end = (line_no < LineOffsets.Size) ? buf_begin + LineOffsets[line_no] : NULL;
					if (Filter.PassFilter(line, line_end)) {
						TextUnformatted(line, line_end);
					}						
					line = line_end && line_end[1] ? line_end + 1 : NULL;
				}
			} else {
				TextUnformatted(Buf.begin());
			}

			if (ScrollToBottom) {
				SetScrollHere(1.0f);
			}
				
			ScrollToBottom = false;
			EndChild();
			End();
			//PopStyleColor();
		}
	};
#pragma endregion

	class Debug : public Singleton<Debug>
	{
		friend class Singleton<Debug>;
		private:
			Debug();

		public:
			void Log(string String);
			void Spacer();
			void DrawConsoleWindow();
			void ClearLogWindow();

		private:
			ConsoleLog log;

	};
}

