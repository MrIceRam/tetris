#include <iostream>

using namespace std;
int x;
int a;
int ym2(){
	system("CD");
	system("DIR");
	system("md ямамин лох лазурный");
	return 52;
}

int main()
{
	setlocale(LC_ALL, "Russian"); //Включает Русский язык в С++
	
	system("mode con cols=50 lines=40");
	system("COLOR 2");
	cout << "хуй бобра";
	system("CLS");
	cin >> x;
	if (x== 42){
		a = ym2();
	}

	cin >> x;
	if (a == 52){
		system("RD ямамин лох лазурный");
	}
	return 0;
}
