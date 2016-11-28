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
	void drawPerformance() { performanceText->draw(shader); }

	void updateTime(float time);
	void updateAxis(char axis);
	void updateMethod(char method);
	void updateNumberOfRotations(int rotations);
	void updateMemory(int memory);

	char getAxis() { return axis; }
	int getRotations() { return rotations; }
	char getMethod() { return method; }

	void setHelp(bool state) { helpState = state; }
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