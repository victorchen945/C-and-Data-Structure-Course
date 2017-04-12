/*1250300 建筑 陈正阳*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i;
    int k;
    char stu_name[10][12];
    int stu_digital[10][2];
    int stu_fail_num[10];
    for (i=0;i<10;i++)
        stu_fail_num[i]=-1;
    int j=0;
    for (i=0;i<10;i++)
    {

        do
        {
            cout<<"请输入第"<<i+1<<"个学生姓名 学号与成绩:"<<endl;
            cin>>stu_name[i];
            cin>>stu_digital[i][0]>>stu_digital[i][1];
            if (cin.fail()||stu_digital[i][1]<0||stu_digital[i][1]>100)
                cout<<"error:please check your input:"<<endl;
            cin.clear();
        }while(cin.fail()||stu_digital[i][1]<0||stu_digital[i][1]>100);

        if (stu_digital[i][1]<60)
            {
                stu_fail_num[j]=i;
                j++;
            }
    }
    cout<<"输入完毕"<<endl;
    for (j=0;stu_fail_num[j]!=-1;j++)
    {

        cout<<"不及格学生"<<j+1<<"--->姓名:";
        cout<<&stu_name[stu_fail_num[j]][0];
        cout<<"学号:"<<stu_digital[stu_fail_num[j]][0]<<"成绩:"<<stu_digital[stu_fail_num[j]][1]<<endl;
    }
    return 0;
}
