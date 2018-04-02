
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void printT(vector<vector<int>> T){
    for(auto x:T){
        for(auto y:x)
            cout << y <<" ";
        cout << endl;
    }
}


int subsquareMatrix(vector<vector<int>> &A){
    vector<vector<int>> T(A.size()+1,vector<int>(A[0].size()+1,0));
    for(int i=1; i<=A.size();++i){
        for(int j=1; j<=A[0].size(); ++j){
            if(A[i-1][j-1]){
                T[i][j] = A[i-1][j-1] + min(T[i-1][j], min(T[i-1][j-1],T[i][j-1]));    
            }   
        }
    }
    
    printT(T);
    
    int max = 0;
    for(auto x: T){
        int y = *max_element(x.begin(),x.end());
        max = (y>max)?y:max;
    }
    return max;
}


int main()
{
    vector<vector<int>> A = {{0,0,1,1,1},{1,0,1,1,1},{0,1,1,1,1},{1,0,1,1,1}};
    cout << subsquareMatrix(A) << endl;
    return 0;
}
