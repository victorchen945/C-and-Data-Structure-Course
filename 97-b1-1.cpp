/*1250300 建筑 陈正阳*/
#include <iostream>

#include <ctime>
#include <cmath>
#include <cstdio>
#include <windows.h>
#include <iomanip>

const int X_a=10;
const int X_b=30;
const int X_c=50;
const int Y=20;


void gotoxy(HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}
void setcolor(HANDLE hout, const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(hout, bg_color * 16 + fg_color);
}

void showch(HANDLE hout, const int X, const int Y, const int bg_color, const int fg_color, const char ch, const int n)
{
	int i;
	gotoxy(hout, X, Y);
	setcolor(hout, bg_color, fg_color);

	/* 循环n次，打印字符ch */
	for (i = 0; i<n; i++)
		putchar(ch);
}
void draw_foundation(HANDLE hout,int fg_color,int bg_color)
{
	showch(hout,X_a-8,Y,fg_color,bg_color,' ',16);
	showch(hout,X_b-8,Y,fg_color,bg_color,' ',16);
	showch(hout,X_c-8,Y,fg_color,bg_color,' ',16);
	
}
void draw_column(HANDLE hout,int fg_color,int bg_color)
{
	int i;
	for (i=1;i<12;i++)
	{
		showch(hout,X_a,Y-i,fg_color,bg_color,' ',1);
		showch(hout,X_b,Y-i,fg_color,bg_color,' ',1);
		showch(hout,X_c,Y-i,fg_color,bg_color,' ',1);
	}
}
void draw_tower(HANDLE hout,int fg_color,int bg_color)
{
	
	draw_foundation(hout,fg_color,bg_color);
	draw_column(hout,fg_color,bg_color);

}

int main()
{
	int fg_color=9;
	int bg_color=0;
	
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	draw_tower(hout,fg_color,bg_color);
	gotoxy(hout,0,30);
	return 0;
}