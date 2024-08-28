#include <bits/stdc++.h>
using namespace std;

void help(int n, string source, string helper, string destination){
    if(n == 1)
    {
        cout << "moving "<<n<< " from "<< source <<" to "<< destination<<endl;
        return;
    }
    
    help(n-1, source, destination, helper);
    cout << "moving "<<n<< " from "<< source <<" to "<< destination<<endl;
    help(n-1,  helper,source, destination);
}


int main()
{

    int n;
    cin >> n;
    
    string A="A", B="B", C="C";
    help(n, A, B, C);

    return 0;
}
