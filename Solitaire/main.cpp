#include <SFML\Graphics.hpp>

using namespace sf;

int main()
{
	Window window(VideoMode(200, 200), "Solitaire");

	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == Event::Closed)
				window.close();
		}
	}
	return (0);
}