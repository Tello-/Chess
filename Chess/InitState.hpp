#pragma once
#include "IState.hpp"



class InitState :
	public IState
{
public:
	virtual void UpdateState();
	virtual void RenderState();
};

