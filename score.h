#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Check player score
int Score(int my_score, char mod)
{
	int rank = 0;
	string line;
	ifstream myfile_in("score.txt");

	int first = 0, second = 0, third;

	// Read scores
	getline(myfile_in, line); // First line
	if (my_score >= stoi(line))
	{
		first = my_score;
		rank = 1;
		second = stoi(line);
		getline(myfile_in, line);
		third = stoi(line);
	}
	else
	{
		first = stoi(line);
		getline(myfile_in, line);
		if (my_score >= stoi(line)) // Second line
		{
			second = my_score;
			rank = 2;
			third = stoi(line);
		}
		else
		{
			second = stoi(line);
			getline(myfile_in, line);
			if (my_score >= stoi(line)) // Third line
			{
				third = my_score;
				rank = 3;
			}
			else
			{
				third = stoi(line);
			}
		}
	}

	// Save ?
	if (mod == 's')
	{
		// Write scores
		ofstream myfile_out("score.txt");
		myfile_out << first << endl;
		myfile_out << second << endl;
		myfile_out << third;
	}

	return rank;
}

// Show nth rank score
string Show_Scores(int r)
{
	string line;
	ifstream myfile_in("score.txt");

	for (int i = 0; i < r; i++)
	{
		getline(myfile_in, line); // Read line
	}
	return line;
}
