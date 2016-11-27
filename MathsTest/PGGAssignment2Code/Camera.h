//DISCLAMER - This is a modified version of code from one of my other assignments.

#pragma once

#include <SDL.h>
#include <iostream>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "GL/glew.h"

/**
@brief Creates a Camera object.
*/
class Camera
{
public:
	/**
	@brief Constructs a Camera object.
	*/
	Camera();

	/**
	@brief Destructs an Camera object.
	*/
	~Camera();
	
	/**
	@brief Moves the Camera using the translation.
	@param translation The translation.
	*/
	void moveCamera(glm::vec3 translation);

	/**
	@brief Moves the Camera along the X axis.
	@param translateX The translation along the X axis.
	*/
	void moveCameraAlongX(float translateX);

	/**
	@brief Moves the Camera along the Y axis.
	@param translateY The translation along the Y axis.
	*/
	void moveCameraAlongY(float translateY);

	/**
	@brief Moves the Camera along the Z axis.
	@param translateZ The translation along the Z axis.
	*/
	void moveCameraAlongZ(float translateZ);

	/**
	@brief Rotates the Camera using the rotation.
	@param rotation The rotation.
	*/
	void rotateCamera(glm::vec3 rotation);

	/**
	@brief Rotate the Camera along the X axis.
	@param rotationX The rotation along the X axis.
	*/
	void rotateCameraAlongX(float rotationX);

	/**
	@brief Rotate the Camera along the Y axis.
	@param rotationY The rotation along the Y axis.
	*/
	void rotateCameraAlongY(float rotationY);

	/**
	@brief Rotate the Camera along the Z axis.
	@param rotationZ The rotation along the Z axis.
	*/
	void rotateCameraAlongZ(float rotationZ);

	/**
	@brief Returns the Camera view matrix.
	@returns The Camera view matrix.
	*/
	glm::mat4 getView();

	/**
	@brief Returns the Camera projection matrix.
	@returns The Camera projection matrix.
	*/
	glm::mat4 getProjection();

	/**
	@brief Returns the Camera orientation.
	@returns The Camera orientation.
	*/
	glm::vec3 getOrientation();

	/**
	@brief Sets the position of the Camera.
	@param position The new position.
	*/
	void setPosition(glm::vec3 position);

private:
	///Create a viewing matrix for the Camera (Camera orientation)
	glm::mat4 view;
	///Construct a projection matrix for the Camera (Camera lense)
	glm::mat4 projection;
	///The Orientation of the Camera
	glm::vec3 orientation;
};