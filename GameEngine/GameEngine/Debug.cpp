#include "stdafx.h"
#include "Debug.h"


Utility::Debug::Debug()
{
	Log("Starting Debug");
}

void Utility::Debug::Log(string String)
{
	cout << String << endl;
}

void Utility::Debug::Spacer()
{
	Log("-----------");
}
