/*1250300 ฝจึþ ณยีýั๔*/

#include <iostream>
#include <cstdio>
using namespace std;
char trans_cpt(char a)
{
    if (a>='a'&&a<='z')
        a-='a'-'A';
    return a;
}
char trans_sml(char a)
{
    if (a>='A'&&a<='Z')
        a+='a'-'A';
    return a;
}
void trans(char sent[])
{
    int i;
    for (i=1;i<50;i++)
    {
        if (sent[i-1]==' ')
            sent[i]=trans_cpt(sent[i]);
        else
            sent[i]=trans_sml(sent[i]);
    }
    sent[0]=trans_cpt(sent[0]);
}
int main()
{
    char sent[50];
    cout<<"please input the sentence:";
    gets(sent);
    trans(sent);
    cout<<sent;
    return 0;
}
