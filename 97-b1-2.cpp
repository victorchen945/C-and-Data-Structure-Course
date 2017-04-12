/*1250300 建筑 陈正阳*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <windows.h>
#include <iomanip>
using namespace std;

const int X_a=20;
const int X_b=45;
const int X_c=70;
const int Y=20;
char tower_start;
char tower_end;
int tower_color_set[10]={2,3,4,5,10,11,12,13,14,6};

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
	showch(hout,X_a-12,Y,fg_color,bg_color,' ',24);
	showch(hout,X_b-12,Y,fg_color,bg_color,' ',24);
	showch(hout,X_c-12,Y,fg_color,bg_color,' ',24);

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
void draw_plates(HANDLE hout,int x,int n)
{
	int i;
	for (i=1;i<=n;i++)
	{
		showch(hout,x-n-1+i,Y-i,tower_color_set[i-1],0,' ',2*(n+1-i)+1);
	}
}
int input_plate_num(HANDLE hout)
{
	int n;
	do{
        cout<<"请输入盘子数目[0-10]"<<endl;
        cin>>n;
        while(!(cin))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"请输入盘子数目[0-10]"<<endl;
        }
        if (n<1||n>10) cout<<"error, please check your input:"<<endl;
    }while(n<1||n>10);
	return n;
}
int input_tower_selection(HANDLE hout)

{
	int x;

	 do{
        cout<<"确定初始的塔:[A,B,C]"<<endl;
        cin>>tower_start;
        while(!(cin))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"确定初始的塔:[A,B,C]"<<endl;
        }
        if (tower_start!='A'&&tower_start!='B'&&tower_start!='C') cout<<"error, please check your input:"<<endl;
    }while(tower_start!='A'&&tower_start!='B'&&tower_start!='C');
	switch(tower_start)
	{
	case ('A'):x=X_a;break;
	case ('B'):x=X_b;break;
	case ('C'):x=X_c;break;
	}
	return x;
}
int main()
{
	int fg_color=9;
	int bg_color=0;
	int tower_num;
	int plate_num;



	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	system("mode con cols=100 lines=30");

	tower_num=input_tower_selection(hout);
	plate_num=input_plate_num(hout);
	draw_tower(hout,fg_color,bg_color);
	draw_plates(hout,tower_num,plate_num);

    setcolor(hout,0,7);
	gotoxy(hout,0,30);
	return 0;
}
