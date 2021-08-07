#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> 3SumBF(vector<int>& nums,int tagrget) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            int flag = 0;
            for(int j = i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k] == tagrget)
                    {
                        v.push_back(i);
                        v.push_back(j);
                        v.push_back(k);
                        flag = 1;
                    }
                }
                
            }
            if(flag)
                ans.push_back(v);

        }

        return ans;
    }

vector<vector<int>> 3sumOPT(vector<int>& nums,int target) 
{
        vector<vector<int>> ans;
        int n = nums.size();
        // 1st we would sort the entire array
        sort(nums.begin(),nums.end());
        // Now pick every number and then solve pair sum problrm for every part
        // We would use two pointer approach as the array has been sorted
        for(int i=0;i<=n-3;i++)
        {
            int j = i+1;
            int k = n-1;
            // Two Pointer approach
            while(j<k)
            {
                int current_sum = nums[i];
                current_sum+=nums[j];
                current_sum+=nums[k];
                if(current_sum == target)
                {
                    // Better Way to push elements in 2d vector
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(current_sum > target)
                {
                    k--;
                }
                else
                j++;
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
    int ta;cin>>ta;
    // Brute Force
    vector<vector<int>> ans = 3sumBF(a,ta);
    for(auto j:ans)
    {
        for(auto k:j)
        {
            cout<<k<<" "
        }
        cout<<endl;
    }
    // Optimized one
    vector<vector<int>> ans = 3sumOPT(a,ta);
    for(auto j:ans)
    {
        for(auto k:j )
        {
            cout<<k<<" "
        }
        cout<<endl;
    }
    //Leetcode submitted code
    ans = 3sum(a,ta);
    for(auto j:ans)
        cout<<j<<" ";
    cout<<endl;
    return 0;
}