
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;


int optCost(vector<int> &freq, int i, int j){
    
    if(j<i)
        return 0;
        
    if(i==j)
        return freq[i];
        
    int fsum = 0;
    for(int k=i; k<=j; ++k)
        fsum += freq[k];
        
    int min = INT_MAX;
    for(int r = i; r<=j; ++r){
        int cost = optCost(freq, i, r-1) + optCost(freq, r+1,j);
        if(cost < min)
            min = cost;
    }
    return fsum+min;
}


int optimalSearchTree(vector<int> keys, vector<int> freq){

    return optCost(freq,0,freq.size() - 1);    
}


int main(){
    
    vector<int> keys = {10, 12, 16, 21};
    vector<int> freq = {4, 2, 6, 3};
    
    cout << optimalSearchTree(keys,freq) << endl;
    
    return 0;    
}
