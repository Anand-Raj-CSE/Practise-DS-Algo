// https://practice.geeksforgeeks.org/problems/minimum-swaps/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int MinimumSwaps(vector<int> a)
{
    int ans=0;
    int n = a.size();
    // Know the actual positions of elements (sorting)
    // We would also store the current indices
    pair<int,int> ap[n];
    for(int i=0;i<n;i++)
    {
        ap[i].first=a[i];
        ap[i].second=i;
    }
    // Sorting
    sort(ap,ap+n);
    
    // Building main logic
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        // if element is visited or element is in the right position
        int old_position = ap[i].second;
        if(visited[i] == true or old_position == i)
        {
            continue;
        }
        //visiting the element or index for first time
        int node = i;
        int cycle = 0;
        while(!visited[node])
        {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle+=1;
        }
        ans+=(cycle-1);
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
    // how many swaps do we need to make our input array sorted
    cout<<MinimumSwaps(a)<<endl;



    return 0;
}