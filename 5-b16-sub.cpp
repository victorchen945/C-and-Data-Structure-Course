/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */
#include <iostream>
#include <cstdio>
using namespace std;

#include "5-b16.h"

int tj_strlen(const char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i; //return值可根据需要修改
}

int tj_strcat(char s1[], const char s2[])
{
    int i=0;
    int j;
    while(s1[i]!='\0')
    {
        i++;
    }
    for (j=0;s2[j]!='\0';j++,i++)
        s1[i]=s2[j];
    s1[i]='\0';
    return 0; //return值可根据需要修改
}

int tj_strcpy(char s1[], const char s2[])
{
    int i=0;
    while(s2[i]!='\0')
    {
        s1[i]=s2[i];
        i++;
    }
    while(s1[i]!='\0')
    {
        s1[i]='\0';
        i++;
    }
    return 0; //return值可根据需要修改
}

int tj_strncpy(char s1[], const char s2[], int len)
{
    int i=0;
    while(s2[i]!='\0'&&i<len)
    {
        s1[i]=s2[i];
        i++;
    }
    return 0; //return值可根据需要修改
}

int tj_strcmp(const char s1[], const char s2[])
{
    int i=0;
    int cmp;
    while(s1[i]!='\0'||s2[i]!='\0')
    {
        cmp=s1[i]-s2[i];
        if (cmp) return cmp;
        i++;
    }
    return 0; //return值可根据需要修改
}

int tj_strcasecmp(const char s1[], const char s2[])
{
    int i=0;
    int cmp;
    while(s1[i]!='\0'||s2[i]!='\0')
    {
        if(s1[i]>='A'&&s1[i]<='z'&&s2[i]>='A'&&s2[i]<='z'&&(s1[i]-s2[i]=='A'-'a'||s2[i]-s1[i]=='A'-'a'))
            cmp=0;
        else
            cmp=s1[i]-s2[i];
        if (cmp) return cmp;
        i++;
    }
    return 0; //return值可根据需要修改
}

int tj_strncmp(const char s1[], const char s2[], int len)
{
    int i=0;
    int cmp;
    while(i<len)
    {
        if(s1[i]=='\0'&&s2[i]=='\0')
            break;
        cmp=s1[i]-s2[i];
        if (cmp) return cmp;
        i++;
    }
    return 0; //return值可根据需要修改
}

int tj_strcasencmp(const char s1[], const char s2[], int len)
{
    int i=0;
    int cmp;
    while(i<len)
    {
        if(s1[i]=='\0'&&s2[i]=='\0')
            break;
        if(s1[i]>='A'&&s1[i]<='z'&&s2[i]>='A'&&s2[i]<='z'&&(s1[i]-s2[i]=='A'-'a'||s2[i]-s1[i]=='A'-'a'))
            cmp=0;
        else
            cmp=s1[i]-s2[i];
        if (cmp) return cmp;
        i++;
    }
    return 0; //return值可根据需要修改
}

int tj_strupr(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if (str[i]>='a'&&str[i]<='z')
            str[i]-='a'-'A';
        i++;
    }

    return 0; //return值可根据需要修改
}

int tj_strlwr(char str[])
{
   int i=0;
    while(str[i]!='\0')
    {
        if (str[i]>='A'&&str[i]<='Z')
            str[i]+='a'-'A';
        i++;
    }

    return 0; //return值可根据需要修改
}

int tj_strchr(const char str[], char ch)
{
    int i=0;
    while(str[i]!='\0')
    {
        if (str[i]==ch)
            return i+1;
        i++;
    }
    return 0; //return值可根据需要修改
}

int tj_strstr(const char str[], const char substr[])
{
    int i=0;
    int j=0;
    int k;
    while(str[i]!='\0')
    {
        k=i;
        while(str[i]==substr[j])
        {
            i++;
            j++;
            if(substr[j]=='\0')
                return k+1;
            if(str[i]=='\0')
                return 0;
        }
        j=0;
        i++;
    }
    return 0; //return值可根据需要修改
}

int tj_strrchr(const char str[], const char ch)
{
    int len=tj_strlen(str);
    int i=len;
    while(i!=-1)
    {
        if (str[i]==ch)
            return i+1;
        i--;
    }
    return 0; //return值可根据需要修改
}

int tj_strrstr(const char str[], const char substr[])
{

    int len1=tj_strlen(str);
    int len2=tj_strlen(substr);
    int i=len1-1;
    int j=0;
    int k;
    while(i!=-1)
    {
        k=i;
        while(str[i]==substr[j])
        {
            i++;
            j++;
            if(substr[j]=='\0')
                return k+1;
            if(str[i]=='\0')
                break;
        }
        i=k;
        j=0;
        i--;
    }
    return 0; //return值可根据需要修改
}

int tj_strrev(char str[])
{
    int i=0;
    int j;
    char temp;
    while (str[i]!='\0')
    {
        i++;
    }
    j=i-1;
    for (j=i-1;j>=i/2;--j)
    {
        temp=str[j];
        str[j]=str[i-1-j];
        str[i-1-j]=temp;
    }
    return 0; //return值可根据需要修改
}
