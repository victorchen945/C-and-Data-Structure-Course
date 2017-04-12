/*1250300 建筑 陈正阳*/
#include <iostream>
#include<stdio.h>

using namespace std;
int a[10],b[10],c[10];
int n;
char tower;
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
        cin>>tower;
        while(!(cin))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"确定初始的塔:[A,B,C]"<<endl;
        }
        if (tower!='A'&&tower!='B'&&tower!='C') cout<<"error, please check your input:"<<endl;
    }while(tower!='A'&&tower!='B'&&tower!='C');

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
}
void hanno_traverse()
{
    int i;
    cout<<"A:  ";
    for(i=0;i<10;i++)
    {
        if (a[i])
            cout<<a[i]<<"  ";
    }

    cout<<"B:  ";
    for(i=0;i<10;i++)
    {
        if (b[i])
            cout<<b[i]<<"  ";
    }

    cout<<"C:  ";
    for(i=0;i<10;i++)
    {
        if (c[i])
            cout<<c[i]<<"  ";
    }

    cout<<endl;

}
int hanno(int step,int x,int y,int z)
{
    //i++;
    //cout<<i<<":"<<endl;
    static int step_count=0;

    if (step==1)
    {

        cout<<"第"<<step_count<<"步:   ";
        step_count++;
        cout<<"第"<<step<<"个盘子:     ";
        cout<<char(x+64)<<"->"<<char(z+64)<<endl;

    }
    else
    {

        hanno(step-1,x,z,y);

        step_count++;
    cout<<"第"<<step_count<<"步:   ";
        cout<<"第"<<step<<"个盘子      ";
        cout<<char(x+64)<<"->"<<char(z+64)<<endl;
        hanno (step-1,y,x,z);
    }
    return 0;
}
int main()
{
    int i=0;
    hanno_input();
    if (tower=='A')
        hanno_init(a);
    else if(tower=='B')
        hanno_init(b);
    else
        hanno_init(c);

    hanno_traverse();

    int x=1,y=2,z=3;
    hanno(n,x,y,z);

    //int hanno(int, int,int,int);
   // hanno(n,a,b,c);
   return 0;
}

