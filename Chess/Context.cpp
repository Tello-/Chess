#include "Context.hpp"

Context::Context(IState* state)
     : state_(nullptr) 
{
     this->TransitionTo(state);
}

Context::~Context()
{
     delete state_;
}

void Context::TransitionTo(IState* state)
{
     std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
     if (this->state_ != nullptr)
          delete this->state_;
     this->state_ = state;
     this->state_->set_context(this);
}
