#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Heap
{
    vector<int> v;
    bool minheap;
    
    bool Cmp(int a,int b)
    {
        if(minheap){
            return a<b;
        }
        else
        return a>b;
    }
    
    void Heapify(int i)
    {
        int left = 2*i+1;
        int right = 2*i+2;

        int min_i = i;
        int n = v.size();
        if(left<n && Cmp(v[right],v[i]))
        {
            min_i = right;
        }
        if(right<n && Cmp(v[left],v[min_i]))
        {
            min_i = left;
        }
        if(i != min_i)
        {
            swap(v[i],v[min_i]);
            Heapify(min_i);
        }
    } 

    public:

    // Constructor
    Heap(int ds = 100 , bool flag = true)
    {
        minheap = flag;
        v.reserve(ds);
    }
     
    void push(int data)
    {
        v.push_back(data);
        int i =  v.size()-1;
        int p = floor((i-1)/2);
        while(i>1 && Cmp(v[i],v[p]))
        {
            swap(v[i],v[p]);
            i=p;
            p=p/2;
        }
    }

    bool isEmpty()
    {
        return v.size()==0;
    }

    int front()
    {
        return v[0];
    }
    
    void pop()
    {
        //Swap 1st and last
        int last = v.size()-1;
        swap(v[0],v[last]);
        v.pop_back();

        Heapify(0);
    }
};