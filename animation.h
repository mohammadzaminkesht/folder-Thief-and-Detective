#include <iostream>
#include <Windows.h>

void Moveto(char character, int first_x, int first_y, int fin_x, int fin_y, int steps, int speed)
{
	int y = first_y;
	int direction;

	// Set direction for y
	if ((fin_y - first_y) > 0)
		direction = steps;
	else
		direction = -steps;

	// Check and set y
	while (first_y != fin_y)
	{
		// Sleep for a few seconds
		Sleep(speed);
		// Remove character from previous position
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { first_x, first_y });
		std::cout << " ";
		// Set character to new position
		first_y += direction;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { first_x, first_y });
		std::cout << character;
	}

	// Set direction for x
	if ((fin_x - first_x) > 0)
		direction = steps;
	else
		direction = -steps;

	// Check and set x
	while (first_x != fin_x)
	{
		// Sleep for a few seconds
		Sleep(speed);
		// Remove character from previous position
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { first_x, first_y });
		std::cout << " ";
		// Set character to new position
		first_x += direction;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { first_x, first_y });
		std::cout << character;
	}
}
