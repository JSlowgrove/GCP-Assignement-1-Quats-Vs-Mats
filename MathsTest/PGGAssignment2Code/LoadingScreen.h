//DISCLAMER - This is a modified version of code from one of my other assignments.

#pragma once

#include <SDL.h>
#include <iostream>
#include <unordered_map>
#include "Shader.h"
#include "UIObject.h"
#include "UI.h"

/**
@brief A class for the 2D LoadingScreen that inherits UI.
*/
class LoadingScreen : public UI
{
public:
	/**
	@brief Constructs the LoadingScreen object.
	@param vertexShaderFileName The name of the vertex shader file.
	@param fragmentShaderFileName The name of the fragment shader file.
	@param shaders A reference to the loaded Shader files
	*/
	LoadingScreen(std::string vertexShaderFileName, std::string fragmentShaderFileName,
		std::unordered_map<std::string, Shader*> &shaders);

	/**
	@brief Constructs the LoadingScreen object.
	@param shaders A reference to the loaded Shader files
	*/
	LoadingScreen(std::unordered_map<std::string, Shader*> &shaders);

	/**
	@brief Destructs the LoadingScreen object.
	*/
	~LoadingScreen();

	/**
	@brief A function to update the LoadingScreen.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function to draw to the screen.
	*/
	void draw();

private:
	///The loading text
	UIObject * loadingText;
	///The loading image
	UIObject * loadingImage;
};