/*1250300 建筑 陈正阳*/
#include <iostream>
#include<stdio.h>
#include<iomanip>

using namespace std;
int a[10],b[10],c[10];
int n;
char tower_start;
char tower_end;
static int step_count=0;


void tower_init(int tower[])
{
    int i;
    for(i=0;i<10;i++)
        tower[i]=0;
}
int hanno_input()
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
	do{
        cout<<"确定结束的塔:[A,B,C]"<<endl;
        cin>>tower_end;
        while(!(cin))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"确定结束的塔:[A,B,C]"<<endl;
        }
        if (tower_end==tower_start||tower_end!='A'&&tower_end!='B'&&tower_end!='C') cout<<"error, please check your input:"<<endl;
    }while(tower_end==tower_start||tower_end!='A'&&tower_end!='B'&&tower_end!='C');

   return 0;
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
	cout<<"初始状态"<<setw(14)<<" ";
}
/*void hanno_traverse()
{
    int i;
    cout<<"A:  ";
    for(i=0;i<10;i++)
    {
        if (a[i])
			cout<<setw(2)<<setiosflags(ios::left)<<a[i];
		else
			cout<<setw(2)<<" ";
    }

    cout<<"B:  ";
    for(i=0;i<10;i++)
    {
        if (b[i])
            cout<<setw(2)<<setiosflags(ios::left)<<b[i];
		else
			cout<<setw(2)<<" ";

    }

    cout<<"C:  ";
    for(i=0;i<10;i++)
    {
        if (c[i])
            cout<<setw(2)<<setiosflags(ios::left)<<c[i];
		else
			cout<<setw(2)<<" ";
    }

    cout<<endl;

}*/
void hanno_traverse2()
{
    int i;
    int count_num_a=0;
    int count_num_b=0;
    int count_num_c=0;
    for(i=9;i>=0;i--)
    {
        cout<<setw(15)<<" ";
        if (a[i])
        {
            cout<<setw(8)<<setiosflags(ios::left)<<a[i];
            count_num_a++;
        }

		else
			cout<<setw(8)<<" ";
        if (b[i])
        {
            cout<<setw(8)<<setiosflags(ios::left)<<b[i];
            count_num_b++;
        }

		else
			cout<<setw(8)<<" ";
        if (c[i])
        {
            cout<<setw(8)<<setiosflags(ios::left)<<c[i];
            count_num_c++;
        }

		else
			cout<<setw(8)<<" ";
        cout<<endl;
    }
    cout<<setw(12)<<" ";
    cout<<"----------------------"<<endl;
    cout<<setw(15)<<" ";
    cout<<setw(8)<<setiosflags(ios::left)<<count_num_a<<setw(8)<<setiosflags(ios::left)<<count_num_b<<setw(8)<<setiosflags(ios::left)<<count_num_c<<endl;
    cout<<setw(15)<<" ";
    cout<<setw(8)<<setiosflags(ios::left)<<"A"<<setw(8)<<setiosflags(ios::left)<<"B"<<setw(8)<<setiosflags(ios::left)<<"C";

}
int hanno_func(int tower1[],int tower2[])
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
	temp=tower1[i-1];
	tower1[i-1]=0;
	for (j=0;j<10;j++)
	{
		if(!tower2[j])
			break;
	}
	tower2[j]=temp;
	return 0;
}
int hanno_move(int step,int x,int y,int z,int a[],int b[],int c[])
{
    //i++;
    //cout<<i<<":"<<endl;
    int i;
    if (step==1)
    {

		hanno_func(a,c);
		hanno_traverse2();
		for (i=0;i<5;i++)
            cout<<endl;

		cout<<"第"<<setw(2)<<step_count<<"步: ";
        cout<<"("<<step<<"): ";
        cout<<char(x+64)<<"--->"<<char(z+64)<<"   ";

    }
    else
    {

        hanno_move(step-1,x,z,y,a,c,b);
		hanno_func(a,c);
		hanno_traverse2();
		for (i=0;i<5;i++)
            cout<<endl;
		cout<<"第"<<setw(2)<<step_count<<"步: ";
        cout<<"("<<step<<"): ";
        cout<<char(x+64)<<"--->"<<char(z+64)<<"   ";
        hanno_move(step-1,y,x,z,b,a,c);
    }
    return 0;
}
int main()
{
    int i=0;

    int x=1,y=2,z=3;
    hanno_input();
    if (tower_start=='A')
	{
        hanno_init(a);
		hanno_traverse2();
		if (tower_end=='B')
		{
			hanno_move(n,x,z,y,a,c,b);
		}
		else
			hanno_move(n,x,y,z,a,b,c);
	}
    else if(tower_start=='B')
    {
        hanno_init(b);
		hanno_traverse2();
		if (tower_end=='A')
		{
			hanno_move(n,y,z,x,b,c,a);
		}
		else
			hanno_move(n,y,x,z,b,a,c);
	}
    else
    {
        hanno_init(c);
		hanno_traverse2();
		if (tower_end=='A')
		{
			hanno_move(n,z,y,x,c,b,a);
		}
		else
			hanno_move(n,z,x,y,c,a,b);
	}




    //int hanno(int, int,int,int);
   // hanno(n,a,b,c);
   return 0;
}

