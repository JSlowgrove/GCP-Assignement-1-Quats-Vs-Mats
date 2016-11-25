#include "MainStateUI.h"

MainStateUI::MainStateUI(std::string vertexShaderFileName, std::string fragmentShaderFileName,
	std::unordered_map<std::string, Shader*> &shaders)
	: UI(vertexShaderFileName, fragmentShaderFileName, shaders)
{
	//initialise the UI objects
	background = new UIObject(0.0f, 0.0f, 720.0f, 567.0f);
	button = new UIObject(75.0f, 10.0f, 50.0f, 20.0f);
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
	button = new UIObject(75.0f, 10.0f, 50.0f, 20.0f, image);

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
	SDL_Surface *text = TTF_RenderText_Blended(font, "Button", fontColour);
	//initialise the button UI text
	buttonText = new UIObject(75.0f, 10.0f, 50.0f, 20.0f, text);
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
	delete button;
	delete buttonText;
}

void MainStateUI::update(float dt)
{
}

void MainStateUI::draw()
{
	//disable the depth test to make the 2D appear on top of the 3D
	glDisable(GL_DEPTH_TEST);

	//draw the title
	background->draw(shader);

	//draw the buttons
	button->draw(shader);

	//draw the text
	buttonText->draw(shader);

	//enable the depth test for the 3D next loop
	glEnable(GL_DEPTH_TEST);
}