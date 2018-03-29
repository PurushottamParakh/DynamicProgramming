// Example program
// Example program
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int minimumCoinBottomUp(const vector<int> &coins, int total, vector<int> &R){
    vector<int> T(total+1,INT_MAX-1); // INT_MAX - 1 is very important because of comparison T[i] > 1 + T[ i-coins[j] ], 1 + INT_MAX = INT_MIN
    T[0] = 0;
    
    //T[i] = number of coins required to get i
    //R[i] = last coin needed to get T[i]
    
    for(int j=0; j<coins.size(); ++j){
        for(int i=0; i<=total; ++i){
            if(i>=coins[j]){
                if(T[i] > 1 + T[ i-coins[j] ]){
                    T[i] = 1 + T[ i-coins[j] ];
                    R[i] = j;
                }    
            }
        }   
    }  
   return T[total]; 
}


void printCoinCombination(vector<int>& R, vector<int>& coins,int total){
    if(R[total] == -1){
        cout << "no solution is possible" << endl;
        return;
    }
    
    cout << "{ ";
    while(total!=0){
        cout << coins[R[total]] << ", ";
        total = total-coins[R[total]];
    }    
    cout << "}" << endl;
}

int main(){
    
    vector<int> coins = {7,2,3,6};
    int total = 13;
    
    vector<int> R(total+1, -1);
    cout << minimumCoinBottomUp(coins,total,R) << endl;
    
    printCoinCombination(R,coins,total);
    
    return 0;    
}
