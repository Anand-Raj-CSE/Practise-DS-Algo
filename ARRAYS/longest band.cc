// https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

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

    return 0;
}