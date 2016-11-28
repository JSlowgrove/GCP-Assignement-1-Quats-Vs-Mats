#pragma once

#include <SDL.h>
#include <iostream>
#include <cstdint>
#include <sstream>
#include <iomanip> 
#include <unordered_map>
#include "../PGGAssignment2Code/Shader.h"
#include "../PGGAssignment2Code/UIObject.h"
#include "../PGGAssignment2Code/UI.h"
#include "../Core/Logging.h"

/**
@brief A UI for the MainState using my old PGG2 UI classes.
*/
class MainStateUI : public UI
{
public:
	/**
	@brief Constructs the MainStateUI.
	@param shaders A reference to the loaded Shader files
	*/
	MainStateUI(std::unordered_map<std::string, Shader*> &shaders);

	/**
	@brief Destructs the MainStateUI object.
	*/
	~MainStateUI();

	/**
	@brief A function to update the MainStateUI.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function to draw to the screen.
	*/
	void draw();

	/**
	@brief A function to draw to the loading text to the screen.
	*/
	void drawLoading() { loadingText->draw(shader); }

	/**
	@brief A function to draw to the performance text to the screen.
	*/
	void drawPerformance() { performanceText->draw(shader); }

	/**
	@brief A function to update the time text.
	@param time The time to update the text to.
	*/
	void updateTime(float time);

	/**
	@brief A function to update the axis.
	@param axis The axis to switch to.
	*/
	void updateAxis(char axis);

	/**
	@brief A function to update the method.
	@param method The method to switch to.
	*/
	void updateMethod(char method);

	/**
	@brief A function to update the number of rotations.
	@param rotations The number of rotations to switch to.
	*/
	void updateNumberOfRotations(int rotations);

	/**
	@brief A function to update the memory text.
	@param memory The memory to update the text to.
	*/
	void updateMemory(int memory);

	/**
	@brief A function to get the current axis.
	@returns The current axis.
	*/
	char getAxis() { return axis; }

	/**
	@brief A function to get the current number of rotations.
	@returns The current number of rotations.
	*/
	int getRotations() { return rotations; }

	/**
	@brief A function to get the current method.
	@returns The current method.
	*/
	char getMethod() { return method; }

	/**
	@brief A function to set the help state.
	@param state The state of help.
	*/
	void setHelp(bool state) { helpState = state; }

	/**
	@brief A function to get the current help state.
	@returns The current help state.
	*/
	bool getHelp() { return helpState;  }

private:
	///The Title Image
	UIObject * background;
	///The help image
	UIObject * help;
	///Info Text
	UIObject * axisText;
	UIObject * numberOfRotationsText;
	UIObject * rotationMethodText;
	UIObject * matrixText;
	UIObject * quatText;
	UIObject * xText;
	UIObject * yText;
	UIObject * zText;
	UIObject * set10Text;
	UIObject * set100Text;
	UIObject * set1000Text;
	UIObject * set10000Text;
	UIObject * helpText;
	///The performance texts
	UIObject * timeText;
	UIObject * memoryText;
	///The loading text
	UIObject * loadingText;
	UIObject * performanceText;
	///the current axis
	char axis;
	int rotations;
	char method;
	///if the help should be displayed
	bool helpState;
};