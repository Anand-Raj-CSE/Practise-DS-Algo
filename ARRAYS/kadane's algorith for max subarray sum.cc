#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int Kadanes_nonNegative(vector<int>& a) {
        int n = a.size();
        int max_so_far = INT_MIN;
        int max_till_here = 0;
        for(int i=0;i<n;i++)
        {
            max_till_here += a[i];
            if(max_till_here > max_so_far)
            {
                max_so_far = max_till_here;
            }
            // This approach will not work with all negative number array.But surpurisingly it worked.
            if(max_till_here < 0)
            {
                max_till_here = 0;
            }
        }
    return max_so_far;
}


int Kadanes(vector<int> &a)
{
    int n = a.size();
        int max_so_far = a[0];
        int max_till_here = a[0];
        for(int i=1;i<n;i++)
        {
            max_till_here = max(a[i],max_till_here+a[i]);
            max_so_far = max(max_so_far,max_till_here);
        }
    return max_so_far;

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
    cout<<Kadanes_nonNegative(a)<<endl;
    cout<<Kadanes(a)<<endl;

    return 0;
}