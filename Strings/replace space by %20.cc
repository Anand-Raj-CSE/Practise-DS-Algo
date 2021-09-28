#include<iostream>
#include<cstring>
using namespace std;

void Bruteforce(string &s)
{
    cout<<s<<endl;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ')
        {
            for(int j=n-1;j<i;j--)
            {
                s[j+3] = s[j];
            }
            s[i++]='%';
            s[i++]='2';
            s[i]='0';
        }
    }
}

void replace_space(char *str)
{
    // 1. Calculation of spaces
    int space = 0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        space++;
    }
    int idx = strlen(str)+2*space;
    str[idx]='\0';
    for(int i=strlen(str)-1;i>=0;i--)
    {
        if(str[i]==' ')
        {
            str[idx-1]='0';
            str[idx-2]='2';
            str[idx-3]='%';
            idx=idx-3;
        }
        else
        {
            str[idx-1]=str[i];
            idx--;
        }
    }

}

int main()
{
    string s;
    getline(cin,s);
    // This does not has extra space allocated
    Bruteforce(s);
    cout<<s<<endl;

    // Extra Space code using pointers
    char input[1000];
    cin.getline(input,1000);
    replace_space(input);
    cout<<input<<endl;
    return 0;
}

