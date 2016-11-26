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
	
	//initialise the matrixs
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		matrix.push_back(Maths::Mat4());
		matrix[i].setAsIdentityMatrix();
		matrix[i].scale(matrix[i], 0.04f);
		matrix[i].translate(matrix[i], Maths::Vec3(((float)(i) - 4.5f) * 25.0f, 0.0f, 0.0f));
	}

	//initialise the quaternions
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		quats.push_back(Maths::Quaternion());
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

		int tmp = 0;

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

			case SDLK_SPACE:
				//performanceScreen();
				switch (userInterface->getMethod())
				{
				case 'm':
					tester->testStart();
					for (int i = 0; i < userInterface->getRotations(); i++)
					{
						switch (userInterface->getAxis())
						{
						case 'x':
							matrix[i].rotateAlongX(matrix[i], 90.0f, Maths::angleType::degree);
							break;

						case 'y':
							matrix[i].rotateAlongY(matrix[i], 90.0f, Maths::angleType::degree);
							break;

						case 'z':
							matrix[i].rotateAlongZ(matrix[i], 90.0f, Maths::angleType::degree);
							break;
						}
					}
					userInterface->updateTime(tester->testFinish() * 0.001f);
					break;

				case 'q':
					tester->testStart();
					for (int i = 0; i < userInterface->getRotations(); i++)
					{
						switch (userInterface->getAxis())
						{
						case 'x':
							quats[i].rotate(quats[i], Maths::Vec3(1.0f, 0.0f, 0.0f), 90.0f, Maths::angleType::degree);
							break;

						case 'y':
							quats[i].rotate(quats[i], Maths::Vec3(0.0f, 1.0f, 0.0f), 90.0f, Maths::angleType::degree);
							break;

						case 'z':
							quats[i].rotate(quats[i], Maths::Vec3(0.0f, 0.0f, 1.0f), 90.0f, Maths::angleType::degree);
							break;
						}
					}
					userInterface->updateTime(tester->testFinish() * 0.001f);
					for (int i = 0; i < userInterface->getRotations(); i++)
					{
						matrix[i] = matrix[i] * quats[i].getMatrix();
					}
					break;
				}
				//loadingScreen();
				break;

			case SDLK_x:
				userInterface->updateAxis('x');
				break;

			case SDLK_y:
				userInterface->updateAxis('y');
				break;

			case SDLK_z:
				userInterface->updateAxis('z');
				break;

			case SDLK_m:
				userInterface->updateMethod('m');
				break;

			case SDLK_q:
				userInterface->updateMethod('q');
				break;

			case SDLK_1:
				userInterface->updateNumberOfRotations(10);
				loadingScreen();
				matrix.clear();
				quats.clear();
				for (int i = 0; i < userInterface->getRotations(); i++)
				{
					matrix.push_back(Maths::Mat4());
					matrix[i].setAsIdentityMatrix();
					matrix[i].scale(matrix[i], 0.04f);
					matrix[i].translate(matrix[i], Maths::Vec3(((float)(i)-4.5f) * 25.0f, 0.0f, 0.0f));
				}
				for (int i = 0; i < userInterface->getRotations(); i++)
				{
					quats.push_back(Maths::Quaternion());
				}
				break;

			case SDLK_2:
				userInterface->updateNumberOfRotations(100);
				loadingScreen();
				matrix.clear();
				quats.clear();
				for (int y = 0; y < 10; y++)
				{
					for (int x = 0; x < 10; x++)
					{
						matrix.push_back(Maths::Mat4());
						matrix[matrix.size()-1].setAsIdentityMatrix();
						matrix[matrix.size()-1].scale(matrix[matrix.size()-1], 0.03f);
						matrix[matrix.size()-1].translate(
							matrix[matrix.size()-1], 
							Maths::Vec3((x - 4.5f) * 25.0f, (y - 6.5f) * 25.0f, 0.0f)
							);
					}
				}
				for (int i = 0; i < userInterface->getRotations(); i++)
				{
					quats.push_back(Maths::Quaternion());
				}
				break;

			case SDLK_3:
				userInterface->updateNumberOfRotations(1000);
				loadingScreen();
				matrix.clear();
				quats.clear();
				for (int y = 0; y < 10; y++)
				{
					for (int x = 0; x < 10; x++)
					{
						for (int z = 0; z < 10; z++)
						{
							matrix.push_back(Maths::Mat4());
							matrix[matrix.size() - 1].setAsIdentityMatrix();
							matrix[matrix.size() - 1].scale(matrix[matrix.size() - 1], 0.03f);
							matrix[matrix.size() - 1].translate(
								matrix[matrix.size() - 1],
								Maths::Vec3((x - 4.5f) * 25.0f, (y - 6.5f) * 25.0f, z * 25.0f)
							);
						}
					}
				}
				for (int i = 0; i < userInterface->getRotations(); i++)
				{
					quats.push_back(Maths::Quaternion());
				}
				break;
			}
		}
	}
	return true;
}

void MainState::update(float dt)
{
	/*angleUpdate = (20.0f * dt);
	Maths::Quaternion t;
	t.rotate(t, Maths::Vec3(0.0f, 1.0f, 0.0f), angleUpdate, Maths::angleType::degree);
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		matrix[i] = matrix[i] * t.getMatrix();
	}*/
}

void MainState::draw()
{
	//Draw sam using the camera and each matrix
	for (int i = 0; i < userInterface->getRotations(); i++)
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

void MainState::performanceScreen()
{
	//clear the frame-buffer to a colour
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//write colour to the frame-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draw the loading screen
	userInterface->drawPerformance();

	//display the window
	SDL_GL_SwapWindow(window);
}