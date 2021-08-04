//https://leetcode.com/problems/add-strings/
#include<iostream>
#include<string>

using namespace std;

string addStrings(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        cout<<n1<<" "<<n2<<endl;
        int carry = 0;
        string ans="";
        int i = n1-1,j=n2-1;
        while(i>=0 && j>=0)
        {
            int a = (num1[i]-'0')+(num2[j]-'0')+carry;
            cout<<a<<" ";
            if(a>=10)
            {
                carry=1;
             ans=to_string(a%10)+ans;
            }
            else
            {
                ans=to_string(a)+ans;
                carry = 0;
            }
            i--;j--;
        }
        if(i>=0)
        {
            while(i>=0)
            {
                int a = (num1[i]-'0')+carry;
                cout<<a<<" ";
                if(a>=10)
                {
                carry=1;
                ans=to_string(a%10)+ans;
                }
                else
                {
                ans=to_string(a)+ans;
                carry = 0;
                }
                i--;
            }
        }
        if(j>=0)
        {
            while(j>=0)
            {
                int a = (num2[j]-'0')+carry;
                cout<<a<<" ";
                if(a>=10)
                {
                carry=1;
                ans=to_string(a%10)+ans;
                }
                else
                {
                ans=to_string(a)+ans;
                carry = 0;
                }
                j--;
            }
        }
        if(carry)
        {
         ans = to_string(carry)+ans;
            carry=0;
        }
        
        return ans;
    }


int main()
{
    string num1,num2;
    cin>>num1>>num2;
    cout<<addStrings(num1,num2)<<endl;
    return 0;
}