/*1250300 ���� ������*/

#include<iostream>
using namespace std;

void array_init(int a[],int n)
{
    int i;
    for (i=0;i<n;i++)
        a[i]=2*i;
}
void array_insert(int a[],int n,int e)
{
    int i;
    int j;

    for (i=0;i<n;i++)
        if (e<a[i]) break;
    for (j=n;j>=i;j--)
        a[j+1]=a[j];
    a[i]=e;
}
void array_traverse(int a[],int n)
{
    int i;
    for (i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    int e;

    do
    {
        cout<<"�����������С(С��999)"<<endl;
        cin>>n;
        if (n<=0) cout<<"����������"<<endl;
    }while(n<=0);
    int a[1000];
    cout<<"��������Ϊ:"<<endl;
    array_init(a,n);
    array_traverse(a,n);
    cout<<"������Ҫ�����Ԫ��:"<<endl;
    cin>>e;
    array_insert(a,n,e);
    cout<<"����ɹ���������Ϊ:"<<endl;
    array_traverse(a,n);
    return 0;

}
