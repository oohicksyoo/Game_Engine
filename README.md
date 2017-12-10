# Game_Engine
# SFML Setup

**SFML Download**
* Download the latest version of SFML from: https://www.sfml-dev.org/download.php
* Currently I am using version: 2.4.2
* Grab the version: Visual C++ 14 (2015) - 32-bit
* Create a folder in **C:\Program Files** and call it **SFML**
* Open zip folder from download and copy the inner contents of the SFML version folder. Should have folder such as bin, examples, lib and include

**Linking setup**
* Right click project in solution explorer window (Must create a console c++ project first)
* If you do not have a main.cpp file go ahead and create that in the source file
* In the properties windows change **Configuration** to **All Configurations**
* Select **C/C++ -> General** 
* Edit the **Additional Include Directories** to include **C:\Program Files\SFML\include**
* Select **Linker -> General**
* Edit the **Additional Library Directores** to include **C:\Program Files\SFML\lib**
* In the properties windows change **Configuration** to **Debug**
* Select **Linker -> Input**
* Add **sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-network-d.lib;sfml-audio-d.lib;** before **kernal32.lib** in the property **Additional Dependencies**
* Hit **Apply** (If greyed out select another property to get focus out of the Additional Dependencies)
* Hit **Ok**

**Adding Bin Files to Project**
* Navigate to **C:\Program Files\SFML\bin**
* Copy all files to your project folder where you can see your entry .cpp file

**Extra Help If Needed**
* http://gamecodeschool.com/sfml/building-your-first-sfml-game-project/

# Dear ImGUI Setup
* Download Dear ImGUI repo from github: https://github.com/ocornut/imgui
* Create a folder in **C:\Program Files** and call it **Dear ImGUI**
* Paste files from zip in this folder, should see things like examples, extra_fonts etc.
* Download Dear ImGUI SFML Wrappers: https://github.com/eliasdaler/imgui-sfml
* You **only** need to add the imconfig-SFML.h, imgui-SFML.cpp, and imgui-SFML.h to the **Dear ImGUI** folder system
* Open the **imconfig-SFML.h** and copy everything into the **imconfig.h** file (at the bottom of all the comments)
* In you project add the files (imgui.cpp, imgui_demo.cpp, imgui_draw.cpp, imgui-SFML.cpp) to the sources folder
* I found that since I made my project as a console project I had to include the header **#include "stdafx.h"** to each of the imported files from above
* Open project properties and under **C/C++ -> General -> Additional Include Directories** add the **C:\Program Files\Dear ImGUI** Folder
* Next go to **Linker -> Input -> Additional Dependencies** add **opengl32.lib** just above kernel32.lib
* Hit **Apply**
* Hit **Ok**
* Try a test run with the sample code from the link below

**Resource Tutorial**
https://eliasdaler.github.io/using-imgui-with-sfml-pt1/

# Lua and Lua Bridge 
**Resource Tutorial**
https://eliasdaler.wordpress.com/2014/07/18/using-lua-with-cpp-luabridge/
