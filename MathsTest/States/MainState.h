#pragma once

#include <SDL.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <time.h>
#include "../PGGAssignment2Code/StateManager.h"
#include "../PGGAssignment2Code/Camera.h"
#include "../PGGAssignment2Code/State.h"
#include "../Core/Logging.h"
#include "../Maths/Vec2.h"
#include "../Maths/Vec4.h"
#include "../Maths/Mat4.h"
#include "../Sam.h"

/**
@brief The main state of the program.
*/
class MainState : public State
{
private:
	///The loaded Object files
	///(left over from PGG, not really needed as only have one object and shader but is a lot of work to remove)
	std::unordered_map<std::string, Object*> objects;
	///The loaded Shader files
	///(left over from PGG, not really needed as only have one object and shader but is a lot of work to remove)
	std::unordered_map<std::string, Shader*> shaders;
	///The 3D model
	Sam* sam;
	///The Camera for the program
	Camera* camera;
	///Current Mouse position
	Maths::Vec2 mouse;
	///The array of matrix's to use
	Maths::Mat4 matrix[9];

	//tmp for testing
	float angleUpdate;

public:
	/**
	Constructs a MainState.
	@param stateManager A pointer to the StateManager.
	@param window A pointer to the window.
	@param screenWidth The screen width.
	@param screenHeight The screen height.
	*/
	MainState(StateManager* stateManager, SDL_Window* window, int screenWidth, int screenHeight);

	/**
	Destructs a MainState object.
	*/
	~MainState();

	/**
	Handles the MainState input.
	@returns If false then quit the MainMenu State.
	*/
	bool input();

	/**
	A function to update the MainState.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	A function to draw to the screen.
	*/
	void draw();
};