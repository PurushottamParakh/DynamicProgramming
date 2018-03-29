
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#define unsigned int uint

using namespace std;

int LPS(const string &input){
    vector< vector<int> > T(input.length(), vector<int>(input.length(), 0));
    
    for(uint i=0; i<input.length(); ++i)
        T[i][i] = 1;
        
    for(uint l=2; l<=input.length(); ++l){
        for(uint i=0; i<input.length(); ++i){
            uint j = i+l-1;
            if(j<input.length()){
                if(input[i] == input[j])
                    T[i][j] = T[i+1][j-1] + 2;
                else
                    T[i][j] = max(T[i+1][j],T[i][j-1]);
            }
        }
    }
    
    return T[0][input.length()-1];
}


int main(){
    string input("agbdba");
    cout << LPS(input) <<endl;
    return 0;
}
