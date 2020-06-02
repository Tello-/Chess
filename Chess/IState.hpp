#pragma once

class Context;
class IState
{
protected: 
	Context* mContext;
public:
     virtual ~IState() {
     }

     void set_context(Context* context) {
          this->mContext = context;
     }

     virtual void UpdateState() = 0;
     virtual void RenderState() = 0;
};