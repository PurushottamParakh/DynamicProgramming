// Example program
// Example program
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;


int getSum(vector<int> arr, int i, int j){
    int sum = 0;
    for(int k=i; k<=j; ++k)
        sum += arr[k];
    return sum;
}

int optCostDP(vector<int> &keys, vector<int> &freq){
    int n = freq.size();
    vector< vector<int> > T(n, vector<int>(n,0));
    
    for(int i=0; i<n; ++i)
        T[i][i]=freq[i];
            
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << T[i][j] << " ";    
        }    
        cout << endl;
    }
    
    cout << "the matrix now is" << endl;
    
    for(int l=2; l<=n; ++l){
        for(int i=0; i<=n-1; ++i){
            int j = i+l-1;
            if(j >= n)
                continue;
            T[i][j] = INT_MAX;
            int sum = getSum(freq,i,j);
            
            for(int k=i; k<=j; ++k){
                int val = sum + (k-1 < i ? 0 : T[i][k-1]) + (k+1>j? 0 : T[k+1][j]);
                if(val < T[i][j])
                    T[i][j] = val;                    
            }
        }
    }
        
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << T[i][j] << " ";    
        }    
        cout << endl;
    }
    return T[0][n-1];
}



int main(){
    
    vector<int> keys = {10, 12, 16, 21};
    vector<int> freq = {4, 2, 6, 3};
    
    cout << optCostDP(keys,freq) << endl;
    
    return 0;    
}
