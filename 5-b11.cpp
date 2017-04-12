/*1250300 ½¨Öş ³ÂÕıÑô*/

#include <iostream>
using namespace std;

//void string_cpy(char str[][30],int j,int k)
//{
  //  int i;
 //   for(i=0;i<30;i++)
//        str[j][i]=str[k][i];
//}
int string_cmp(char str[][10],int j,int k)
{
    int i;
    for(i=0;i<10;i++)
    {
        cout<<"i="<<i<<" :";
        cout<<str[j][i]<<" "<<str[k][i]<<endl;

        if (str[j][i]!=str[k][i])
            return 0;
        if (str[j][i]=='/0')
            return 1;
    }
    return 1;
}
int search_stu(char find_name[][10],int num[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (string_cmp(find_name,i,50)==1)
        {
            cout<<&find_name[i][0]<<"has been found,his number is "<<&num[i]<<endl;
            return 1;
        }
    }
    cout<<"can't find this name";
    return 0;
}
int main()
{
    int n;
    char name[51][10];
    int num[50];
    int i;
    do{
        cout<<"please input number of this class:";
        cin>>n;
        if (n>50)
            cout<<"too many students"<<endl;
    }while(n>50);
    cout<<endl;


    for(i=0;i<n;i++)
    {
        cout<<"input name and no. of student"<<i+1<<":";
        cin>>name[i];
        cin>>num[i];
    }
    cout<<"please input name you want to find:";
    cin>>name[50];
    cout<<&name[50][0]<<endl;
    search_stu(name,num,n);
    return 0;

}
