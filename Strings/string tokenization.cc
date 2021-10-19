#include<iostream>
#include<vector>
#include<sstream> // for stringstream
#include<cstring> // for strtok 
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
    cout<<"Now using strtok"<<endl;
    // strtok only works with character array, so we will inout in the character array.
    char inpt[10000];
    cin.getline(inpt,10000);
    
    cout<<strtok(inpt," ")<<endl; // This will always start feom the firstr of the string and print the first word

    // To use strtok for all words in the sentense we need pass NULL everytime as
    cout<<"Using strtok for multiple words"<<endl;
    // strtok internally stores the state of the function that is passed by making a static variable.
    //cout<<strtok(inpt," ")<<endl;
    cout<<strtok(NULL," ")<<endl;
    cout<<strtok(NULL," ")<<endl;
    cout<<strtok(NULL," ")<<endl;
    cout<<strtok(NULL," ")<<endl;

    // Implimnting using while loop
    char inp[10000];
    cin.getline(inp,10000);

    char *tkn = strtok(inp," ");
    
    while(tkn!=NULL)
    {
        cout<<tkn<<endl;
        tkn = strtok(NULL," ");
    }

    return 0;
}