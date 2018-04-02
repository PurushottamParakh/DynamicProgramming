
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void printT(vector<vector<bool>> &T){
    for(auto x: T){
        for(auto y:x){
            cout << y << " ";    
        }    
        cout << endl;
    }
    
}

bool ifIntervleave(string str1,string str2, string str3){
    vector<vector<bool>> T(str2.length()+1, vector<bool>(str1.length()+1,false));
    
    T[0][0] = true;
    for(int j=1; j<=str1.length(); ++j)
        if(str3[j-1] == str1[j-1])
            T[0][j] = true;
            
    for(int i=1; i<=str2.length(); ++i)
        if(str3[i-1] == str2[i-1])
            T[i][0] = true;
            
    printT(T);        
    cout <<endl;
    
    for(int i=1; i<=str2.length(); ++i){
        for(int j=1; j<=str1.length(); ++j){
            if(str3[i+j-1] == str2[i-1]){
                T[i][j] = T[i-1][j];
            }
            else if(str3[i+j-1]==str1[j-1]){
                T[i][j] = T[i][j-1];
            }
            else{
                T[i][j] = false;
            }    
        }    
    }
    
    printT(T);
    return T[str2.length()][str1.length()];
}



int main(){
    string str1("aab"),str2("axy");
    string str3("aaxaby");
    cout << ifIntervleave(str1, str2, str3) <<endl;
    return 0;
}
