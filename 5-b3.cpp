/*1250300 建筑 陈正阳*/

#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

int year_boolean(int year)
{
    if ((year % 4) || (!(year % 100) && year % 400))
        return FALSE;
    return TRUE;
}
void day_num(int month[],bool flag)
{
    int i;
    for (i=0;i<13;i+=2)
    {
        month[i]=31;
        month[i+1]=30;
    }
    for (i=7;i<12;i++)
        month[i]=month[i+1];
    if (flag)
        month[1]=29;
    else month[1]=28;
    //for (i=0;i<12;i++)
     //   cout<<month[i]<<endl;
}

int day_count(int month[],int cur_month,int cur_day)
{

    int i;
    for (i=0;i<cur_month-1;i++)
    {
        cur_day+=month[i];

    }

    return cur_day;
}

int main()
{
    int year,cur_month,cur_day;
    int day;
    int month[13];
    bool flag;
    do
    {
        cout<<"请输入年 月 日"<<endl;
        cin>>year>>cur_month>>cur_day;
        flag=year_boolean(year);
        day_num(month,flag);
        if(year<0||cur_month<1||cur_month>12||cur_day<1||month[cur_month-1]<cur_day)
            cout<<"输入错误"<<endl;
    }while(year<0||cur_month<1||cur_month>12||cur_day<1||month[cur_month-1]<cur_day);

    day=day_count(month,cur_month,cur_day);
    cout<<"该日期为"<<year<<"年的第"<<day<<"天"<<endl;

    return 0;
}
