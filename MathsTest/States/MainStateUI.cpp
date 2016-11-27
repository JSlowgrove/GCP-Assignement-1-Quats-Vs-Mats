#include "MainStateUI.h"

MainStateUI::MainStateUI(std::unordered_map<std::string, Shader*> &shaders)
	: UI(shaders), axis('x'), rotations(10), method('m')
{
	//Initialise background

	SDL_Surface* image = IMG_Load("assets/img/background.png");
	if (!image)
	{
		Core::Logging::logI("Unable to load image from: img/background.png");

	}
	background = new UIObject(0.0f, 0.0f, 200.0f, 200.0f, image);

	//Initialise text

	TTF_Font* font = TTF_OpenFont("assets/font/isl_jupiter.ttf", 100);
	if (!font)
	{
		Core::Logging::logI("Unable to load ttf from: font/isl_jupiter.ttf");
		Core::Logging::logI("TTF error : " + std::string(TTF_GetError()));
	}
	SDL_Color fontColour = { 255, 255, 255 };
	SDL_Color selectedFontColour = { 0, 0, 255 };

	//info text
	SDL_Surface *text = TTF_RenderText_Blended(font, "Rotation axis:", fontColour);
	axisText = new UIObject(60.0f, 10.0f, 40.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Rotation method:", fontColour);
	rotationMethodText = new UIObject(10.0f, 10.0f, 40.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Number of rotations:", fontColour);
	numberOfRotationsText = new UIObject(115.0f, 10.0f, 75.0f, 10.0f, text);

	//button text
	text = TTF_RenderText_Blended(font, "Matrix", selectedFontColour);
	matrixText = new UIObject(10.0f, 20.0f, 40.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Quaternion", fontColour);
	quatText = new UIObject(10.0f, 35.0f, 40.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "X", selectedFontColour);
	xText = new UIObject(60.0f, 20.0f, 10.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Y", fontColour);
	yText = new UIObject(75.0f, 20.0f, 10.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Z", fontColour);
	zText = new UIObject(90.0f, 20.0f, 10.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "10", selectedFontColour);
	set10Text = new UIObject(115.0f, 20.0f, 15.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "100", fontColour);
	set100Text = new UIObject(130.0f, 20.0f, 15.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "1000", fontColour);
	set1000Text = new UIObject(145.0f, 20.0f, 15.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "10000", fontColour);
	set10000Text = new UIObject(160.0f, 20.0f, 15.0f, 10.0f, text);

	//performance text
	text = TTF_RenderText_Blended(font, "Time Taken: -ms", fontColour);
	timeText = new UIObject(60.0f, 35.0f, 40.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Memory Usage: -B", fontColour);
	memoryText = new UIObject(115.0f, 35.0f, 75.0f, 10.0f, text);

	//loading text
	text = TTF_RenderText_Blended(font, "LOADING...", fontColour);
	loadingText = new UIObject(50.0f, 90.0f, 100.0f, 20.0f, text);
	text = TTF_RenderText_Blended(font, "TESTING PERFORMANCE...", fontColour);
	performanceText = new UIObject(10.0f, 90.0f, 180.0f, 20.0f, text);

	//clean up
	TTF_CloseFont(font);
	font = NULL;
	SDL_FreeSurface(image);
	SDL_FreeSurface(text);
}

MainStateUI::~MainStateUI()
{
	/*delete pointers*/
	delete background;
	delete axisText;
	delete numberOfRotationsText;
	delete rotationMethodText;
	delete matrixText;
	delete quatText;
	delete xText;
	delete yText;
	delete zText;
	delete set10Text;
	delete set100Text;
	delete set1000Text;
	delete set10000Text;
	delete timeText;
	delete memoryText;
	delete loadingText;
	delete performanceText;
}

void MainStateUI::update(float dt)
{
}

void MainStateUI::updateTime(float time)
{
	//set floating point precision of the results
	std::stringstream stream;
	stream.precision(3);
	stream << std::fixed << time;
	std::string s = stream.str();

	//convert the time to text
	std::string textContent = "Time Taken: " + s + "ms";

	//initialise font and font colour
	TTF_Font* font = TTF_OpenFont("assets/font/isl_jupiter.ttf", 100);
	if (!font)
	{
		Core::Logging::logI("Unable to load ttf from: font/isl_jupiter.ttf");
		Core::Logging::logI("TTF error : " + std::string(TTF_GetError()));
	}
	//initialise a colour
	SDL_Color fontColour = { 255, 255, 255 };
	//create surface
	SDL_Surface *text = TTF_RenderText_Blended(font, textContent.c_str(), fontColour);
	//initialise the button UI text
	timeText = new UIObject(60.0f, 35.0f, 40.0f, 10.0f, text);
	//delete font
	TTF_CloseFont(font);
	font = NULL;

	//free the surfaces
	SDL_FreeSurface(text);
}

void MainStateUI::updateAxis(char axis)
{
	this->axis = axis;

	//initialise font and font colour
	TTF_Font* font = TTF_OpenFont("assets/font/isl_jupiter.ttf", 100);
	if (!font)
	{
		Core::Logging::logI("Unable to load ttf from: font/isl_jupiter.ttf");
		Core::Logging::logI("TTF error : " + std::string(TTF_GetError()));
	}
	SDL_Color xFontColour = { 255, 255, 255 };
	SDL_Color yFontColour = { 255, 255, 255 };
	SDL_Color zFontColour = { 255, 255, 255 };
	//initialise the colours
	switch (axis)
	{
	case 'x':
		xFontColour = { 0, 0, 255 };
		break;

	case 'y':
		yFontColour = { 0, 0, 255 };
		break;

	case 'z':
		zFontColour = { 0, 0, 255 };
		break;
	}

	//create text
	SDL_Surface *text = TTF_RenderText_Blended(font, "X", xFontColour);
	xText = new UIObject(60.0f, 20.0f, 10.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Y", yFontColour);
	yText = new UIObject(75.0f, 20.0f, 10.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Z", zFontColour);
	zText = new UIObject(90.0f, 20.0f, 10.0f, 10.0f, text);

	//delete font
	TTF_CloseFont(font);
	font = NULL;
	//free the surfaces
	SDL_FreeSurface(text);
}

void MainStateUI::updateMethod(char method)
{
	this->method = method;

	//initialise font and font colour
	TTF_Font* font = TTF_OpenFont("assets/font/isl_jupiter.ttf", 100);
	if (!font)
	{
		Core::Logging::logI("Unable to load ttf from: font/isl_jupiter.ttf");
		Core::Logging::logI("TTF error : " + std::string(TTF_GetError()));
	}
	SDL_Color mFontColour = { 255, 255, 255 };
	SDL_Color qFontColour = { 255, 255, 255 };
	//initialise the colours
	switch (method)
	{
	case 'm':
		mFontColour = { 0, 0, 255 };
		break;

	case 'q':
		qFontColour = { 0, 0, 255 };
		break;
	}

	SDL_Surface *text = TTF_RenderText_Blended(font, "Matrix", mFontColour);
	matrixText = new UIObject(10.0f, 20.0f, 40.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "Quaternion", qFontColour);
	quatText = new UIObject(10.0f, 35.0f, 40.0f, 10.0f, text);

	//delete font
	TTF_CloseFont(font);
	font = NULL;

	//free the surfaces
	SDL_FreeSurface(text);
}

void MainStateUI::updateNumberOfRotations(int rotations)
{
	this->rotations = rotations;

	//initialise font and font colour
	TTF_Font* font = TTF_OpenFont("assets/font/isl_jupiter.ttf", 100);
	if (!font)
	{
		Core::Logging::logI("Unable to load ttf from: font/isl_jupiter.ttf");
		Core::Logging::logI("TTF error : " + std::string(TTF_GetError()));
	}
	SDL_Color fontColour1 = { 255, 255, 255 };
	SDL_Color fontColour2 = { 255, 255, 255 };
	SDL_Color fontColour3 = { 255, 255, 255 };
	SDL_Color fontColour4 = { 255, 255, 255 };
	//initialise the colours
	switch (rotations)
	{
	case 10:
		fontColour1 = { 0, 0, 255 };
		break;

	case 100:
		fontColour2 = { 0, 0, 255 };
		break;

	case 1000:
		fontColour3 = { 0, 0, 255 };
		break;

	case 10000:
		fontColour4 = { 0, 0, 255 };
		break;
	}

	//create text
	SDL_Surface * text = TTF_RenderText_Blended(font, "10", fontColour1);
	set10Text = new UIObject(115.0f, 20.0f, 15.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "100", fontColour2);
	set100Text = new UIObject(135.0f, 20.0f, 15.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "1000", fontColour3);
	set1000Text = new UIObject(155.0f, 20.0f, 15.0f, 10.0f, text);
	text = TTF_RenderText_Blended(font, "10000", fontColour4);
	set10000Text = new UIObject(175.0f, 20.0f, 15.0f, 10.0f, text);

	//delete font
	TTF_CloseFont(font);
	font = NULL;
	//free the surfaces
	SDL_FreeSurface(text);
}

void MainStateUI::updateMemory(int memory)
{
	//set floating point precision of the results
	std::stringstream stream;
	stream << std::fixed << std::setprecision(3) << memory;
	std::string s = stream.str();

	//convert the time to text
	std::string textContent = "Memory Usage: " + s + "B";

	//initialise font and font colour
	TTF_Font* font = TTF_OpenFont("assets/font/isl_jupiter.ttf", 100);
	if (!font)
	{
		Core::Logging::logI("Unable to load ttf from: font/isl_jupiter.ttf");
		Core::Logging::logI("TTF error : " + std::string(TTF_GetError()));
	}
	//initialise a colour
	SDL_Color fontColour = { 255, 255, 255 };
	//create surface
	SDL_Surface *text = TTF_RenderText_Blended(font, textContent.c_str(), fontColour);
	//initialise the button UI text
	memoryText = new UIObject(115.0f, 35.0f, 75.0f, 10.0f, text);
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
	
	//draw the text
 	matrixText->draw(shader);
	quatText->draw(shader);
 	timeText->draw(shader);
	memoryText->draw(shader);
 	axisText->draw(shader);
 	numberOfRotationsText->draw(shader);
 	rotationMethodText->draw(shader);
	xText->draw(shader);
	yText->draw(shader);
	zText->draw(shader);
 	set10Text->draw(shader);
 	set100Text->draw(shader);
	set1000Text->draw(shader);
	set10000Text->draw(shader);

	//enable the depth test for the 3D next loop
	glEnable(GL_DEPTH_TEST);
}