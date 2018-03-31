#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#define unsigned int uint
using namespace std;

void printT(vector< vector<int> > &T){
    for(auto x:T){
        for(auto y:x)
            cout << y << " ";
        cout << endl;
    }    
}


int longestCommonSubstring(string &A, string &B){
    vector< vector<int> > T(B.length()+1, vector<int>(A.length()+1,0));
    for(uint i=1;i<=B.length(); ++i){
        for(uint j = 1; j<=A.length(); ++j){
            if(B[i-1] == A[j-1])
                T[i][j] = T[i-1][j-1] + 1;
        }    
    }
    
    printT(T);
    int longest=0;
    for(uint i=1;i<=B.length(); ++i){
        for(uint j = 1; j<=A.length(); ++j){
            if(longest < T[i][j])
                longest = T[i][j];
        }    
    }
    return longest;
}


int main()
{
  
  string str1 = "abcdaf";
  string str2 = "zbcdf";
  
  cout << longestCommonSubstring(str1,str2) << endl;
  
  return 0;
}
