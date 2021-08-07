#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSumBF(vector<int>& nums,int tagrget) {
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

vector<vector<int>> threeSumBF(vector<int>& nums,int tagrget) {
        vector<vector<int>> ans;
        int n = nums.size();
        // 1st we would sort the entire array
        sort(nums.begin(),nums.end());

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
    vector<int> ans = 3sumBF(a,ta);
    for(auto j:ans)
    {
        for(auto k:j)
        {
            cout<<k<<" "
        }
        cout<<endl;
    }
    // Optimized one
    vector<int> ans = 3sumOPT(a,ta);
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