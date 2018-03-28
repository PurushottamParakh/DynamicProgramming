#include <iostream>
#include <string>
#include <vector>
using namespace std;


int knapsack(const vector<int> &val, const vector<int> &wt, const int &W){
    
    int rows = val.size();
    int cols = W + 1;
    
    vector<vector<int>> T (rows, vector<int>( cols , 0 ));
       
    for(int i=0; i<rows; ++i){
        for(int j=1; j< cols; ++j){
            // when considering item i of weight wt[i] and val[i] to fill the sack of capacity j
            // we have two option either pick up the item i or do not pick up
            // if you pick up the item, the sack is left with capacity : j-wt[i] and we already know how to fill it using earlier 0..(i-1) items.
            
            if(i==0){
                if(j>=wt[i])
                    T[0][j] = val[i]; 
                continue;    
            }
            
            if(i-1 >= 0 && j < wt[i])
                T[i][j] = T[i-1][j];
            else
                T[i][j] = max(val[i] + T[i-1][j-wt[i]] , T[i-1][j]);            
        }    
    }
    
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    
    return T[rows-1][cols-1]; 
}


int main()
{
    vector<int> val = {1,4,5,7};
    vector<int> wt = {1,3,4,5};
    int W = 7;
    
    cout << knapsack(val,wt,W) << endl;
    return 0;
  
}
