#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Function to print the indices where small string is found in the big string
vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    int idx = big.find(small);
    while(idx!= -1)
    {
        result.push_back(idx);
        idx = big.find(small,idx+1);
    }
    return result;

}


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