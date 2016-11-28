#include "Sam.h"

Sam::Sam(std::unordered_map<std::string, Object*> &objects, std::unordered_map<std::string, Shader*> &shaders)
	: material("sam.png")
{
	//initialise the shader
	initialiseShaders("texture", "texture", shaders);
	//initialise the object
	initialiseVAO("sam", objects);
}

Sam::~Sam()
{
}

void Sam::initialiseVAO(std::string objFileName, std::unordered_map<std::string, Object*> &objects)
{
	/*test if the model is textured*/
	if (material != "Untextured")
	{
		/*test if the object has already been loaded*/
		if (objects.count(objFileName + "/" + material) == 0)
		{
			/*load the object*/
			objects[objFileName + "/" + material] = new Object(objFileName, material);
		}
		else
		{
			/*print out that it is already loaded*/
			Core::Logging::logE(objFileName + "/" + material + " object already loaded.");
		}
		/*update the objectName*/
		objFileName = objFileName + "/" + material;
	}
	else
	{
		/*test if the object has already been loaded*/
		if (objects.count(objFileName) == 0)
		{
			/*load the object*/
			objects[objFileName] = new Object(objFileName);
		}
		else
		{
			/*print out that it is already loaded*/
			Core::Logging::logE(objFileName + " object already loaded.");
		}
	}
	/*initialise the object*/
	obj = objects[objFileName];
}

void Sam::initialiseShaders(std::string vertexShaderFileName, std::string fragmentShaderFileName,
	std::unordered_map<std::string, Shader*> &shaders)
{
	/*a string for the name of the linked shader*/
	std::string linkedShaderName = vertexShaderFileName + "/" + fragmentShaderFileName;

	/*test if the shader has already been loaded*/
	if (shaders.count(linkedShaderName) == 0)
	{
		/*load the shader*/
		shaders[linkedShaderName] = new Shader(vertexShaderFileName, fragmentShaderFileName);
	}
	else
	{
		/*print out that it is already loaded*/
		Core::Logging::logE(linkedShaderName + " shader already loaded.");
	}
	/*initialise the object*/
	shader = shaders[linkedShaderName];
}

void Sam::draw(Maths::Mat4 &viewMatrix, glm::mat4 &projMatrix, Maths::Mat4 matrix)
{
	/*Activate the shader program*/
	glUseProgram(shader->getShaderProgram());

	/*Activate the vertex array object*/
	glBindVertexArray(obj->getVAO());

	/*Send the matrices to the shader as uniforms locations*/
	glUniformMatrix4fv(shader->getModelMatrixLocation(), 1, GL_TRUE, matrix.getMatrixArray());
	glUniformMatrix4fv(shader->getViewMatrixLocation(), 1, GL_TRUE, viewMatrix.getMatrixArray());
	glUniformMatrix4fv(shader->getShaderProjectionMatrixLocation(), 1, GL_FALSE, glm::value_ptr(projMatrix));

	/*if the model uses a shader*/
	if (material != "Untextured")
	{
		/*texturing*/
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, obj->getTextureID());
		glUniform1i(shader->getTextureSamplerLocation(), 0);
	}

	/*Draw the model to the screen, using the type of geometry and the number of vertices's*/
	glDrawArrays(GL_TRIANGLES, 0, obj->getNumberOfVertices());

	/*Unbind the vertex array object*/
	glBindVertexArray(0);

	/*disable the shader program*/
	glUseProgram(0);
}