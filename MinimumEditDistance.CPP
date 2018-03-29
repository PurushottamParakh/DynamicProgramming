#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int MED(string str1, string str2){
    vector< vector<int> > T(str2.length()+1, vector<int>(str1.length()+1,0));
    
    for(unsigned int i=0; i<=str2.length(); ++i)
        T[i][0] = i;
        
    for(unsigned int j=0; j<=str1.length(); ++j)
        T[0][j] = j;

    for(unsigned int i=1; i<=str2.length(); ++i){
        for(unsigned int j=1; j<=str1.length(); ++j){
            if(str2[i-1] == str1[j-1])
                T[i][j] = T[i-1][j-1];
            else
                T[i][j] = min(T[i-1][j-1], min(T[i-1][j],T[i][j-1])) + 1;
        }    
    }
    
    for(unsigned int i=0; i<=str2.length(); ++i){
        for(unsigned int j=0; j<=str1.length();++j){
            cout << T[i][j] << " ";    
        }    
        cout << endl;
    }
    
    return T[str2.length()][str1.length()];    
}

int main(){
    string str1("abcdef");
    string str2("azced");
    cout << MED(str1,str2) <<endl;
    return 0;
}
