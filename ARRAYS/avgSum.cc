#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i = 0;i<n;i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    int sp=0,ep=4;
    vector<float> ans;
    int temp=sp;
    float sum = 0;


    while(ep<n)
    {
        if(temp == ep && ep<n && sp<sp+4)
        {
            ep++;
            sp++;
            temp = sp;
            ans.push_back(sum/5);
            sum=0;
        }
        else
        {
            sum+=a[temp++];
        }
    }
	int n2=ans.size();
	for(int i=0;i<n2;i++)
	cout<<ans[i]<<",";
    return 0; 
}