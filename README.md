# Game_Engine


# SFML Setup

**SFML Download**
* Download the latest version of SFML from: https://www.sfml-dev.org/download.php
* Currently I am using version: 2.4.2
* Grab the version: Visual C++ 14 (2015) - 32-bit
* Create a folder in C:\Program Files and call it **SFML**
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
