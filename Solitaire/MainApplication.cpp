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
		cards.at(rand_card)->hide(false);
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
		{
			m_cards[(type - 1) * 13 + number - 1] = new Card(type, number);
			m_cards[(type - 1) * 13 + number - 1]->setPosition(80.0f * number, 150.0f * type);
		}
	initBoard();
}

MainApplication::~MainApplication(void)
{
	int	i;
	for (i = 0; i < 52; i++)
		delete m_cards[i];
}

void	MainApplication::launch()
{
	while (m_window->isOpen())
	{
		sf::Event evt;
		
		while (m_window->pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed)
				m_window->close();
		}
		m_window->clear(sf::Color(33, 116, 64));
		for (int i=0; i < 52; i++)
			m_window->draw(m_cards[i]->getSprite()); // Temporaire
		m_window->display();
	}
	exit(0);
}
