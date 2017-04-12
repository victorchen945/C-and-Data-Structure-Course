/*1250300 建筑 陈正阳*/
#include <iostream>
#include<fstream>
#include<iomanip>


using namespace std;

bool shudu_difference(int a[])
{
    int i,j;
    for (i=0;i<9;i++)
    {
        for (j=i+1;j<9;j++)
        {
            if (a[i]==a[j]) return false;
        }
    }
    return true;
}
bool shudu_row(int a[][9])
{
    int i,j;
    int row[9];
    for (i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            row[j]=a[i][j];
        }
        if (!shudu_difference(row))
            return false;
    }
    //cout<<"YESr"<<endl;
    //getchar();
    return true;
}
bool shudu_col(int a[][9])
{
    int i,j;
    int col[9];
    for (i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            col[j]=a[j][i];
        }
        if (!shudu_difference(col))
            return false;
    }
   // cout<<"YESc"<<endl;
   // getchar();
    return true;
}
bool shudu_box(int a[][9])
{
    int i,j;
    int k,l;
    int m;
    int count_box=0;
    int box[9];
    for (i=0;i<9;i+=3)
    {
        for(j=0;j<9;j+=3)
        {
            for (k=0,count_box=0;k<3;k++)
            {
                for(l=0;l<3;l++)
                {
                    box[count_box]=a[i+k][j+l];
                    count_box++;
                }
            }
           // for(m=0;m<9;m++)
               // cout<<box[m]<<endl;
            if (!shudu_difference(box))
                return false;
        }
    }
    //cout<<"YESb"<<endl;
   // getchar();
    return true;
}
bool shudu_decision(int shudu[][9])
{
    if(shudu_row(shudu)&&shudu_col(shudu)&&shudu_box(shudu))
        return true;
    return false;
}
int main()
{
    int shudu[9][9];
    int i;
    int j;
    ifstream infile;
    infile.open("shudu.txt",ios::in);
    if(infile.is_open()==0)
    {
        cout<<"打开文件失败"<<endl;
        return -1;
    }
    for (i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            infile>>shudu[i][j];
        }
    }
    cout<<"打开成功,矩阵为:"<<endl;
    for (i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<setw(3)<<setiosflags(ios::left)<<shudu[i][j];
        }
        cout<<endl;
    }
    if(shudu_decision(shudu))
        cout<<"该矩阵为数独的解"<<endl;
    else
        cout<<"该矩阵不为数独的解"<<endl;

    return 0;
}
