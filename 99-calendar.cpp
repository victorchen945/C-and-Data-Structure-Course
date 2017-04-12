/*1250300 建筑 陈正阳*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <windows.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define ERROR -1
void init_daylist(int day_list[12][42],int daymax[12],bool flag)
{
    int i,j;
    for (i=0;i<12;i++)
        for(j=0;j<42;j++)
            day_list[i][j]=0;
    if (flag)
        daymax[1]=29;
}
void gotoxy(HANDLE hout, int cod_x, int cod_y)
{
	COORD coord;
	coord.X = cod_x;
	coord.Y = cod_y;
	SetConsoleCursorPosition(hout, coord);
}
void setcolor(HANDLE hout, const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(hout, bg_color * 16 + fg_color);
}
void day_shift(int day_list[][42])
{
    int i,j;
    for (i=0;i<12;i++)
    {
        if (day_list[i][0])
        {
            for (j=41;j>=6;j--)
                day_list[i][j]=day_list[i][j-6];
            for(j=5;j>=0;j--)
                day_list[i][j]=0;
        }
        else
            for(j=0;j<41;j++)
                day_list[i][j]=day_list[i][j+1];

    }
}
void day_input(int day_list[12][42],int daymax[],int year)
{
    int i,j;
    int zell;
    int zeller(int year,int month,int day);
    for (i=0;i<12;i++)
    {
        for(j=1;j<=daymax[i];j++)
        {
            zell=zeller(year,i+1,1)+j-1;
            day_list[i][zell]=j;
        }

    }
    //for (i=0;i<12;i++)
    //{
     //   for (j=0;j<42;j++)
      //  {
       //     cout<<day_list[i][j];
      //      cout<<' ';
      //  }
      //  cout<<endl;

    //}

}
int zeller(int year,int month,int day)
{
    int w;

    int m=month;
    if (m==1||m==2)
    {
        m+=12;
        year--;
    }
    int y=year%100;
    int c=year/100;
    int d=day;

    w=y+y/4+c/4-2*c+(13*(m+1)/5)+d-1;
    w=w%7;

    if (w<0) w+=7;
    //cout<<w<<endl;
    return w;
}
void title_printer(char title_list[])
{
    int i;
    for (i=0;i<7;i++)
    {
        cout<<title_list[2*i]<<title_list[2*i+1];
        cout<<' ';
    }
}
void day_printer(HANDLE hout,int day_list[][42],int month,int line)
{
    int i,j;
    int k;
    for (i=line*7;i<(line+1)*7;i++)
    {
        if (day_list[month][i])
            {
                if((i+1)%7==0)
                {
                    setcolor(hout,0,4);
                    cout<<setw(2)<<day_list[month][i];
                }
                else
                {
                    if((i+1)%7==6)
                    {
                    setcolor(hout,0,5);
                    cout<<setw(2)<<day_list[month][i];
                    }
                    else
                    {
                        setcolor(hout,0,2);
                        cout<<setw(2)<<day_list[month][i];
                    }
                }
                setcolor(hout,0,7);
            }
        else
        {
            setcolor(hout,0,7);
            cout<<setw(2)<<' ';
        }
        cout<<' ';
    }
}
void blank_printer()
{
    cout<<"    ";
}

void total_printer(HANDLE hout,char title_list[],int day_list[][42])
{
    int i,j,k,l;
    for (k=0;k<4;k++)
    {
        for(l=0;l<3;l++)
        {
            title_printer(title_list);
            blank_printer();
        }
        cout<<endl;
        for (j=0;j<6;j++)
        {
            for (i=k*3;i<(k+1)*3;i++)
            {
                day_printer(hout,day_list,i,j);
                blank_printer();
            }
            cout<<endl;
        }
        cout<<endl;

    }
}

int main()
{
    int day_list[12][42];
    char title_list[]="一二三四五六日";
    int daymax[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int year,month,day;
    bool flag;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	system("mode con cols=100 lines=50");
    do
    {
        cout<<"please enter year"<<endl;
        cin>>year;
        if ((!(year % 4) && year % 100) || !(year % 400))
            flag = TRUE;
        else
            flag = FALSE;
        if (year<1900||year>2100)
            cout<<"error:please check the parameter you input:"<<endl;
    }while(year<1900||year>2100);
    init_daylist(day_list,daymax,flag);
    day_input(day_list,daymax,year);
    day_shift(day_list);
    total_printer(hout,title_list,day_list);
    //zeller(year,month,day);

    return 0;
}
