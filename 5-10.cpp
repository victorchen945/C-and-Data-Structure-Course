/*1250300 ���� ������*/

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
    cout<<"��д��ĸ"<<capital_num<<"��,"<<"Сд��ĸ"<<small_num<<"��,"<<"����"<<digital_num<<"��,"<<"�ո���"<<space_num<<"��,"<<"�����ַ�"<<other_num<<"��"<<endl;
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
