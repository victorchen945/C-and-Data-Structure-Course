/*1250300 ½¨Öş ³ÂÕıÑô*/

#include <iostream>
#include <cstdio>
using namespace std;

void string_cpy(char str[][30],int j,int k)
{
    int i;
    for(i=0;i<30;i++)
        str[j][i]=str[k][i];
}
int string_cmp(char str[][30],int j,int k)
{
    int i;
    for(i=0;i<30;i++)
    {
        if (str[j][i]>str[k][i])
            return 1;
        else if (str[j][i]<str[k][i])
            return 0;
    }
    return 0;

}
int main()
{
    int i;
    char str[4][30];
    cout<<"please input 3 strings:";
    for (i=1;i<4;i++)
        cin>>str[i];
    if(string_cmp(str,2,3))
    {
        string_cpy(str,0,2);
        string_cpy(str,2,3);
        string_cpy(str,3,0);
    }
    if(!string_cmp(str,1,2))
        cout<<&str[1][0]<<" "<<&str[2][0]<<" "<<&str[3][0]<<endl;
    else if(!string_cmp(str,1,3))
        cout<<&str[2][0]<<" "<<&str[1][0]<<" "<<&str[3][0]<<endl;
    else
        cout<<&str[2][0]<<" "<<&str[3][0]<<" "<<&str[1][0]<<endl;
    return 0;
}
