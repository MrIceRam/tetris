#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y) {
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

class Game {
public:
	Game() {
	}
	void showField() {
		for (int i = 0; i < 15; i++) {
			cout << "#" << endl;
		}
		for (int i = 0; i < 20; i++) {
			cout << "#";
		}
		for (int i = 0; i < 15; i++) {
			gotoxy(19, i);
			cout << "#" << endl;
		}
	}

	int run() {
		showField();

		int ch = 0;
		int i = 0;

		int x = 5, y = 5;

		while (true){
			while (!_kbhit()) {
				gotoxy(x, y);
				cout << i % 10;
				i++;
			}
			ch = _getch();

			if (ch == 224) {
				ch = _getch();
				gotoxy(20, 20);
				cout << ch;
			}

			switch (ch) {
			case 77: // вправо
				x++;
				break;
			}

			switch (ch) {
			case 80: // вниз
				y++;
				break;
			}
			switch (ch) {
			case 75: // Влево
				x--;
				break;
			}
			//72 вверх


		}
		return 0;
	}
};

int main()
{
	//system("mode con cols=20 lines=16");
	setlocale(LC_ALL, "Russian"); //Включает Русский язык в С++
	Game game;
	game.run();
	_getch();
}
