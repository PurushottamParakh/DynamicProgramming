
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int minCoin(vector<int> &coins, int total, unordered_map<int,int> &M){
    
    if(total == 0){
        return 0;    
    }
    
    if(M.count(total))
        return M[total];
    
    int min = INT_MAX;
    for(int i=0; i<coins.size(); ++i){
        if(coins[i]>total)
            continue;
            
        int val = minCoin(coins,total-coins[i],M);
        
        if(val < min)
            min = val;
    }
        
    min = (min == INT_MAX)? min: min+1;
    M[total] = min;
    return min;
}


int main()
{
    int N=5; 
    vector<int> coins = {1,2,3};
    unordered_map<int,int> M;
    cout << minCoin(coins,N,M) <<endl;
    return 0;
}
