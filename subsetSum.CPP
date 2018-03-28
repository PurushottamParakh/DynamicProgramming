// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printmat(vector<vector<bool>> &T){
    for(int i=0; i<T.size();++i){
        for(int j=0; j<T[0].size();++j)
            cout << T[i][j] << " ";
        cout << endl;
    }       
}


bool subsetSum(vector<int> &S, int N){

    int m = N;
    int n = S.size() ;
    
    vector< vector<bool> > T(n+1,vector<bool>(m+1,false));
    
    printmat(T);
    
    for(int i=0;i<=n;++i)
        T[i][0] = true;
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){    
            if (j - S[i - 1] >= 0)
                T[i][j] = T[i-1][j] || T[i-1][j-S[i-1]];
            else
                T[i][j] = T[i-1][j];
                
        }    
    }
    
    cout << "DP MATRIX : " << endl;
    printmat(T);
    
    return T[n][m];
}



int main(){
    
    vector<int> S = {2,3,7,8,10};
    int N = 11;
    
    cout << "answer: " << subsetSum(S,N) << endl;
    
    return 0;    
}
