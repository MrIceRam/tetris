#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;

void gotoxy(int x, int y) {
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

const int WIDTH = 10 + 2; 
const int HEIGHT = 20 + 1;

struct Point {
	int x;
	int y;
};

class Figure {
	vector<Point> vec;
public:
	void push(int x, int y) {
		Point temp;
		temp.x = x;
		temp.y = y;
		vec.push_back(temp); // правильно vec.push_back(temp);
	}

	void show() {
		for (int i = 0; i < vec.size(); i++) {
			gotoxy(vec[i].x, vec[i].y);
			cout << "*";
		}
	}

	void hide() {
		for (int i = 0; i < vec.size(); i++) {
			gotoxy(vec[i].x, vec[i].y);
			cout << " ";
		}
	}
	
	void moveDown() {
		for (int i = 0; i < vec.size(); i++) {
			vec[i].y++;

		}
	}

	void moveUp() {
		for (int i = 0; i < vec.size(); i++) {
			vec[i].y--;
		}
	}

	void moveLeft() {
		for (int i = 0; i < vec.size(); i++) {
			vec[i].x--;

		}
	}

	void moveRight() {
		for (int i = 0; i < vec.size(); i++) {
			vec[i].x++;

		}
	}

	bool isCollision(const vector <vector <int>> &vec2d) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec2d[vec[i].y][vec[i].x] == 1) // столкновение с границей
				return true;
			if (vec2d[vec[i].y][vec[i].x] == 2) // столкновение с фингурой
				return true;
		}
		return false;
	}


	void fixed(vector <vector <int>>& vec2d) {
		for (int i = 0; i < vec.size(); i++) {
			vec2d[vec[i].y][vec[i].x] = 2;

		}
	}

	void spawn() { // фигура пока что только квадрат
		vec.clear();
		this->push(4, 0);
		this->push(5, 0);
		this->push(4, 1);
		this->push(5, 1);
	}
	
};

class Game {

	vector <vector<int>> vec;

public:
	Game() {
	}

	void initVec(vector <vector<int>> & vec,int width, int height) {
		vector<int> temp;
		temp.push_back(1);
		for (int i = 1; i < width - 1; i++) {
			temp.push_back(0);
		}
		temp.push_back(1);

		for (int i = 0; i < height-1; i++) {
			vec.push_back(temp);
		}

		temp.clear();
		for (int i = 0; i < width; i++) {
			temp.push_back(1);
		}
		vec.push_back(temp);
	}

	void showField(const vector <vector<int>>& vec) {

		// Для отладки
		for (int i = 0; i < vec.size(); i++) {
			gotoxy(19, i);
			for (int j = 0; j < vec[i].size(); j++) {
				cout << vec[i][j];
			}
			cout << endl;
		}

		for (int i = 0; i < vec.size(); i++) {
			gotoxy(0, i);
			for (int j = 0; j < vec[i].size(); j++) {
				if (vec[i][j] == 1) {
					cout << "#";
				}
				if (vec[i][j] == 2) {
					cout << "@";
				}
				if (vec[i][j] == 0) {
					cout << " ";
				}
			}
			cout << endl;
		}
	}

	int run() {
		initVec(vec, WIDTH, HEIGHT);
		showField(vec);

		Figure fig;
		fig.spawn();

		int ch = 0;
		int i = 0;
		int x = 5, y = 5;
		while (true){
			while (!_kbhit()) {
				gotoxy(x, y);
				fig.hide();
				
				fig.moveDown();
				if (fig.isCollision(vec)) {
					fig.moveUp();
					fig.fixed(vec);
					showField(vec);
					fig.spawn();
				}
				fig.show();
				Sleep(200);
				
				i++;
			}

			ch = _getch();
			
			// Понять под каким номером находиться стрелки (влево, вправо, верх, вниз)
			//if (ch == 224) {
			//	ch = _getch(); 
			//	gotoxy(20, 20);
			//	//cout << ch;
			//}

			switch (ch) {
			case 77: // вправо
				fig.hide();
				fig.moveRight();
				if (fig.isCollision(vec) ) {
					fig.moveLeft();
				}
				break;
			}
			switch (ch) {
			case 80: // вниз
				y++;
				break;
			}
			switch (ch) {
			case 75: // Влево
				fig.hide();
				fig.moveLeft();
				if (fig.isCollision(vec)) {
					fig.moveRight();
				}
				break;
			}
			//72 вверх
		}
		return 0;
	}
};

int main()
{
	//system("mode con cols=30 lines=20");
	setlocale(LC_ALL, "Russian"); //Включает Русский язык в С++
	Game game;
	game.run();
	_getch();
}