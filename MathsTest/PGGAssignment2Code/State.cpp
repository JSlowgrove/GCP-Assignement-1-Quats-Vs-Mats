//DISCLAMER - This is a modified version of code from one of my other assignments.

#include "State.h"

State::State(StateManager * stateManager, SDL_Window* window, int screenWidth, int screenHeight)
{
	//sets the pointer to the state manager
	this->stateManager = stateManager;
	//sets the pointer to the window
	this->window = window;
	//load the screen dimensions
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

}

State::~State() 
{
}

SDL_Window* State::getWindow()
{
	//return the window
	return window;
}