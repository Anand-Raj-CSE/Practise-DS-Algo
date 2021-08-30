

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


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
    pair<int,int> ans = SortingSol( a);
    cout<<"Sorting needed from : "<<ans.first<<" to : "<<ans.second<<endl;


    return 0;
}