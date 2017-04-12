/*1250300 建筑 陈正阳*/

#include <iostream>
#include <cstdio>
using namespace std;

void count_num(char line[][81])
{
    int i;
    int j;
    int capital_num=0,small_num=0,digital_num=0,space_num=0,other_num=0;
    for (i=0;i<3;i++)
    {
        for(j=0;j<81;j++)
        {
            if (line[i][j]=='\0')
                break;
            if (line[i][j]>='A'&&line[i][j]<='Z')
                capital_num++;
            else if (line[i][j]>='a'&&line[i][j]<='z')
                small_num++;
            else if (line[i][j]>='0'&&line[i][j]<='9')
                digital_num++;
            else if(line[i][j]==' ')
                space_num++;
            else
                other_num++;
        }

    }
    cout<<"大写字母"<<capital_num<<"个,"<<"小写字母"<<small_num<<"个,"<<"数字"<<digital_num<<"个,"<<"空格数"<<space_num<<"个,"<<"其他字符"<<other_num<<"个"<<endl;
}
int main()
{
    char line[3][81];
    int i;
    cout<<"please input the passage:"<<endl;
    for(i=0;i<3;i++)
        gets(line[i]);
    count_num(line);
    return 0;


}
