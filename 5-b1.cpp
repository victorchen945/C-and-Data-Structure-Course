/*1250300 ½¨Öş ³ÂÕıÑô*/

#include<iostream>
#include<iomanip>
using namespace std;


void traverse(int a[][10])
{
    int i,j;
    int k;
    for (i=0;i<10;i++)
    {
        for (k=1;k<10-i;k++)
            cout<<setw(3)<<" ";
        for (j=0;j<=i;j++)
            cout<<setw(6)<<setiosflags(ios::left)<<a[i][j];
        cout<<endl;
    }
}
void yanghui(int a[][10])
{
    int i;
    int j;

    for (i=0;i<10;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for (i=2;i<10;i++)
    {
        for (j=i-1;j>=1;j--)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    }
}
int main()
{
    int a[10][10];
    yanghui(a);
    traverse(a);
    return 0;

}
