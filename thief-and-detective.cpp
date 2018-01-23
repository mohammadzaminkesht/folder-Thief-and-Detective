#include <iostream>	
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <math.h>
#include "Animation.h"
#include "Score.h"
using namespace std;

void Swap(int&, int&);
void loading();
void gotoxy(int, int);
void start();
void color(int);
void w_size(int, int);
void home(int, int, int, char);
void border(int, int, int, int);
void border2(int, int);
void graphic();
void s_rand();
void change(int);
void Thief(int, char);
void Neighbor();
void detective();
void eye();

// variables
int h_x, h_y, x_T, y_T, x_t, y_t, x_D, y_D, home_T, home_t, home_D;
int e_T = 0;
int S_T, S_t;
int po[5];
int Dc;
int ehtemal = 0;
int balapayin;
int eye_enable = 0;

void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void loading()
{
	system("cls");
	color(0x02);
	gotoxy(32, 2);
	cout << " $$$$$$$  $     $  $$$  $$$$$  $$$$$ ";
	gotoxy(32, 3);
	cout << "    $     $     $   $   $      $     ";
	gotoxy(32, 4);
	cout << "    $     $$$$$$$   $   $$$$$  $$$$$ ";
	gotoxy(32, 5);
	cout << "    $     $     $   $   $      $     ";
	gotoxy(32, 6);
	cout << "    $     $     $  $$$  $$$$$  $     ";
	color(0x07);
	color(0x01);
	gotoxy(20, 9);
	cout << " $$$    $$$$$  $$$$$  $$$$$    $$$  $$$$$  $$$  $   $   $$$$$ ";
	gotoxy(20, 10);
	cout << " $  $   $        $    $       $       $     $   $   $   $     ";
	gotoxy(20, 11);
	cout << " $   $  $$$$$    $    $$$$$  $        $     $    $ $    $$$$$ ";
	gotoxy(20, 12);
	cout << " $  $   $        $    $       $       $     $    $ $    $     ";
	gotoxy(20, 13);
	cout << " $$$    $$$$$    $    $$$$$    $$$    $    $$$    $     $$$$$ ";
	color(0x09);
	gotoxy(48, 18);
	cout << "loading";
	color(0x07);
	int i = 0;
	while (i <= 30)
	{
		color(0x30);
		gotoxy(i + 36, 21);
		cout << " ";
		Sleep(100);
		i++;
	}
}

int main()
{
	// size window
	w_size(850, 500);
	loading();
	Beep(1000, 100);
	start();
	cin.get();
	cin.get();
	return 0;
}

void border2(int x, int y)
{
	color(0x04);
	for (int i = 0; i < 25; i += 4)
	{
		gotoxy(x, y + i);
		cout << "=  =                                                                                              =  =";
		gotoxy(x, y + i + 1);
		cout << " =  ==                                                                                          ==  =";
		gotoxy(x, y + i + 2);
		cout << "  =  ===                                                                                      ===  =";
		gotoxy(x, y + i + 3);
		cout << " =  ==                                                                                          ==  =";
	}
}

void start()
{
	while (true)
	{
		border2(0, 0);
		gotoxy(46, 2);
		color(0x01);
		cout << "0.Start Game";
		gotoxy(48, 6);
		color(0x01);
		cout << "1.Tips";
		gotoxy(46, 10);
		color(0x01);
		cout << "2.Best Record";
		gotoxy(47, 14);
		color(0x01);
		cout << "3.Setting";
		gotoxy(48, 18);
		color(0x01);
		cout << "4.Exit";
		gotoxy(48, 26);
		color(0x01);
		cout << "Input:";
		color(0x07);
		int i;
		do
		{
			gotoxy(54, 26);
			cout << "     ";
			color(0x01);
			gotoxy(54, 26);
			cin >> i;
			color(0x07);
		} while (i > 4 || i < 0);

		if (i == 0)
		{
			system("cls");
			graphic();
			s_rand();
			S_T = 0;
			S_t = 0;
			int score = 0;
			e_T = 0;
			int i;
			char h;
			do
			{
				Neighbor();
				eye();
				if (S_T == 0 || S_t == 0)
				{
					if (S_T == 0 && S_t != 0)
					{
						int i = 0;
						while (i <= 10)
						{
							color(0x30);
							gotoxy(i + 81, 21);
							cout << " ";
							Sleep(100);
							i++;
						}
						color(0x07);
						gotoxy(81, 21);
						cout << "            ";
						gotoxy(86, 21);
						cout << "     ";
						gotoxy(86, 21);
						cout << "T";
					}
					else if (S_t == 0 && S_T != 0)
					{
						int i = 0;
						while (i <= 10)
						{
							color(0x30);
							gotoxy(i + 81, 21);
							cout << " ";
							Sleep(100);
							i++;
						}
						color(0x07);
						gotoxy(81, 21);
						cout << "            ";
						gotoxy(86, 21);
						cout << "     ";
						gotoxy(86, 21);
						cout << "t";
					}
					else
					{
						int i = 0;
						while (i <= 10)
						{
							color(0x30);
							gotoxy(i + 81, 21);
							cout << " ";
							Sleep(100);
							i++;
						}
						color(0x07);
						gotoxy(81, 21);
						cout << "            ";
						gotoxy(84, 21);
						cout << "T & t";
					}
					do
					{
						gotoxy(65, 21);
						cout << "     ";
						gotoxy(65, 21);
						cin >> h;
					} while ((h == 'T' && S_T != 0) || (h == 't' && S_t != 0) || (h != 't' && h != 'T'));
					do
					{
						gotoxy(61, 23);
						cout << "     ";
						gotoxy(61, 23);
						cin >> i;
					} while (i == home_T || i == home_t || i == home_D || i < 0 || i>10);
					if (i % 2 == balapayin && eye_enable == 1)
						e_T = 1;
					else if (i % 2 != balapayin && home_T % 2 == balapayin && eye_enable == 1)
						e_T = 2;
					else
						e_T = 0;
					if (i != 10)
					{
						if (h == 'T')
						{
							home_T = i;
							S_T = (S_T + 1) % 2;
							if (S_t != 0)
								S_t = (S_t + 1) % 3;
						}
						else if (h == 't')
						{
							home_t = i;
							S_t = (S_t + 1) % 3;
							if (S_T != 0)
								S_T = (S_T + 1) % 2;
						}
						Thief(i, h);
					}

				}
				else
				{
					S_T = (S_T + 1) % 2;
					S_t = (S_t + 1) % 3;
				}
				int i = 0;
				while (i <= 10)
				{
					color(0x30);
					gotoxy(i + 81, 21);
					cout << " ";
					Sleep(100);
					i++;
				}
				color(0x07);
				gotoxy(81, 21);
				cout << "            ";
				gotoxy(86, 21);
				cout << "     ";
				gotoxy(86, 21);
				cout << "D";
				detective();
				score += 1;
				gotoxy(13, 21);
				cout << score;
				Sleep(1000);
			} while (x_T != x_D || abs(y_T - y_D) != 3);
			Sleep(1000);
			Beep(1000, 1000);
			system("cls");
			color(0x04);
			gotoxy(25, 10);
			cout << " $   $  $$$$$  $   $    $      $$$$$  $$$$$  $$$$$ ";
			gotoxy(25, 11);
			cout << "  $ $   $   $  $   $    $      $   $  $      $     ";
			gotoxy(25, 12);
			cout << "   $    $   $  $   $    $      $   $  $$$$$  $$$$$ ";
			gotoxy(25, 13);
			cout << "   $    $   $  $   $    $      $   $      $  $     ";
			gotoxy(25, 14);
			cout << "   $    $$$$$  $$$$$    $$$$$  $$$$$  $$$$$  $$$$$ ";
			color(0x07);
			Score(score, 's');
		}
		else if (i == 1)
		{
			system("cls");
			cout << "Welcome to the game thief and detective.\n" << endl;
			_getch();
			cout << "this game consists of four characters which includes the thief, the assistant thief, the detective    and guardian, we will explain the work of each of them.\n";
			_getch();
			system("cls");
			start();
		}
		else if (i == 2)
		{
			system("cls");
			color(0x06);
			gotoxy(47, 9);
			cout << "First:  " << Show_Scores(1);
			gotoxy(46, 12);
			cout << "Second:  " << Show_Scores(2);
			gotoxy(47, 15);
			cout << "third:  " << Show_Scores(3);
			//gotoxy(47, 16);
			//cout <<"fourth: " << Show_Scores(4);
			//gotoxy(48, 19);
			//cout << "fifth: " << Show_Scores(5);
			Sleep(5000);
			start();

		}
		else if (i == 3)
		{

		}
		else
			exit(4);
		Sleep(1000);
	}
}

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)				//baray karakter hay bazi neshangar mouse harekat mikonad
{
	COORD coord;
	coord.X = x;
	coord.Y = y;


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void w_size(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, w, h, TRUE);
}

void home(int x, int y, int plate, char kind)					//sakhte khane ha ba estefade az in tabe
{
	gotoxy(x, y);
	cout << "***********";
	gotoxy(x, y + 5);
	cout << "***********";
	//noe khane ra moshakhas mikonad
	//plate khane ra moshakhas mikonad
	if (kind == 'a')
	{
		gotoxy(x + 5, y + 5);
		cout << " ";
		gotoxy(x + 5, y);
		cout << plate;
	}
	else
	{
		gotoxy(x + 5, y);
		cout << " ";
		gotoxy(x + 5, y + 5);
		cout << plate;
	}

	for (int i = 0; i < 4; i++)
	{
		gotoxy(x, y + i + 1);
		cout << "*         *";
	}
}

void border(int x, int y, int w, int h)
{
	// khat dor mohit bazi
	gotoxy(x, y);
	// khat bala
	for (int i = 0; i < w; i++)
	{
		cout << "=";
	}
	gotoxy(x, y + h);
	// khat payin
	for (int i = 0; i < w; i++)
	{
		cout << "=";
	}
	// khat chap
	for (int i = 0; i < h - 1; i++)
	{
		gotoxy(x, y + 1 + i);
		cout << "=";
	}
	// khat rast
	for (int i = 0; i < h - 1; i++)
	{
		gotoxy(x + w - 1, y + 1 + i);
		cout << "=";
	}
}

void graphic()
{
	// sakht khone ha
	for (int i = 0; i < 5; i++)
	{
		home((i * 13) + 5, 2, (i * 2), 'a');
		home((i * 13) + 5, 13, (i * 2) + 1, 'b');
	}
	// rasm line vasat koche
	gotoxy(5, 10);
	cout << "-- -- --  ----  -- --  ----  -- --  ----  -- --  ----  -- -- --";
	color(0x04);
	// border samt chap bala
	border(1, 0, 71, 20);
	// border samt rast
	border(71, 0, 30, 27);
	// border samt chap payin
	border(1, 20, 71, 7);
	color(0x07);
	// write possibility
	gotoxy(80, 3);
	cout << "possibility:";
	gotoxy(82, 19);
	cout << "character:";
	gotoxy(78, 23);
	cout << "purpose Detective:";
	gotoxy(6, 21);
	cout << "record:";
	gotoxy(55, 21);
	cout << "character:";
	gotoxy(55, 23);
	cout << "input:";
	gotoxy(21, 26);
	cout << "Made By Mohammad Zamin Kesht";
}

void s_rand()
{
	// megdar dahi avaliye
	srand((unsigned)time(NULL));
	int choice1, choice2, choice3;
	choice1 = rand() % 10;
	do
	{
		choice2 = rand() % 10;
		choice3 = rand() % 10;
	} while (choice1 == choice2 || choice2 == choice3 || choice1 == choice3);
	// gharar dadan mohre ha
	change(choice1);
	x_T = h_x;
	y_T = h_y;
	color(0x02);
	gotoxy(h_x, h_y);
	cout << "T";
	color(0x07);
	home_T = choice1;
	change(choice2);
	x_t = h_x;
	y_t = h_y;
	color(0x06);
	gotoxy(h_x, h_y);
	cout << "t";
	color(0x07);
	home_t = choice2;
	change(choice3);
	x_D = h_x;

	if (choice3 % 2 == 0)
		y_D = h_y + 3;
	else
		y_D = h_y - 3;
	color(0x01);
	gotoxy(x_D, y_D);
	cout << "D";
	color(0x07);
	home_D = choice3;

}

void change(int z)			// shomare khone
{
	switch (z)
	{
	case 0:
		h_x = 10;
		h_y = 5;
		break;
	case 1:
		h_x = 10;
		h_y = 15;
		break;
	case 2:
		h_x = 23;
		h_y = 5;
		break;
	case 3:
		h_x = 23;
		h_y = 15;
		break;
	case 4:
		h_x = 36;
		h_y = 5;
		break;
	case 5:
		h_x = 36;
		h_y = 15;
		break;
	case 6:
		h_x = 49;
		h_y = 5;
		break;
	case 7:
		h_x = 49;
		h_y = 15;
		break;
	case 8:
		h_x = 62;
		h_y = 5;
		break;
	case 9:
		h_x = 62;
		h_y = 15;
		break;
	}
}

void Thief(int input, char k)
{
	if (k == 'T')
	{
		color(0x02);
		gotoxy(x_T, y_T);
		cout << "  ";
		change(input);
		if (input % 2 == 0)
			Moveto('T', x_T, y_T, h_x, h_y + 4, 1, 75);
		else
			Moveto('T', x_T, y_T, h_x, h_y - 4, 1, 75);
		if (input % 2 == 0)
			Moveto('T', h_x, h_y + 4, h_x, h_y, 1, 75);
		else
			Moveto('T', h_x, h_y - 4, h_x, h_y, 1, 75);
		x_T = h_x;
		y_T = h_y;
	}
	else
	{
		color(0x06);
		gotoxy(x_t, y_t);
		cout << "  ";
		change(input);
		if (input % 2 == 0)
			Moveto('t', x_t, y_t, h_x, h_y + 4, 1, 75);
		else
			Moveto('t', x_t, y_t, h_x, h_y - 4, 1, 75);
		if (input % 2 == 0)
			Moveto('t', h_x, h_y + 4, h_x, h_y, 1, 75);
		else
			Moveto('t', h_x, h_y - 4, h_x, h_y, 1, 75);
		x_t = h_x;
		y_t = h_y;
	}
	color(0x07);
	gotoxy(65, 21);
	cout << "  ";
	gotoxy(61, 23);
	cout << "  ";
}

void Neighbor()

{
	po[0] = home_T;
	po[4] = 4;
	if ((abs(y_T - y_D) == 7 && (x_T == x_D)) || (x_T - 13 == x_D  && abs(y_T - y_D) == 3) || (x_T == x_D - 13 && abs(y_T - y_D) == 3))
		po[4] = 2;
	else if (y_T == y_D - 3 || y_T - 3 == y_D)
		po[4] = 3;
	else
		po[4] = 4;
	srand((unsigned)time(NULL));
	do
	{
		po[1] = rand() % 10;
		po[2] = rand() % 10;
		po[3] = rand() % 10;
	} while (po[0] == po[1] || po[0] == po[2] || po[0] == po[3] || po[1] == po[2] || po[1] == po[3] || po[2] == po[3]
		|| (po[0] == home_D || po[1] == home_D || po[2] == home_D || po[3] == home_D));
	// niro jadoyi dasyar
	int random_num = rand() % 100;
	if (random_num < 50 && home_t == home_D)
	{
		do
		{
			po[0] = rand() % 10;
		} while (po[0] == home_T || po[0] == po[1] || po[0] == po[2] || po[0] == po[3]);
	}


	// jabejayi

	srand((unsigned)time(NULL));
	random_num = rand() % 100;
	if (po[4] == 2)
	{
		if (random_num <= 50)
			Swap(po[0], po[1]);
	}
	else if (po[4] == 3)
	{
		if (random_num < 33)
			Swap(po[0], po[1]);
		else if (33 <= random_num &&random_num < 66)
			Swap(po[0], po[2]);
	}
	else if (po[4] == 4)
	{
		if (random_num < 25)
			Swap(po[0], po[1]);
		else if (25 <= random_num &&random_num < 50)
			Swap(po[0], po[2]);
		else if (50 <= random_num &&random_num < 75)
			Swap(po[0], po[3]);
	}
	if (po[4] == 2)
	{
		gotoxy(90, 8);
		cout << po[0];
		gotoxy(80, 8);
		cout << "65%";
		gotoxy(90, 10);
		cout << po[1];
		gotoxy(80, 10);
		cout << "35%";
		gotoxy(90, 12);
		cout << " ";
		gotoxy(80, 12);
		cout << "    ";
		gotoxy(90, 14);
		cout << " ";
		gotoxy(80, 14);
		cout << "   ";
	}
	else if (po[4] == 3)
	{
		gotoxy(90, 8);
		cout << po[0];
		gotoxy(80, 8);
		cout << "60%";
		gotoxy(90, 10);
		cout << po[1];
		gotoxy(80, 10);
		cout << "25%";
		gotoxy(90, 12);
		cout << po[2];
		gotoxy(80, 12);
		cout << "15%";
		gotoxy(90, 14);
		cout << " ";
		gotoxy(80, 14);
		cout << "   ";
	}
	else if (po[4] == 4)
	{
		gotoxy(90, 8);
		cout << po[0];
		gotoxy(80, 8);
		cout << "50%";
		gotoxy(90, 10);
		cout << po[1];
		gotoxy(80, 10);
		cout << "30%";
		gotoxy(90, 12);
		cout << po[2];
		gotoxy(80, 12);
		cout << "15%";
		gotoxy(90, 14);
		cout << po[3];
		gotoxy(80, 14);
		cout << "5%";
	}
}

void detective()
{
	// cheshm
	if (e_T == 1)
	{
		po[4] = 1;
		po[0] = home_T;
	}
	else if (e_T == 2)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i <= po[4]; i++)
			{
				if ((po[i]) % 2 == balapayin && po[4] > 0)
				{
					swap(po[i], po[po[4] - 1]);
					po[4] -= 1;
				}
			}
		}
		if (po[4] <= 0)
			po[4] = 1;
	}
	color(0x01);
	srand((unsigned)time(NULL));
	int random_num = rand() % 100 + 1;
	if (po[4] == 1)
		Dc = po[0];
	else if (po[4] == 2)
	{
		if (random_num <= 65)
			Dc = po[0];
		else
			Dc = po[1];
	}
	else if (po[4] == 3)
	{
		if (random_num <= 60)
			Dc = po[0];
		else if (random_num > 60 && random_num <= 85)
			Dc = po[1];
		else
			Dc = po[2];
	}
	else if (po[4] == 4)
	{
		if (random_num <= 50)
			Dc = po[0];
		else if (random_num > 50 && random_num <= 80)
			Dc = po[1];
		else if (random_num > 80 && random_num <= 95)
			Dc = po[2];
		else
			Dc = po[3];
	}
	//loding
	color(0x07);
	int i = 0;
	while (i <= 10)
	{
		color(0x30);
		gotoxy(i + 81, 25);
		cout << " ";
		Sleep(100);
		i++;
	}
	color(0x07);
	gotoxy(81, 25);
	cout << "           ";
	gotoxy(86, 25);
	cout << Dc;

	color(0x01);
	gotoxy(x_D, y_D);
	cout << " ";
	change(Dc);

	if (Dc % 2 == 0)
	{
		Moveto('D', x_D, y_D, h_x, h_y + 3, 1, 75);
		y_D = h_y + 3;
	}
	else
	{
		Moveto('D', x_D, y_D, h_x, h_y - 3, 1, 75);
		y_D = h_y - 3;
	}
	x_D = h_x;
	home_D = Dc;
	color(0x07);
	gotoxy(86, 25);
	cout << " ";
}

void eye()
{
	srand((unsigned)time(NULL));
	int random = (rand() % 100);
	if (random < ehtemal)
	{
		eye_enable = 1;
		balapayin = rand() % 2;
		if (balapayin == 0)
		{
			gotoxy(69, 9);
			cout << ">";
		}
		else
		{
			gotoxy(3, 11);
			cout << "<";
		}
		ehtemal = 0;
	}
	else
	{
		eye_enable = 0;
		gotoxy(69, 9);
		cout << " ";
		gotoxy(3, 11);
		cout << " ";
		ehtemal += 20;
	}
}
