//using binary search
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr){
    int left=0;
    int right=arr.size();
    while(left<right){
        int mid=(left+right)/2;
        if(arr[mid]>arr[mid+1]){
            right=mid;
        }
        else{
            
            left=mid+1;
        }
    }
    return left;
}

int main(){
    vector<int>arr;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    int ans= binarySearch(arr);
    cout<<ans;

}
