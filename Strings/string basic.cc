#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    // Input string till we encounter a .
    getline(cin,s,'.');
    cout<<s<<endl;

    //use of find function
    string word;
    cin>>word;
    int idx = s.find(word);
    if(idx!=-1)
    cout<<"found at : "<<idx;
    else
    cout<<"Not found"<<endl;
    return 0;
}