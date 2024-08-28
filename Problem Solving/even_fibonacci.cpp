#include <bits/stdc++.h>
using namespace std;

int generate_fib(int n, vector<int>& fib, int target, int &sum){
    if(n < 2){
        fib.push_back(1);
    }
    else{
        int ele = fib[n-1] + fib[n-2];
        if(ele < target)
        {
            fib.push_back(ele);
            if(ele %2 ==0)sum+=ele;
        }
        else return 0;
    }
    return generate_fib(n+1, fib, target, sum);
}

int main()
{
    int  target;
    cin >>target;
    vector<int>fib;
    int sum = 0;
    int ans = generate_fib(0, fib, target, sum);
    cout << sum;
    return 0;
}
