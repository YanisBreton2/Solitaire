#include "MainApplication.h"

#include <stdlib.h>
#include <time.h>

int		takeRandCard(std::vector<Card *> *cards)
{
	return (rand() % cards->size());
}

void	MainApplication::initBoard()
{
	srand((unsigned int)time(NULL));
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

void	MainApplication::initPosition()
{
	unsigned int	i, j;

	for (i = 0; i < m_stack.size(); i++)
		m_stack.at(i)->setPosition(STACK_POSITION_X, STACK_POSITION_Y);
	for (i = 0; i < 7; i++)
		for (j = 0; j < m_piles[i].size(); j++)
			m_piles[i].at(j)->setPosition(PILE_FIRST_POSITION_X + (float)i * PILE_DELTA_X, PILE_POSITION_Y + (float)j * PILE_DELTA_Y);
}

		MainApplication::MainApplication(sf::RenderWindow *window): m_window(window)
{
	unsigned int	type;
	unsigned int	number;
	for (type = 1; type < 5; type++)
		for (number = 1; number < 14; number++)
			m_cards[(type - 1) * 13 + number - 1] = new Card(type, number);
	initBoard();
	initPosition();
}

MainApplication::~MainApplication(void)
{
	int	i;
	for (i = 0; i < 52; i++)
		delete m_cards[i];
}

void	MainApplication::drawBoard()
{
	if (m_stack.size() > 0)
		m_window->draw(m_stack.at(0)->getSprite());
	unsigned int i, j;
	for (i = 0; i < 7; i++)
		for (j = 0; j < m_piles[i].size(); j++)
			m_window->draw(m_piles[i].at(j)->getSprite());
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
		drawBoard();
		m_window->display();
	}
	exit(0);
}
