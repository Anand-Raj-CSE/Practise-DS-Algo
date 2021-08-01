#include<iostream>
#include<vector>
using namespace std;

int Max_SubArray_BF(vector<int> &a,int n)
{
    int ans = 0;
    int left,right;
    left = right = -1;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int csum = 0;
            for(int k=i;k<=j;k++)
            {
                csum+=a[k];
                left = i;
                right = j;
            }
            ans = max(ans,csum);
        }
    }
    cout<<"Maximum sum subarray sum lies between indices : "<<left<<" and "<<right<<endl;
    return ans;
}

void Cummulative_sum_Array(vector<int> &a,int n)
{
    int csum[1000] = {0};
    csum[0] = a[0];
    for(int i=1;i<n;i++)
    {
        csum[i] = csum[i-1]+a[i];
    }
    int ans = 0,left = -1,right = -1;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int currentsum = 0;
            currentsum = csum[j] - csum[i-1];
            if(currentsum>ans)
            {
                ans = currentsum;
                left = i;
                right= j;
            }
        }
    }
    cout<<"Maximum Subarray sum is : "<<ans<<" and the Subarray is : "<<endl;
    for(int i=left;i<=right;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
    // Brute Force O(n^3)
    cout<<"Brute Force :"<<Max_SubArray_BF(a,n)<<endl;
    // Using cummulative sum array O(n^2)
    Cummulative_sum_Array(a,n);

    return 0;
}