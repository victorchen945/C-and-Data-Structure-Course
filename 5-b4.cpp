#include<iostream>
#include<stdlib.h>
using namespace std;

int init(int a[],int n)
{
    int i;
    for (i=0;i<n;i++)
        a[i]=rand()%(100-60+1)+60;
    return a[i];
}
int traverse(int a[],int n)
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
    int n;
    do{
        cout<<"请输入数组的大小(大于等于50)"<<endl;
        cin>>n;
        if(n<50) cout<<"请重新输入"<<endl;
    }while(n<50);

    int a[n];
    cout<<"生成"<<n<<"个分数(假设都没挂科)"<<endl;
    init(a,n);
    traverse(a,n);
    cout<<"排序结果为:"<<endl;
    array_sort(a,0,n-1);
    traverse(a,n);
    cout<<"排名结果为："<<endl;
    array_scorelist(a,n);
    return 0;

}
