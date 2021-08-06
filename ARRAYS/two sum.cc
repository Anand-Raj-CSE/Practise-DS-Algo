#include<iostream>
#include<vector>
#
using namespace std;

// Brute force - O(n2)
vector<int> twoSumbf(vector<int>& nums, int target) {
        vector<int> ans;        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }

// Little Optimized - O(NlogN)



// Optimized using Hashmap - O(N) - Looking up i.e Searching in a set is O(1) operation

vector<int> twoSumBS(vector<int>& nums, int target) {
        vector<int> ans;        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            // We would not first insert all the elements in the set as we cout get as 2+2=4 , if 4 is target.
            // This would give us wrong answer.So we would keep adding to set while iterating and finding.


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
    int ta;cin>>ta;
    vector<int> ans = twoSumbf(a,ta);
    for(auto j:ans)
        cout<<j<<" ";
    cout<<endl;
    // Binary Search Optimized
    ans = twoSumBS(a,ta);
    for(auto j:ans)
        cout<<j<<" ";
    cout<<endl;
    // Optimized using Hash map
    ans = twoSumOPT(a,ta);
    for(auto j:ans)
        cout<<j<<" ";
    cout<<endl;
    return 0;
}