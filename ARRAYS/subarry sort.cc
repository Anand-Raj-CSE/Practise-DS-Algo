//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;


//Leet tried but cases failed
bool isOutOfOrder(vector<int> &a,int i,int &flag)
    {
        int x=a[i];
        if(i==0)
            return x>a[1];
        if(i==a.size()-1)
            return x<a[i-1];
        
        return x>a[i+1] || x<a[i-1];
        
        
    }
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int smallest = INT_MAX;
        int largest = INT_MIN;
        if(n==1)
            return 0;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(isOutOfOrder(nums,i,flag))
            {
                smallest = min(smallest,i);
                largest = max(largest,i);
            }
        }
        if(smallest==INT_MAX)
            return 0;
        return largest-smallest+1;
    }



// Sorting apparoach
pair<int,int> SortingSol(vector<int> a)
{
    int n= a.size();
    pair<int,int> p;
    vector<int> temp(a.begin(),a.end());
    sort(temp.begin(),temp.end());
    int i=0,j=n-1,flag1=0,flag2=0;
    while(i<=j)
    {
        if(a[i]!=temp[i])
        {
            p.first=i;flag1=1;
        }
        if(a[j]!=temp[j])
        {
            p.second=j;flag2=1;
        }
        if(flag1 & flag2)
        break;
        if(!flag1)
        i++;
        if(!flag2)
        j--;
    }
     return p;
}



bool outOfOrder(vector<int> a,int i)
{
    int x=a[i];
    if(i==0)
        return x>a[1];
    if(i==a.size()-1)
        return x<a[i-1];
    return x>a[i+1] || x<a[i-1];

}

//Optimized solution - O(n)
pair<int,int> Optimized(vector<int> a)
{
    int smallest=INT_MAX;
    int largest = INT_MIN;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        int x = a[i];
        if(outOfOrder(a,i))
        {
            smallest=min(smallest,x);
            largest=max(largest,x);
        }
    }
    // Now we have to find out the correct places for these elements
    if(smallest==INT_MAX)
        return {-1,-1};

    int left=0;
    while (smallest >= a[left])
    {
        left++;
    }
    int right = n-1;
    while(largest <= a[right])
    {
        right--;
    }
    return {left,right};
    
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
    // We want to know that which part of the array must be sorted so that we know after their sorting our whole array would be sorted.
    // We would use sorting for this taking NogN time.
    pair<int,int> ans = SortingSol(a);
    cout<<"Sorting needed from : "<<ans.first<<" to : "<<ans.second<<endl;

    // Optimized solution - O(n) , just by iterating we would know that wheather a number is in correct sorted order or not
    ans = Optimized(a);
    cout<<"Sorting needed from : "<<ans.first<<" to : "<<ans.second<<endl;

    return 0;
}