/*1250300 ½¨Öş ³ÂÕıÑô*/

#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

void init(int minefield[][28],char mineshow[][28])
{
    int i,j;
    for (i=0;i<12;i++)
        for (j=0;j<28;j++)
        {
            minefield[i][j]=0;
            mineshow[i][j]='0';
        }

}
void mine_count(int minefield[][28],char mineshow[][28])
{
    int i,j;
    int sum=0;
    for(i=1;i<=10;i++)
    {
        for (j=1;j<=26;j++)
        {
            if(minefield[i][j]==1)
            {
                mineshow[i][j]='*';
                continue;
            }
            else
            {
                sum=minefield[i-1][j-1]+minefield[i][j-1]+minefield[i+1][j-1]+minefield[i-1][j]+minefield[i+1][j]+minefield[i-1][j+1]+minefield[i][j+1]+minefield[i+1][j+1];
                mineshow[i][j]=sum+'0';
               // cout<<sum;
                sum=0;
            }
        }
    }
}
void traverse(char mineshow[][28])
{
    int i,j;
    for (i=1;i<=10;i++)
    {
        for(j=1;j<=26;j++)
            cout<<mineshow[i][j]<<' ';
        cout<<endl;
    }
}
int main()
{
    int minefield[12][28];
    char mineshow[12][28];
    int mine_x;
    int mine_y;
    int i;
    int j;
	srand((unsigned int)(time(0)));
	init(minefield,mineshow);
	for(i=0;i<50;i++)
	{
	    mine_x=rand()%26+1;
        mine_y=rand()%10+1;

	    //cout<<mine_x<<" "<<mine_y<<endl;
	    minefield[mine_y][mine_x]=1;
	}
	/*for(i=0;i<=10;i++)
        for (j=0;j<=26;j++)
            cout<<minefield[i][j]<<" ";*/

	mine_count(minefield,mineshow);
	traverse(mineshow);
    return 0;
}
