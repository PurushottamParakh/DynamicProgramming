
#include <bits/stdc++.h>

using namespace std;

int countBST(int n){
    vector<int> T(n+1,0);
    T[0] = 1;
    T[1] = 1;
    
    for(int i=2; i<=n; ++i){
        int sum = 0;
        for(int j=0; j<=(i-1); ++j){
                sum += T[j]*T[(i-1) - j]; // #(tree on left) * #(tree on right)
        }    
        T[i] = sum;
        cout << i << " = "<<T[i] << endl;
    }
    return T[n];
}


int main()
{
   cout << countBST(5) <<endl;
   return 0;
}
