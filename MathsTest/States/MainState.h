#pragma once

#include <SDL.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <time.h>
#include "../PGGAssignment2Code/StateManager.h"
#include "../PGGAssignment2Code/Camera.h"
#include "../PGGAssignment2Code/State.h"
#include "../Core/Logging.h"
#include "../Core/PerformanceTest.h"
#include "../Maths/Vec2.h"
#include "../Maths/Vec4.h"
#include "../Maths/Mat4.h"
#include "../Maths/Quaternion.h"
#include "../Maths/Convert.h"
#include "../Sam.h"
#include "MainStateUI.h"

/**
@brief The main state of the program.
*/
class MainState : public State
{
public:
	/**
	@brief Constructs a MainState.
	@param stateManager A pointer to the StateManager.
	@param window A pointer to the window.
	@param screenWidth The screen width.
	@param screenHeight The screen height.
	*/
	MainState(StateManager* stateManager, SDL_Window* window, int screenWidth, int screenHeight);

	/**
	@brief Destructs a MainState object.
	*/
	~MainState();

	/**
	@brief Handles the MainState input.
	@returns If false then quit the MainMenu State.
	*/
	bool input();

	/**
	@brief A function to update the MainState.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function to draw to the screen.
	*/
	void draw();

private:
	///The loaded Object files
	///(left over from PGG, not really needed as only have one object and shader but is a lot of work to remove)
	std::unordered_map<std::string, Object*> objects;
	///The loaded Shader files
	///(left over from PGG, not really needed as only have one object and shader but is a lot of work to remove)
	std::unordered_map<std::string, Shader*> shaders;
	///The MainStateUI
	MainStateUI* userInterface;
	///The 3D model
	Sam* sam;
	///The Camera for the program
	Camera* camera;
	///The array of matrix's to use
	std::vector<Maths::Mat4> matrix;
	///The array of quaternion's to use
	std::vector<Maths::Quaternion> quats;
	///The performance tester
	Core::PerformanceTest* tester;

	/**
	@brief Draws a LoadingScreen.
	*/
	void loadingScreen();

	/**
	@brief Initialise 10 sets of matrixs and quats.
	*/
	void init10MatQuats();

	/**
	@brief Initialise 100 sets of matrixs and quats.
	*/
	void init100MatQuats();

	/**
	@brief Initialise 1000 sets of matrixs and quats.
	*/
	void init1000MatQuats();

	/**
	@brief Initialise 10000 sets of matrixs and quats.
	*/
	void init10000MatQuats();

	/**
	@brief Runs the performance test.
	*/
	void performanceTest();

	/**
	@brief Runs the memory test.
	*/
	void memoryTest();

	/**
	@brief Runs the matrix performance test of the X axis.
	*/
	void xAxisMatRotationTest();

	/**
	@brief Runs the matrix performance test of the Y axis.
	*/
	void yAxisMatRotationTest();

	/**
	@brief Runs the matrix performance test of the Z axis.
	*/
	void zAxisMatRotationTest();

	/**
	@brief Runs the quat performance test of the X axis.
	*/
	void xAxisQuatRotationTest();

	/**
	@brief Runs the quat performance test of the Y axis.
	*/
	void yAxisQuatRotationTest();

	/**
	@brief Runs the quat performance test of the Z axis.
	*/
	void zAxisQuatRotationTest();
};