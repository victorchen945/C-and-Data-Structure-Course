/*1250300 ½¨Öþ ³ÂÕýÑô*/

#include <iostream>
#include <cstdio>
using namespace std;

void decompile(char code[])
{
    int i;
    for (i=0;i<100;i++)
    {
        if (code[i]=='\0')
            break;
        else if (code[i]>='A'&&code[i]<='Z')
            code[i]='Z'-(code[i]-'A');
        else if (code[i]>='a'&&code[i]<='z')
            code[i]='z'-(code[i]-'a');
    }
    cout<<"the original code is:"<<endl;
    for (i=0;i<100;i++)
    {
        if(code[i]=='\0')
            break;
        else
            cout<<code[i];
    }
    cout<<endl;

}
int main()
{
    char code[100];
    cout<<"please input the code to decompile:"<<endl;
    gets(code);
    decompile(code);
}
