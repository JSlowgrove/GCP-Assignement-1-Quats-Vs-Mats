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
	
	//initialise the matrixs and quats
	init10MatQuats();

	//initialise the quaternions
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		quats.push_back(Maths::Quaternion());
	}

	//initialise the mouse
	mouse = Maths::Vec2(0.0f, 0.0f);
	
	//initialise the performance tester
	tester = new Core::PerformanceTest();
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
				performanceTest();
				memoryTest();
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
				init10MatQuats();
				break;

			case SDLK_2:
				init100MatQuats();
				break;

			case SDLK_3:
				init1000MatQuats();
				break;

			case SDLK_4:
				init10000MatQuats();
				break;
			}
		}
	}
	return true;
}

void MainState::update(float dt)
{
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

void MainState::init10MatQuats()
{
	userInterface->updateNumberOfRotations(10);
	loadingScreen();
	matrix.clear();
	matrix.shrink_to_fit();
	quats.clear();
	quats.shrink_to_fit();
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
}

void MainState::init100MatQuats()
{
	userInterface->updateNumberOfRotations(100);
	loadingScreen();
	matrix.clear();
	matrix.shrink_to_fit();
	quats.clear();
	quats.shrink_to_fit();
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			matrix.push_back(Maths::Mat4());
			matrix[matrix.size() - 1].setAsIdentityMatrix();
			matrix[matrix.size() - 1].scale(matrix[matrix.size() - 1], 0.03f);
			matrix[matrix.size() - 1].translate(
				matrix[matrix.size() - 1],
				Maths::Vec3((x - 4.5f) * 25.0f, (y - 6.5f) * 25.0f, 0.0f)
			);
		}
	}
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		quats.push_back(Maths::Quaternion());
	}
}

void MainState::init1000MatQuats()
{
	userInterface->updateNumberOfRotations(1000);
	loadingScreen();
	matrix.clear();
	matrix.shrink_to_fit();
	quats.clear();
	quats.shrink_to_fit();
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
}

void MainState::init10000MatQuats()
{
	userInterface->updateNumberOfRotations(10000);
	loadingScreen();
	matrix.clear();
	matrix.shrink_to_fit();
	quats.clear();
	quats.shrink_to_fit();
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			for (int z = 0; z < 100; z++)
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
}

void MainState::performanceTest()
{
	switch (userInterface->getMethod())
	{
	case 'm':
		switch (userInterface->getAxis())
		{
		case 'x':
			xAxisMatRotationTest();
			break;

		case 'y':
			yAxisMatRotationTest();
			break;

		case 'z':
			zAxisMatRotationTest();
			break;
		}
		break;

	case 'q':
		switch (userInterface->getAxis())
		{
		case 'x':
			xAxisQuatRotationTest();
			break;

		case 'y':
			yAxisQuatRotationTest();
			break;

		case 'z':
			zAxisQuatRotationTest();
			break;
		}
		for (int i = 0; i < userInterface->getRotations(); i++)
		{
			matrix[i] = matrix[i] * quats[i].getMatrix();
		}
		break;
	}
}

void MainState::memoryTest()
{
	int numberOfBytes = 0;
	switch (userInterface->getMethod())
	{
	case 'm':
		numberOfBytes = sizeof(matrix[0]) * userInterface->getRotations();
		break;

	case 'q':
		numberOfBytes = sizeof(quats[0]) * userInterface->getRotations();
		break;
	}
	userInterface->updateMemory(numberOfBytes);
}

void MainState::xAxisMatRotationTest()
{
	float angle = Maths::Convert::convertDegreeToRadian(90.0f);

	tester->testStart();
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		matrix[i].rotateAlongX(matrix[i], angle);
	}
	userInterface->updateTime(tester->testFinish() * 0.001f);
}

void MainState::yAxisMatRotationTest()
{
	float angle = Maths::Convert::convertDegreeToRadian(90.0f);

	tester->testStart();
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		matrix[i].rotateAlongY(matrix[i], angle);
	}
	userInterface->updateTime(tester->testFinish() * 0.001f);
}

void MainState::zAxisMatRotationTest()
{
	float angle = Maths::Convert::convertDegreeToRadian(90.0f);

	tester->testStart();
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		matrix[i].rotateAlongZ(matrix[i], angle);
	}
	userInterface->updateTime(tester->testFinish() * 0.001f);
}

void MainState::xAxisQuatRotationTest()
{
	float angle = Maths::Convert::convertDegreeToRadian(90.0f);

	tester->testStart();
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		quats[i].rotate(quats[i], Maths::Vec3(1.0f, 0.0f, 0.0f), angle);
	}
	userInterface->updateTime(tester->testFinish() * 0.001f);
}


void MainState::yAxisQuatRotationTest()
{
	float angle = Maths::Convert::convertDegreeToRadian(90.0f);

	tester->testStart();
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		quats[i].rotate(quats[i], Maths::Vec3(0.0f, 1.0f, 0.0f), angle);
	}
	userInterface->updateTime(tester->testFinish() * 0.001f);
}

void MainState::zAxisQuatRotationTest()
{
	float angle = Maths::Convert::convertDegreeToRadian(90.0f);

	tester->testStart();
	for (int i = 0; i < userInterface->getRotations(); i++)
	{
		quats[i].rotate(quats[i], Maths::Vec3(0.0f, 0.0f, 1.0f), angle);
	}
	userInterface->updateTime(tester->testFinish() * 0.001f);
}
