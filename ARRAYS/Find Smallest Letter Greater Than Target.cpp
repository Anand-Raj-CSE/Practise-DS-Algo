// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
        int minlen=INT_MAX;;
        int idx = 0;
            int n = letters.size();
            
            for(int i=0;i<n;i++)
            {
                int clen = letters[i]-target;
                if(clen>0 && clen<minlen)
                {
                    idx = i;
                    minlen = clen;
                }
            }
        
        return letters[idx];
    }

int main()
{
    int n;cin>>n;
    char t;
    vector<char> a;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
    }
    char target;cin>>target;
    cout<<nextGreatestLetter(a,target)<<endl;

    return 0;
}