#include "MainApplication.h"

#include <stdlib.h>
#include <time.h>

int		takeRandCard(std::vector<Card *> *cards)
{
	return (rand() % cards->size());
}

void	MainApplication::initBoard()
{
	srand(time(NULL));
	std::vector<Card *>	cards;
	cards.assign(m_cards, m_cards + 52);
	int	i, j;
	int rand_card;
	for (i = 0; i < 7; i++)
	{
		rand_card = takeRandCard(&cards);
		cards.at(rand_card)->setVisible(true);
		m_piles[i].push_back(cards.at(rand_card));
		cards.erase(cards.begin() + rand_card);
		for (j = i + 1; j < 7; j++)
		{
			rand_card = takeRandCard(&cards);
			m_piles[j].push_back(cards.at(rand_card));
			cards.erase(cards.begin() + rand_card);
		}
	}
	while (cards.size() > 0)
	{
		if (cards.size() == 1)
			rand_card = 0;
		else
			rand_card = takeRandCard(&cards);
		m_stack.push_back(cards.at(rand_card));
		cards.erase(cards.begin() + rand_card);
	}
}

		MainApplication::MainApplication(sf::RenderWindow *window): m_window(window)
{
	int	type;
	int	number;
	for (type = 1; type < 5; type++)
		for (number = 1; number < 14; number++)
			m_cards[(type - 1) * 13 + number - 1] = new Card(type, number);
	initBoard();
}

MainApplication::~MainApplication(void)
{
	int	i;
	for (i = 0; i < 52; i++)
		delete m_cards[i];
}
