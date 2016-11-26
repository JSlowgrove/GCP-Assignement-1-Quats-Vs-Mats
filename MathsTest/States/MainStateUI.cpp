#include "MainStateUI.h"

MainStateUI::MainStateUI(std::string vertexShaderFileName, std::string fragmentShaderFileName,
	std::unordered_map<std::string, Shader*> &shaders)
	: UI(vertexShaderFileName, fragmentShaderFileName, shaders)
{
	//initialise the UI objects
	matrixButton = new UIObject(25.0f, 10.0f, 50.0f, 20.0f);
	quatButton = new UIObject(75.0f, 10.0f, 50.0f, 20.0f);
}

MainStateUI::MainStateUI(std::unordered_map<std::string, Shader*> &shaders)
	: UI(shaders)
{
	//Loads the image as a surface
	SDL_Surface* image = IMG_Load("assets/img/background.png");
	if (!image)
	{
		Core::Logging::logI("Unable to load image from: img/background.png");

	}
	//initialise the title UI Object
	background = new UIObject(0.0f, 0.0f, 200.0f, 200.0f, image);

	/*Loads the image as a surface*/
	image = IMG_Load("assets/img/button.png");
	if (!image)
	{
		Core::Logging::logI("Unable to load image from: img/button.png");
	}
	//load in the button object
	matrixButton = new UIObject(20.0f, 10.0f, 75.0f, 20.0f, image);
	quatButton = new UIObject(100.0f, 10.0f, 75.0f, 20.0f, image);

	//initialise font and font colour
	TTF_Font* font = TTF_OpenFont("assets/font/Underdog_tt_hinted.ttf", 100);
	if (!font)
	{
		Core::Logging::logI("Unable to load ttf from: font/Underdog_tt_hinted.ttf");
		Core::Logging::logI("TTF error : " + std::string(TTF_GetError()));
	}
	//initialise a colour
	SDL_Color fontColour = { 255, 255, 255 };
	//create surface
	SDL_Surface *text = TTF_RenderText_Blended(font, "Matrix Rotate 90", fontColour);
	//initialise the button UI text
	matrixButtonText = new UIObject(20.0f, 10.0f, 75.0f, 20.0f, text);
	//create surface
	text = TTF_RenderText_Blended(font, "Quaternion Rotate 90", fontColour);
	//initialise the loading text
	quatButtonText = new UIObject(100.0f, 10.0f, 75.0f, 20.0f, text);
	//create surface
	text = TTF_RenderText_Blended(font, "-", fontColour);
	//initialise the loading text
	timeText = new UIObject(50.0f, 30.0f, 100.0f, 20.0f, text);
	//create surface
	text = TTF_RenderText_Blended(font, "LOADING...", fontColour);
	//initialise the loading text
	loadingText = new UIObject(50.0f, 90.0f, 100.0f, 20.0f, text);
	//delete font
	TTF_CloseFont(font);
	font = NULL;

	//free the surfaces
	SDL_FreeSurface(image);
	SDL_FreeSurface(text);
}

MainStateUI::~MainStateUI()
{
	/*delete pointer*/
	delete background;
	delete matrixButton;
	delete matrixButtonText;
	delete quatButton;
	delete quatButtonText;
	delete timeText;
}

void MainStateUI::update(float dt)
{
}

void MainStateUI::updateTime(float time)
{
	//set floating point precision of the results
	std::stringstream stream;
	stream << std::fixed << std::setprecision(3) << time;
	std::string s = stream.str();

	//convert the time to text
	std::string textContent = "Time Taken: " + s;

	//initialise font and font colour
	TTF_Font* font = TTF_OpenFont("assets/font/Underdog_tt_hinted.ttf", 100);
	if (!font)
	{
		Core::Logging::logI("Unable to load ttf from: font/Underdog_tt_hinted.ttf");
		Core::Logging::logI("TTF error : " + std::string(TTF_GetError()));
	}
	//initialise a colour
	SDL_Color fontColour = { 255, 255, 255 };
	//create surface
	SDL_Surface *text = TTF_RenderText_Blended(font, textContent.c_str(), fontColour);
	//initialise the button UI text
	timeText = new UIObject(50.0f, 30.0f, 100.0f, 20.0f, text);
	//delete font
	TTF_CloseFont(font);
	font = NULL;

	//free the surfaces
	SDL_FreeSurface(text);
}

void MainStateUI::draw()
{
	//disable the depth test to make the 2D appear on top of the 3D
	glDisable(GL_DEPTH_TEST);

	//draw the title
	background->draw(shader);

	//draw the buttons
	matrixButton->draw(shader);
	quatButton->draw(shader);

	//draw the text
	matrixButtonText->draw(shader);
	quatButtonText->draw(shader);
	timeText->draw(shader);

	//enable the depth test for the 3D next loop
	glEnable(GL_DEPTH_TEST);
}