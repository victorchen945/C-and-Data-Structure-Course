/*1250300 建筑 陈正阳*/
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

int array_init(int a[],int n)
{
    int i=0;
    int j;
    ifstream fin;
    fin.open("score.dat",ios::in);
    if (!fin.is_open())
    {
        cout<<"打开失败"<<endl;
        return -1;
    }
    do
    {
        fin>>a[i];
        i++;

    }while(a[i-1]!=-1);
    for(j=i;j<n;j++)
        a[j]=-1;

    //for (i=0;i<1000;i++)
      //  cout<<a[i]<<" "<<i<<endl;
    fin.close();
    cout<<i<<endl;
    return i-1;
}
int array_traverse(int a[],int n)
{
    int i;
    for (i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
int array_partition(int a[],int low,int high)
{
    int pivotkey=a[low];
    while(low<high)
    {
        while(low<high&&a[high]<=pivotkey)
            --high;
        a[low]=a[high];
        while(low<high&&a[low]>=pivotkey)
            ++low;
        a[high]=a[low];
    }
    a[low]=pivotkey;
    return low;
}
int array_sort(int a[],int low,int high)
{
    int pivotloc=array_partition(a,low,high);
    if (pivotloc>low)
        array_sort(a,low,pivotloc-1);
    if (high>pivotloc)
        array_sort(a,pivotloc+1,high);
    return a[high];
}
void array_scorelist(int a[],int n)
{
    int i;
    int cur=1;
    cout<<a[0]<<" "<<cur<<endl;
    for (i=1;i<n;i++)
    {
        if (a[i]!=a[i-1]) cur=i+1;
        cout<<a[i]<<" "<<cur<<endl;
    }
}
int main()
{
    int a[1000];
    int array_num;
    init(a,1000);
    array_num=array_init(a,1000);
    cout<<"从文件读入"<<array_num<<"个数据"<<endl;
    array_traverse(a,array_num);
    cout<<"排序结果为:"<<endl;
    array_sort(a,0,array_num-1);
    array_traverse(a,array_num);
    cout<<"排名结果为："<<endl;
    array_scorelist(a,array_num);
    return 0;
}
