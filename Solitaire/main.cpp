#include <SFML\Graphics.hpp>

#include "MainApplication.h"

#define PLAY (0)
#define EXIT (1)

using namespace sf;

int displayMenu(RenderWindow *window)
{
	Texture play_button_texture;
	Texture exit_button_texture;
	if (!play_button_texture.loadFromFile("../Ressource/menu/play_button.png"))
		exit(1);
	if (!exit_button_texture.loadFromFile("../Ressource/menu/exit_button.png"))
		exit(1);
	Sprite play_button_sprite;
	Sprite exit_button_sprite;
	play_button_sprite.setTexture(play_button_texture);
	play_button_sprite.setPosition(500, 200);
	exit_button_sprite.setTexture(exit_button_texture);
	exit_button_sprite.setPosition(500, 400);
	window->clear(Color::White);
	window->draw(play_button_sprite);
	window->draw(exit_button_sprite);
	window->display();
	while (window->isOpen())
	{
		Event evt;
		while (window->pollEvent(evt))
		{
			if (evt.type == Event::Closed)
				window->close();
			else if(evt.type == Event::MouseButtonReleased && evt.mouseButton.button == Mouse::Left)
			{
				int x = evt.mouseButton.x;
				int y = evt.mouseButton.y;
				if (x > play_button_sprite.getPosition().x && x < play_button_sprite.getPosition().x + 377 &&
					y > play_button_sprite.getPosition().y && y < play_button_sprite.getPosition().y + 133)
					return (PLAY);
				if (x > exit_button_sprite.getPosition().x && x < exit_button_sprite.getPosition().x + 377 &&
					y > exit_button_sprite.getPosition().y && y < exit_button_sprite.getPosition().y + 133)
					return (EXIT);
			}

		}
	}
	return (EXIT);
}

int play(RenderWindow *window)
{
	MainApplication app(window);
	app.launch();
	return (0);
}

int main()
{
	RenderWindow window(VideoMode(1400, 800), "Solitaire");
	while (window.isOpen())
	{
		int choice = displayMenu(&window);
		if (choice == PLAY)
			play(&window);
		else if (choice == EXIT)
			window.close();
	}
	return (0);
}