#pragma once

#include <iostream>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include <unordered_map>
#include "GL/glew.h"
#include "PGGAssignment2Code/Shader.h"
#include "PGGAssignment2Code/Object.h"
#include "Maths/Mat4.h"

/**
@brief A class that handles the sam objects.
*/
class Sam
{
public:
	/**
	@brief Creates a Sam Object using the shader file locations, the obj file location and OpenGL.
	@param objects A reference to the loaded Object files
	@param shaders A reference to the loaded Shader files
	*/
	Sam(std::unordered_map<std::string, Object*> &objects, std::unordered_map<std::string, Shader*> &shaders);

	/**
	@brief Destructs a Sam Object.
	*/
	~Sam();

	/**
	@brief Draw the Sam to the screen.
	@param viewMatrix A reference to the camera view matrix.
	@param projMatrix A reference to the camera projection matrix.
	@param matrix A reference to the objects matrix.
	*/
	void draw(Maths::Mat4 &viewMatrix, glm::mat4 &projMatrix, Maths::Mat4 matrix);

private:
	///The Shader for the Model
	Shader* shader;
	///The object for the Model
	Object* obj;
	///The material name
	std::string material;

	/**
	@brief Initialise the object for the Model.
	@param objFileName The name of the obj file.
	@param objects A reference to the loaded Object files
	*/
	void initialiseVAO(std::string objFileName, std::unordered_map<std::string, Object*> &objects);

	/**
	@brief Initialise the shaders.
	@param vertexShaderFileName The name of the vertex shader file.
	@param fragmentShaderFileName The name of the fragment shader file.
	@param shaders A reference to the loaded Shader files
	*/
	void initialiseShaders(std::string vertexShaderFileName, std::string fragmentShaderFileName,
		std::unordered_map<std::string, Shader*> &shaders);
};
