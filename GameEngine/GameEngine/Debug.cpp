#include "stdafx.h"
#include "Debug.h"


Utility::Debug::Debug()
{
	Log("Starting Debug");
}

void Utility::Debug::Log(string String)
{
	cout << String << endl;	

	string logString = String + "\n";
	log.AddLog(logString.c_str());
}

void Utility::Debug::Spacer()
{
	Log("-----------");
}

void Utility::Debug::DrawConsoleWindow() {	
	log.Draw("Console");
}


