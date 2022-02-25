#include<bits/stdc++.h>
using namespace std;


// Trying a new class implimentation of same code in more otimized way as the above solution has the complexity of O(n*k)
//  Trying this solution in O(n)

class AvgSum
{
    public :
	// Its necessary to make a function static to make it called without object
    static vector<double> AngSumFun(int k , vector<int> a)
    {
        vector<double> ans;
        int n = a.size();
        double sum = 0;
        int windowstart = 0;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            if(i >= k-1)
            {
                ans.push_back(sum/5);
                sum -= a[windowstart];
                windowstart++; 
            }
        }
        return ans;
    }
};



int main()
{
    int k;cin>>k;
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
    cout<<endl;
    // Above solution was a bruteforce solution of O(n*k) complexity but designed a class which has a complexity of O(n) , trying directly to call that class
    vector<double> res = AvgSum::AngSumFun(k,a);

    for(double i : res)
    {
        cout<<i<<",";
    }

    return 0; 
}



