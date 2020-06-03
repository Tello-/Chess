#pragma once
#include "IState.hpp"

class P2_Move_State :
	public IState
{
	virtual void ProcessInput() {}
	virtual void UpdateState() = 0;
	virtual void RenderState() = 0;
};

