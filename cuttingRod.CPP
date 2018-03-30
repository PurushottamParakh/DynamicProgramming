#include <iostream>
#include <string>
#include <vector>
#define unsigned int uint
using namespace std;

void printT(vector< vector<int> > &T){
    for(uint i=0; i< T.size(); ++i){
        for(uint j=0; j<T[0].size(); ++j){
            cout << T[i][j] << " ";
        }    
        cout<< endl;
    }
}


int cuttingRod(vector<int> &val, int &length){
    vector< vector<int> > T(val.size() + 1, vector<int>(length + 1, 0));
    
    for(uint i=1; i<=val.size(); ++i){
        for(uint j=1; j<=(uint)length; ++j){
            if(j>=i){
                T[i][j] = max(T[i-1][j], T[i][j-i] + val[i-1]);     
            }
            else{
                T[i][j] = T[i-1][j];    
            }
        }  
    }
    printT(T);
    return T[val.size()][length];
}

int main()
{
  vector<int> val  = {2,5,7,8};
  int length = 5;
  cout << cuttingRod(val,length) << endl;
  return 0;
}
