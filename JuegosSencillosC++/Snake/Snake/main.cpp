#include <iostream>
#include <conio.h>
#include<Windows.h>

const int WIDTH = 20;
const int HEIGTH = 20;

bool gameOver;
int headX, headY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum class eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = eDirection::STOP;
	headX = WIDTH / 2;
	headY = HEIGTH / 2;
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGTH;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < WIDTH; i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 0; i < HEIGTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0)
				std::cout << "#";

			if (i == headY && j == headX)
				std::cout << 'O';
			else if (i == fruitY && j == fruitX)
				std::cout << '%';
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						std::cout << "o";
						print = true;
					}
				}
				if (!print)
					std::cout << " ";
			}

			if (j == WIDTH - 1)
				std::cout << "#";
			
		}
		std::cout << std::endl; 
	}

	for (int i = 0; i < HEIGTH+2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;

	std::cout << "Score: " << score << std::endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = eDirection::LEFT;
			break;
		case 'd':
			dir = eDirection::RIGHT;
			break;
		case 'w':
			dir = eDirection::UP;
			break;
		case 's':
			dir = eDirection::DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = headX;
	tailY[0] = headY;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevX = prev2Y;
	}

	switch (dir)
	{
	case eDirection::LEFT:
		headX--;
		break;
	case eDirection::RIGHT:
		headX++;
		break;
	case eDirection::UP:
		headY--;
		break;
	case eDirection::DOWN:
		headY++;
		break;
	default:
		break;
	}

	//if(headX > WIDTH || headX < 0 || headY > HEIGTH || headY < 0)
		//sgameOver = true;

	if (headX >= WIDTH)
		headX = 0;
	else if (headX < 0)
		headX = WIDTH - 1;
	
	if (headY >= HEIGTH)
		headY = 0;
	else if (headY < 0)
		headY = HEIGTH - 1;

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == headX && tailY[i] == headY)
		{
			gameOver = true;
		}
	}

	if (headX == fruitX && headY == fruitY)
	{
		score += 10;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGTH;
		nTail++;
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10);
	}

	return 0;
}