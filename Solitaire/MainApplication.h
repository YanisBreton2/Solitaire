#ifndef MAINAPPLICATION_H_
# define MAINAPPLICATION_H_

# include <SFML/Graphics.hpp>
# include <vector>

# include "Card.h"

# define BACKGROUND_RED			(20)
# define BACKGROUND_GREEN		(116)
# define BACKGROUND_BLUE		(20)

# define PILE_FIRST_POSITION_X	((float)50)
# define PILE_POSITION_Y		((float)220)
# define PILE_DELTA_X			((float)200)
# define PILE_DELTA_Y			((float)18)

# define STACK_POSITION_X		((float)50)
# define STACK_POSITION_Y		((float)50)

class MainApplication
{
public:
	MainApplication(sf::RenderWindow *window);
	~MainApplication(void);
	void	initBoard(void);
	void	initPosition(void);
	void	launch(void);
	void	drawBoard(void);
	void	eventHandler(sf::Event &event);

public:
	sf::RenderWindow	*m_window;
	Card				*m_cards[52];
	std::vector<Card *>	m_stack; // Pioche
	std::vector<Card *>	m_piles[7]; // Les sept piles du bas
	std::vector<Card *>	m_ordered_piles[4]; // Les quatre piles du haut
	Card				*m_card_moving;
};

#endif /* !MAINAPPLICATION_H_ */
