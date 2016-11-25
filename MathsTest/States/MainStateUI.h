#pragma once

#include <SDL.h>
#include <iostream>
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
	@param vertexShaderFileName The name of the vertex shader file.
	@param fragmentShaderFileName The name of the fragment shader file.
	@param shaders A reference to the loaded Shader files
	*/
	MainStateUI(std::string vertexShaderFileName, std::string fragmentShaderFileName,
		std::unordered_map<std::string, Shader*> &shaders);

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

private:
	///The Title Image
	UIObject * background;
	///The Button
	UIObject * button;
	///The Play Text
	UIObject * buttonText;
};