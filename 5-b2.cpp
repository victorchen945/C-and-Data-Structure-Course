/*1250300 ���� ������*/
#include <iostream>
using namespace std;

int Arr_Insert(int a[])
{
    int k;
    for(k=0;k<=100;k++)
    {
        a[k]=-k;
    }
    return a[k];
}
int Arr_func(int a[])
{
    int i,j;
    for (i=1;i<=100;i++)
    {
        for (j=i;j<=100;j+=i)
        {
            a[j]*=-1;
        }
    }
    return a[i];
}
int Arr_Traverse(int a[])
{
    int i;
    for (i=1;i<=100;i++)
        if (a[i]>0)
        {
            cout<<a[i]<<" ";
        }

    return 0;
}
int main()
{
    int a[100];
    cout<<"����100��Ԫ��:"<<endl;
    Arr_Insert(a);
    Arr_func(a);
    cout<<"�������Ϊ:"<<endl;
    Arr_Traverse(a);


}
