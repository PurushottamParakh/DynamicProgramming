// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The theory is pretty simple. if str2[i] == str1[j], it should be included i.e. T[i-1][j-1]+1
// If they are not same, then we will take max of without considering str2[i] or str1[j]

int LCS(string &str1, string &str2){
    
    int m = str1.length();
    int n = str2.length();
    
    vector< vector<int> > T(n+1,vector<int>(m+1,0));
    
    for(int i = 1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(str2[i] == str1[j])
                T[i][j] = T[i-1][j-1] + 1;
            else
                T[i][j] = max(T[i-1][j],T[i][j-1]);
        }   
    }
    return T[n][m];
}


int main(){
    
    string str1("abcdaf");
    string str2("acbcf");
    
    cout << LCS(str1, str2) <<endl;
    
    return 0;    
}
