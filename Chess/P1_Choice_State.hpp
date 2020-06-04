#pragma once
#include "IState.hpp"
#include <iostream>
#include <string>
#include <Windows.h>
#include "Context.hpp"


class P1_Choice_State :
	public IState
{
public:
	P1_Choice_State();
	virtual ~P1_Choice_State() {}
	virtual void ProcessInput(std::string input);
	virtual void UpdateState();
	virtual void RenderState();
};

