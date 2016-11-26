#include "MainState.h"

MainState::MainState(StateManager * stateManager, SDL_Window* window, int screenWidth, int screenHeight)
	: State(stateManager, window, screenWidth, screenHeight)
{
	//initialise the UI
	userInterface = new MainStateUI(shaders);

	//Display the loading screen
	loadingScreen();

	//Initialise the Camera
	camera = new Camera();
	camera->moveCameraAlongZ(10.0f);

	//create the sam model
	sam = new Sam(objects, shaders);

	//if number to display is 1000 the scale = 0.01f

	//initialise the matrix's
	for (int i = 0; i < 10; i++)
	{
		matrix[i].setAsIdentityMatrix();
		matrix[i].scale(matrix[i], 0.04f);
		matrix[i].translate(matrix[i], Maths::Vec3(((float)(i) - 4.5f) * 25.0f, 0.0f, 0.0f));
	}

	//initialise the mouse
	mouse = Maths::Vec2(0.0f, 0.0f);
	
	//initialise the performance tester
	tester = new Core::PerformanceTest();

	//tmp for testing
	angleUpdate = 0.0f;
}

MainState::~MainState()
{
	//delete pointers
	delete sam;
	delete camera;
	delete userInterface;
	delete tester;
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
				tester->testStart();
				for (int i = 0; i < 10; i++)
				{
					matrix[i].rotateAlongY(matrix[i], 180.0f, Maths::angleType::degree);
				}
				userInterface->updateTime(tester->testFinish() * 0.001f);
				break;

			case SDLK_LEFT:
				for (int i = 0; i < 10; i++)
				{
					matrix[i].rotateAlongY(matrix[i], -90.0f, Maths::angleType::degree);
				}
				break;

			case SDLK_RIGHT:
				for (int i = 0; i < 10; i++)
				{
					matrix[i].rotateAlongY(matrix[i], 90.0f, Maths::angleType::degree);
				}
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
//  angleUpdate = (20.0f * dt);
// 	matrix[0].rotateAlongY(matrix[0], angleUpdate, Maths::angleType::degree);
// 	matrix[1].rotateAlongY(matrix[1], -angleUpdate, Maths::angleType::degree);
// 	matrix[2].rotateAlongY(matrix[2], -angleUpdate, Maths::angleType::degree);
// 	matrix[3].rotateAlongY(matrix[3], angleUpdate, Maths::angleType::degree);
// 	matrix[4].rotateAlongY(matrix[4], angleUpdate, Maths::angleType::degree);
// 	matrix[5].rotateAlongY(matrix[5], angleUpdate, Maths::angleType::degree);
// 	matrix[6].rotateAlongY(matrix[6], angleUpdate, Maths::angleType::degree);
// 	matrix[7].rotateAlongY(matrix[7], -angleUpdate, Maths::angleType::degree);
// 	matrix[8].rotateAlongY(matrix[8], -angleUpdate, Maths::angleType::degree);
}

void MainState::draw()
{
	//Draw sam using the camera and each matrix
	for (int i = 0; i < 10; i++)
	{
		sam->draw(camera->getView(), camera->getProjection(), matrix[i]);
	}

	//draw the UI
	userInterface->draw();
}

void MainState::loadingScreen()
{
	//clear the frame-buffer to a colour
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//write colour to the frame-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draw the loading screen
	userInterface->drawLoading();

	//display the window
	SDL_GL_SwapWindow(window);
}