//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<iostream>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) 
{
        vector<int> ans;
        int s=0,e = nums.size()-1;
        int key = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] == target)
            {
                key = mid;
                e = mid-1;
            }
            else if(nums[mid]<target)
            s=mid+1;
            else if(nums[mid]>target)
            e = mid-1;
        }
        ans.push_back(key);
        key = -1,s=0,e=nums.size()-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] == target)
            {
                key = mid;
                s = mid+1;
            }
            else if(nums[mid]<target)
            s=mid+1;
            else if(nums[mid]>target)
            e = mid-1;
        }
        ans.push_back(key);
        return ans;
}

int main()
{
    int n;cin>>n;
    vector<int> a;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
    }
    int target;cin>>target;
    vector<int> ans = searchRange(a,target);
    for(int i=0;i<=1;i++)
    cout<<ans[i]<<" ";
    return 0;
}