
#include <bits/stdc++.h>

using namespace std;

int noOfNoWithoutConsectiveOnes(int n){
    vector<int> T(n+1);
    T[0] = 0;
    //n=1 : 0,1
    //n=2 : 00,01,10,11 : 3
    T[1] = 2;
    T[2]=3;
    
    // we either append 0 or 1 to the number to get the next set of binary representation for n+1, 0 does not change anything, and only numbers for prior to prior of n+1
    // which starts from 0 can have 1 appended on front.
    for(int i=3; i<=n; ++i){
        T[i] = T[i-1] + T[i-2];    
    }
    return T[n];
}


int main()
{
   cout << noOfNoWithoutConsectiveOnes(5) <<endl;
    return 0;
}
