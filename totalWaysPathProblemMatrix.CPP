
#include <bits/stdc++.h>

using namespace std;

int totalNoWays(int n, int m){
    vector<vector<int>> T(n,vector<int>(m,0));
    for(int j=0; j<m; ++j)
        T[0][j] = 1;
        
    for(int i=0; i<n; ++i)
        T[i][0] = 1;
        
    for(int i=1; i<n; ++i){
        for(int j=1; j<m; ++j){
            T[i][j] = T[i-1][j] + T[i][j-1];    
        }    
    }
    return T[n-1][m-1];
}


int main()
{
   cout << totalNoWays(4,4) <<endl;
   return 0;
}
