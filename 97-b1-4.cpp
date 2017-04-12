/*1250300 建筑 陈正阳*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <windows.h>
#include <iomanip>
using namespace std;

int a[11],b[11],c[11];
const int X_a=20;
const int X_b=45;
const int X_c=70;
const int Y=20;
char tower_start;
char tower_end;
const int ymax=4;
int column_height=11;
static int step_count=0;
int n;
int tower_color_set[10]={2,3,4,5,10,11,12,13,14,10};

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
	for (i=1;i<column_height+1;i++)
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
void draw_single_plate(HANDLE hout,int x,int y,int width)
{
    width++;
    showch(hout,x-width,y,tower_color_set[width-1],0,' ',2*width+1);
}
void draw_single_plate_black(HANDLE hout,int x,int y,int width)
{
    width++;
    showch(hout,x-width,y,0,7,' ',2*width+1);
}
int input_plate_num(HANDLE hout)
{
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
int input_tower_start_selection(HANDLE hout)

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
int input_tower_end_selection(HANDLE hout)

{
	int x;

	 do{
        cout<<"确定结束的塔:[A,B,C]"<<endl;
        cin>>tower_start;
        while(!(cin))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"确定结束的塔:[A,B,C]"<<endl;
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
void total_init()
{
    int i;
    for (i=0;i<10;i++)
    {
        a[i]=0;
        b[i]=0;
        c[i]=0;
    }
    a[10]=X_a;
    b[10]=X_b;
    c[10]=X_c;
}
void hanno_init(int tower[])
{
    int i;
    int temp=n;
    for (i=0;i<n;i++)
    {
        tower[i]=temp;
       // getchar();
        //cout<<tower[i]<<endl;
        temp--;
    }
}
void hanno_traverse3(HANDLE hout)
{
    int i;
    int count_num_a=0;
    int count_num_b=0;
    int count_num_c=0;
    //int y_a_step=0;
    //int y_b_step=0;
    //int y_c_step=0;
	//char skip=' ';
    for(i=0;i<=9;i++)
    {
        if (a[i])
        {
            draw_single_plate(hout,X_a,Y-count_num_a-1,a[i]-1);
            count_num_a++;
        }
        //else
		//	showch(hout,15,Y_a++,0,7,skip,1);
        if (b[i])
        {
            draw_single_plate(hout,X_b,Y-count_num_b-1,b[i]-1);
            count_num_b++;
        }

		//else
		//	showch(hout,23,Y_b++,0,7,skip,1);
        if (c[i])
        {
            draw_single_plate(hout,X_c,Y-count_num_c-1,c[i]-1);
            count_num_c++;
        }

		//else
		//	showch(hout,31,Y_c++,0,7,skip,1);
        //cout<<endl;


    }
    //cout<<setw(12)<<" ";
    //cout<<"----------------------"<<endl;
    //cout<<setw(15)<<" ";
    //cout<<setw(8)<<setiosflags(ios::left)<<count_num_a<<setw(8)<<setiosflags(ios::left)<<count_num_b<<setw(8)<<setiosflags(ios::left)<<count_num_c<<endl;
    //cout<<setw(15)<<" ";
    //cout<<setw(8)<<setiosflags(ios::left)<<"A"<<setw(8)<<setiosflags(ios::left)<<"B"<<setw(8)<<setiosflags(ios::left)<<"C";
    //getchar();
}
void single_movement(HANDLE hout,int tower1[],int tower2[],int i,int j)
{
    //getchar();

	//gotoxy(hout,40,30);
	//cout<<tower1[i-1]<<endl;

    int x,y;
	for (y = Y-i; y>ymax; y--) {
		draw_single_plate(hout,tower1[10],y,tower1[i-1]-1);
		Sleep(30);
		if (y>ymax) {
            draw_single_plate_black(hout,tower1[10],y,tower1[i-1]-1) ;
            if(y>Y-column_height-1)
                showch(hout,tower1[10],y,9,0,' ',1);
        }

    }
    if (tower1[10]<tower2[10])
    {
        for (x = tower1[10]; x<tower2[10]; x++) {
        draw_single_plate(hout,x,y,tower1[i-1]-1);
        Sleep(30);
        if (x<tower2[10]) {
            draw_single_plate_black(hout,x,y,tower1[i-1]-1);
            }
        }
    }
    else
    {
        for (x = tower1[10]; x>tower2[10]; x--) {
        draw_single_plate(hout,x,y,tower1[i-1]-1);
        Sleep(30);
        if (x>tower2[10]) {
            draw_single_plate_black(hout,x,y,tower1[i-1]-1);   //正常颜色：背景-0-黑色  前景-7-白色
            }
        }
    }
    for (y = ymax; y<=Y-j-1; y++) {
        draw_single_plate(hout,tower2[10],y,tower1[i-1]-1);
        Sleep(30);

        if (y<Y-j-1) {
            draw_single_plate_black(hout,tower2[10],y,tower1[i-1]-1);
            if (y>Y-column_height-1)
                showch(hout,tower2[10],y,9,0,' ',1);
        }
    }
    gotoxy(hout,2,30);

}
int hanno_func(HANDLE hout,int tower1[],int tower2[])
{
	int i;
	int j;
	int temp;
	step_count++;
	for (i=0;i<10;i++)
	{
		if (!tower1[i])
			break;
	}
	if (i==0)
        temp=0;
    else{
        temp=tower1[i-1];
    }
	for (j=0;j<10;j++)
	{
		if(!tower2[j])
			break;
	}
	//cout<<i<<endl;
	//cout<<j<<endl;
	single_movement(hout,tower1,tower2,i,j);
	tower2[j]=temp;
    tower1[i-1]=0;
	return 0;
}
int hanno_move(HANDLE hout,int step,int x,int y,int z,int a[],int b[],int c[])
{
    //i++;
    //cout<<i<<":"<<endl;
    int i;
    if (step==1)
    {

		hanno_func(hout,a,c);
		hanno_traverse3(hout);
		setcolor(hout, 0, 7);
		gotoxy(hout,0,25);
		cout<<"第"<<setw(2)<<step_count<<"步: ";
        cout<<"("<<step<<"): ";
        cout<<char(x+64)<<"--->"<<char(z+64)<<"   ";

    }
    else
    {

        hanno_move(hout,step-1,x,z,y,a,c,b);
		hanno_func(hout,a,c);
		hanno_traverse3(hout);
		setcolor(hout, 0, 7);
		gotoxy(hout,0,25);
		cout<<"第"<<setw(2)<<step_count<<"步: ";
        cout<<"("<<step<<"): ";
        cout<<char(x+64)<<"--->"<<char(z+64)<<"   ";
        hanno_move(hout,step-1,y,x,z,b,a,c);
    }
    return 0;
}
int main()
{
	int fg_color=9;
	int bg_color=0;
	int tower_start;
	int tower_end;
	int plate_num;
    int x=1,y=2,z=3;
	total_init();
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	system("mode con cols=100 lines=30");

	tower_start=input_tower_start_selection(hout);
	tower_end=input_tower_end_selection(hout);
	plate_num=input_plate_num(hout);
	draw_tower(hout,fg_color,bg_color);
	//draw_plates(hout,tower_start,plate_num);
	//cout<<tower_start;

	if (tower_start==X_a)
	{
        hanno_init(a);
		hanno_traverse3(hout);
		if (tower_end==X_b)
		{
			hanno_move(hout,n,x,z,y,a,c,b);
		}
		else
			hanno_move(hout,n,x,y,z,a,b,c);
	}
	else if (tower_start==X_b)
	{
        hanno_init(b);
		hanno_traverse3(hout);
		if (tower_end==X_a)
		{
			hanno_move(hout,n,y,z,x,b,c,a);
		}
		else
			hanno_move(hout,n,y,x,z,b,a,c);
	}
	else if (tower_start==X_c)
	{
        hanno_init(c);
		hanno_traverse3(hout);
		if (tower_end==X_a)
		{
			hanno_move(hout,n,z,y,x,c,b,a);
		}
		else
			hanno_move(hout,n,z,x,y,c,a,b);
	}

    setcolor(hout,0,7);
	gotoxy(hout,0,30);
	return 0;
}

