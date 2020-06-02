#pragma once
#include <typeinfo>
#include <iostream>
#include "IState.hpp"
/**
 * The Context defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the Context.
 */

class Context {
     /**
      * @var State A reference to the current state of the Context.
      */
private:
     IState* state_;

public:
     Context(IState* state);
     ~Context();


     /*The Context allows changing the State object at runtime.*/
     void TransitionTo(IState* state);

     /*The Context delegates part of its behavior to the current State object. */
     void Update() {
          this->state_->UpdateState();
     }
     void Render() {
          this->state_->RenderState();
     }
};
