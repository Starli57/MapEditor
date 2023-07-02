#pragma once
#include <iostream>

#include "../code/windows/inspector/Inspector.h"
#include "../code/particleSystem/ParticleSystem.h"
#include "../code/utility/di/Di.h"
#include "../code/windows/console/LogConsole.h"

using namespace ParticleSystemEditor;

class Editor
{
public:
	LogConsole* logConsole;
	Inspector* inspector;

	Editor();
	~Editor();
	
	void Update();
	void Render();

};
