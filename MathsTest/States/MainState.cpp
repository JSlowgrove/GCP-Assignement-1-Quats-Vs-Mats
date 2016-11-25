#include "MainState.h"

MainState::MainState(StateManager * stateManager, SDL_Window* window, int screenWidth, int screenHeight)
	: State(stateManager, window, screenWidth, screenHeight)
{
	//Initialise the Camera
	camera = new Camera();
	camera->moveCameraAlongZ(100.0f);

	//create the sam model
	sam = new Sam(objects, shaders);

	//initialise the matrix's
	for (int i = 0; i < 9; i++)
	{
		matrix[i].setAsIdentityMatrix();
	}

	//initialise the mouse
	mouse = Maths::Vec2(0.0f, 0.0f);
	
	//tmp for testing
	angleUpdate = 0.0f;
	matrix[1].translate(matrix[1], Maths::Vec3(30.0f, 0.0f, 0.0f));
	matrix[2].translate(matrix[2], Maths::Vec3(-30.0f, 0.0f, 0.0f));
	matrix[3].translate(matrix[3], Maths::Vec3(30.0f, 35.0f, 0.0f));
	matrix[4].translate(matrix[4], Maths::Vec3(-30.0f, 35.0f, 0.0f));
	matrix[5].translate(matrix[5], Maths::Vec3(30.0f, -35.0f, 0.0f));
	matrix[6].translate(matrix[6], Maths::Vec3(-30.0f, -35.0f, 0.0f));
	matrix[7].translate(matrix[7], Maths::Vec3(0.0f, 35.0f, 0.0f));
	matrix[8].translate(matrix[8], Maths::Vec3(0.0f, -35.0f, 0.0f));
}

MainState::~MainState()
{
	//delete pointers
	delete sam;
	delete camera;
	for (auto i = objects.begin(); i != objects.end(); ++i)
	{
		delete i->second;
	}
	for (auto i = shaders.begin(); i != shaders.end(); ++i)
	{
		delete i->second;
	}
}

bool MainState::input()
{
	//Check for user input
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		//get the mouse input
		mouse.x = ((float)incomingEvent.motion.x);
		mouse.y = ((float)incomingEvent.motion.y);
		
		switch (incomingEvent.type)
		{
		case SDL_QUIT: //If user closes the window, end the game loop

			return false;
			break;

		case SDL_KEYDOWN:

			switch (incomingEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE: //If Escape is pressed, end the game loop

				return false;
				break;

			case SDLK_UP:
				//matrix.rotateAlongY(matrix, 180.0f, Maths::angleType::degree);
				break;

			case SDLK_DOWN:
				//matrix.rotateAlongY(matrix, 0.0f, Maths::angleType::degree);
				break;

			case SDLK_LEFT:
				//matrix.rotateAlongY(matrix, 90.0f, Maths::angleType::degree);
				break;

			case SDLK_RIGHT:
				//matrix.rotateAlongY(matrix, 270.0f, Maths::angleType::degree);
				break;
			}

		case SDL_MOUSEBUTTONDOWN: //If the mouse is pressed
			//if the left mouse button
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{
			}
			break;

		case SDL_MOUSEBUTTONUP://If the mouse is released
			//if the left mouse button
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{
			}
			break;
		}
	}
	return true;
}

void MainState::update(float dt)
{
	//tmp for testing
 	angleUpdate = (20.0f * dt);
	matrix[0].rotateAlongY(matrix[0], angleUpdate, Maths::angleType::degree);
	matrix[1].rotateAlongY(matrix[1], -angleUpdate, Maths::angleType::degree);
	matrix[2].rotateAlongY(matrix[2], -angleUpdate, Maths::angleType::degree);
	matrix[3].rotateAlongY(matrix[3], angleUpdate, Maths::angleType::degree);
	matrix[4].rotateAlongY(matrix[4], angleUpdate, Maths::angleType::degree);
	matrix[5].rotateAlongY(matrix[5], angleUpdate, Maths::angleType::degree);
	matrix[6].rotateAlongY(matrix[6], angleUpdate, Maths::angleType::degree);
	matrix[7].rotateAlongY(matrix[7], -angleUpdate, Maths::angleType::degree);
	matrix[8].rotateAlongY(matrix[8], -angleUpdate, Maths::angleType::degree);
}

void MainState::draw()
{
	//Draw sam using the camera and each matrix
	for (int i = 0; i < 9; i++)
	{
		sam->draw(camera->getView(), camera->getProjection(), matrix[i]);
	}
}