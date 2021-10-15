#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

// We can use string stream class in c++ for tokenization


int main()
{
    string input;
    getline(cin,input);

    // Create a string stream object
    stringstream ss(input);
    // << and >> are overloaded for the object which allow us to read and write characters in the string
    string token;
    vector<string> tokens;
    while(getline(ss,token,' '))  // We give deliminator as space
    {
        tokens.push_back(token);
    }

    for (auto token:tokens)
    {
        cout<<token<<" ";
    }
    cout<<endl;
    return 0;
}