#ifndef MAINAPPLICATION_H_
# define MAINAPPLICATION_H_

# include <SFML/Graphics.hpp>

class MainApplication
{
public:
	MainApplication(void);
	~MainApplication(void);

public:
	sf::RenderWindow *m_window;
};

#endif /* !MAINAPPLICATION_H_