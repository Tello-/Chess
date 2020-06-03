#pragma once
#include "IState.hpp"
#include <string>

class P1_Choice_State :
	public IState
{
public:
	virtual void ProcessInput(std::string input);
	virtual void UpdateState();
	virtual void RenderState();
};

