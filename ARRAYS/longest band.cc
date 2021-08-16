// https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;



//nlogn solution using sorting
int LongestSubsequenceSorting(vector<int> &a)
{
    int ans=INT_MIN;
    sort(a.begin(),a.end());
    int clen = 1,start=0,end=0;;
    int n = a.size();
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]==a[i]+1)
        {
            clen++;
            
        }
        else
        {
            ans = max(clen,ans);
            clen=1;
        }
    }
    return ans;
}

// O(n) using unordred set
int LongestSubsequenceOPT(vector<int> a)
{
    // we would store all the elements in an unordered map.
    unordered_set<int> s;
    // Inserting elements in the set
    for(auto x : a)
    {
        s.insert(x);
    }
    int ans = INT_MIN;
    // Now iterating over the array
    for(auto element:s)
    {
        int parent = element-1;
        // If parent exists then we will ignore the element
        if(s.find(parent)==s.end())
        {
            int next=element+1;
            int cnt=1;
            while (s.find(next) != s.end())
            {
                next++;
                cnt++;
            }
            if(cnt>ans)
            ans=cnt;
            
        }
    }
    return ans;

}




int main()
{
    int n;
    cin>>n;
    vector<int> a;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        a.push_back(t);
    }
    // We have to find out the largest subsequence of array which has consecuive numbers.
    // We can do sorting and then iterate over the sorted array and find the argest band 
    cout<<LongestSubsequenceSorting(a);
    // Now the optimized one using unordered_set
    cout<<LongestSubsequenceOPT(a);
    return 0;
}