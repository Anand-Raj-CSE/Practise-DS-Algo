#include<iostream>
#include<vector>
#include<unordered_set>
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
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                }
            }
        }
        return ans;
    }

// Little Optimized - O(NlogN)

vector<int> twoSumBS(vector<int>& nums, int target) {
        vector<int> ans;        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int f = target-nums[i];
            int s=0,e=n-1;
            while (s<=e)
            {
                int mid = s+(e-s)/2;
                if(nums[mid] == f)
                {
                    ans.push_back(nums[i]);
                    ans.push_back(nums[mid]);
                }
                else if(nums[mid]<f)
                s=mid+1;
                else
                e=mid-1;
            }
            
        }
        return ans;
    }

// Optimized using Hashmap - O(N) - Looking up i.e Searching in a set is O(1) operation

vector<int> twoSumOPT(vector<int>& nums, int target) {
        vector<int> ans;        
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            // We would not first insert all the elements in the set as we cout get as 2+2=4 , if 4 is target.
            // This would give us wrong answer.So we would keep adding to set while iterating and finding.
            int f = target-nums[i];
            if(s.find(f)!=s.end())
            {
                ans.push_back(f);
                ans.push_back(nums[i]);
            }
            // Now if not found then insert
            s.insert(nums[i]);
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