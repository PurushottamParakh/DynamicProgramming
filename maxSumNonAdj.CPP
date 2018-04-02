
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int maxSumNonAdj(vector<int> &A){
    int incl=0, excl = 0;
    for(auto a:A){
        int old_incl = incl;
        int old_excl = excl;
        
        incl = max(old_excl + a, old_incl);
        excl = old_incl;
        
    }
    return incl;
}


int main()
{
    vector<int> A = {4,1,1,4,2,1};
    cout << maxSumNonAdj(A) << endl;
    return 0;
}
