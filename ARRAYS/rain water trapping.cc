 // https://leetcode.com/problems/trapping-rain-water/
 #include<iostream>
 #include<vector>

 using namespace std;

// leet submitted solution
int trap(vector<int>& height) {
         int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        int current_max = 0;
        for(int i=0;i<n;i++){
            if(height[i]>current_max){
                current_max = height[i];
            }
            left_max[i]=current_max-height[i];
        }
        current_max = 0;
        for(int i=n-1;i>=0;i--){
            if(height[i]>current_max){
                current_max = height[i];
            }
            right_max[i] =current_max-height[i];
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            int minimum = min(left_max[i],right_max[i]);
            sum+=minimum;
        }
        return sum;
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

    cout<<trap(a);
    return 0;
}