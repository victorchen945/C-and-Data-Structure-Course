/*1250300 建筑 陈正阳*/

#include<iostream>
#include <cmath>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 0
#define ERROR -1

double pt[7][2];
double vec[7][2];

void init()
{
    int i;
    for (i=0;i<7;i++)
    {
        pt[i][0]=0;
        pt[i][1]=0;
        vec[i][0]=0;
        vec[i][1]=0;
    }
}
void input(int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		cout<<"输入第"<<i+1<<"组坐标:   ";
		cin>>pt[i][0]>>pt[i][1];
	}
}
double length(int x1,int x2,int y1,int y2)
{
	double len;
	len=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return len;
}
double area(double pt[][2],int n)
{
    int i;
	double a,b,c;
	double S=0;
	double p=0;
	double sum=0;
	for(i=2;i<n;i++)
    {
        a=length(pt[0][0],pt[i-1][0],pt[0][1],pt[i-1][1]);
        b=length(pt[0][0],pt[i][0],pt[0][1],pt[i][1]);
        c=length(pt[i-1][0],pt[i][0],pt[i-1][1],pt[i][1]);
        if (a+b<=c||b+c<=a||c+a<=b) return FALSE;
        p=(double)(a+b+c)/2.0;
        S=sqrt(p*(p-a)*(p-b)*(p-c));
        sum+=S;
    }

	return sum;

}
double vector_mul(double vec[][2],int pos)
{
	double mul;
	mul=vec[pos][0]*vec[pos+1][1]-vec[pos+1][0]*vec[pos][1];
	return mul;
}
bool vector_compare(double vec[][2],int n)
{
    int pos;
    for (pos=0;pos<n-2;pos++)
    {
        if (vector_mul(vec,pos)*vector_mul(vec,pos+1)<=0)
            return FALSE;
    }
	return TRUE;
}
void construct_vector(double pt[][2],int n)
{
    int i;
    vec[0][0]=pt[0][0]-pt[n-1][0];
    vec[0][1]=pt[0][1]-pt[n-1][1];
	for (i=1;i<n;i++)
    {
        vec[i][0]=pt[i][0]-pt[i-1][0];
        vec[i][1]=pt[i][1]-pt[i-1][1];
    }
}


bool is_convex(double pt[][2],double vec[][2],int n)
{
    int i;
	for (i=2;i<n;i++)
    {
        if (!vector_compare(vec,n)) return FALSE;
    }
    return TRUE;
}
int main()
{
    int i;
    int n;
    cout<<"初始化参数"<<"---------------->"<<endl;
    init();
    do
    {
        cout<<"请输入多边形顶点数(4-7)"<<endl;
        cin>>n;
        if (n<4||n>7)
            cout<<"error:请重新输入:"<<endl;
    }while(n<4||n>7);
    cout<<"请输入顶点(x y)"<<endl;
    input(n);
    construct_vector(pt,n);
    if (is_convex(pt,vec,n))
    {
        cout<<"是凸";
        switch(n)
        {
        case 4:
            cout<<"四";break;
        case 5:
            cout<<"五";break;
        case 6:
            cout<<"六";break;
        case 7:
            cout<<"七";break;
        }
        cout<<"边形"<<endl;
        cout<<"其面积为:";
        cout<<area(pt,n)<<endl;
    }
    else
        cout<<"不是凸多边形"<<endl;

    return 0;
}

