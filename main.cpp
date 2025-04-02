#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

const int fld_width = 20;
const int fld_height = 30;
const int scr_width = fld_width * 2;
const int scr_height = fld_height;

using namespace std;

int main()
{
    char command[1000];
    sprintf(command, "mode con cols=%d lines=%d", scr_width,scr_height);
    system(command);
	cout << "hi\n";
	return 0;
}