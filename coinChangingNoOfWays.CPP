#include <bits/stdc++.h>

using namespace std;
long getWays(vector<int> &coins, int total){
    vector< vector<long> > T(coins.size()+1, vector<long>(total+1,0));
    
    for(int i=0; i<=coins.size();++i)
        T[i][0]=1;
        
    for(int i=1; i<=coins.size(); ++i){
        for(int j=1; j<=total; ++j){
            if(coins[i-1] > j)
                T[i][j] = T[i-1][j];
            else
                T[i][j] = T[i-1][j] + T[i][j-coins[i-1]];
        }    
    }
    return T[coins.size()][total];
}



int main() {
    int total;
    int m;
    cin >> total >> m;
    vector<int> coins(m);
    for(int c_i = 0; c_i < m; c_i++){
        int inp;
        cin >> inp;
        coins[c_i] = inp;
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    cout << getWays(coins, total) << endl;
    
    return 0;
}
