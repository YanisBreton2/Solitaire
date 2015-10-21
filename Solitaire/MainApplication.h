#ifndef MAINAPPLICATION_H_
# define MAINAPPLICATION_H_

# include <SFML/Graphics.hpp>
# include <vector>

# include "Card.h"

class MainApplication
{
public:
	MainApplication(sf::RenderWindow *window);
	~MainApplication(void);
	void	initBoard(void);

public:
	sf::RenderWindow	*m_window;
	Card				*m_cards[52];
	std::vector<Card *>	m_stack; // Pioche
	std::vector<Card *>	m_piles[7]; // Les sept piles du bas
	std::vector<Card *>	m_ordered_piles[4]; // Les quatre piles du haut
};

#endif /* !MAINAPPLICATION_H_ */
