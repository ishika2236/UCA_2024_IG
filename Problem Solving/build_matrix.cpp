// Link to the problem
// https://docs.google.com/document/d/1WYb0WbXYyE2pJJlvOgl5MagMzAgZd6MFh3N_TSZeRuk/edit?usp=sharing

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int colsum[n];
    int rowsum[m];
    for(int i=0;i<n;i++){
        cin>>colsum[i];
    }
    for(int i=0;i<m;i++){
        cin>>rowsum[i];
    }
    vector<vector<int>>result(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result[i][j]=min(rowsum[i],colsum[j]);
            rowsum[i]-=result[i][j];
            colsum[j]-=result[i][j];
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<result[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}
