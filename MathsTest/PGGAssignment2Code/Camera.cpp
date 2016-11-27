//DISCLAMER - This is a modified version of code from one of my other assignments.

#include "Camera.h"

Camera::Camera()
{
	//initialise the projection matrix for the camera (camera lense)
	projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 200.0f);
	//initialise the view matrix for the camera
	view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	//initialise the orientation
	orientation = glm::vec3(0.0f, 0.0f, 0.0f);
}

Camera::~Camera()
{
}

void Camera::moveCamera(glm::vec3 translation)
{
	/*Create a viewing matrix for the camera 'Camera orientation'.
	The translation is inverted to work with OpenGL*/
	view = glm::translate(view, -translation);
}

void Camera::moveCameraAlongX(float translateX)
{
	/*Create a viewing matrix for the camera 'Camera orientation'.
	The translation is inverted to work with OpenGL*/
	view = glm::translate(view, glm::vec3(-translateX, 0.0f, 0.0f));
}

void Camera::moveCameraAlongY(float translateY)
{
	/*Create a viewing matrix for the camera 'Camera orientation'.
	The translation is inverted to work with OpenGL*/
	view = glm::translate(view, glm::vec3(0.0f, -translateY, 0.0f));
}

void Camera::moveCameraAlongZ(float translateZ)
{
	/*Create a viewing matrix for the camera 'Camera orientation'.
	The translation is inverted to work with OpenGL*/
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -translateZ));
}

void Camera::rotateCamera(glm::vec3 rotation)
{
	//Rotates the Camera
	view = glm::rotate(view, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::rotate(view, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	//update the stored orientation
	orientation = rotation;
}

void Camera::rotateCameraAlongX(float rotationX)
{
	//Rotates the Camera along the X axis
	view = glm::rotate(view, rotationX, glm::vec3(1.0f, 0.0f, 0.0f));
	//update the stored orientation
	orientation.x = rotationX;
}

void Camera::rotateCameraAlongY(float rotationY)
{
	//Rotates the Camera along the Y axis
	view = glm::rotate(view, rotationY, glm::vec3(0.0f, 1.0f, 0.0f));
	//update the stored orientation
	orientation.y = rotationY;
}

void Camera::rotateCameraAlongZ(float rotationZ)
{
	//Rotates the Camera along the Z axis
	view = glm::rotate(view, rotationZ, glm::vec3(0.0f, 0.0f, 1.0f));
	//update the stored orientation
	orientation.z = rotationZ;
}

glm::mat4 Camera::getView()
{
	//return the Camera view matrix
	return view;
}

glm::mat4 Camera::getProjection()
{
	//return the Camera projection matrix
	return projection;
}

glm::vec3 Camera::getOrientation()
{
	//return the Camera orientation
	return orientation;
}

void Camera::setPosition(glm::vec3 position)
{
	//set the position
	view = glm::translate(glm::mat4(1.0f), position);
}