#include<iostream>
#include<vector>

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
    vector<int> ans = 3sumBF(a,ta);
    for(auto j:ans)
    {
        for(auto k:j )
        {
            cout<<k<<" "
        }
        cout<<endl;
    }
    // Binary Search Optimized
    ans = 3sum(a,ta);
    for(auto j:ans)
        cout<<j<<" ";
    cout<<endl;
    // Optimized using Hash map
    ans = twoSumOPT(a,ta);
    for(auto j:ans)
        cout<<j<<" ";
    cout<<endl;
    //Leetcode submitted code
    ans = twoSum(a,ta);
    for(auto j:ans)
        cout<<j<<" ";
    cout<<endl;
    return 0;
}