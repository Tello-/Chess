#pragma once
#include "IState.hpp"


class P1TurnState :
	public IState
{

	virtual void UpdateState();
	virtual void RenderState();
};

