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


int EggDropping(int eggs, int floors){
    
    vector< vector<int> > T(eggs+1, vector<int>(floors+1,0));
    
    for(int j=1; j<=floors; ++j)
        T[1][j] = j;
     
    for(int i=2; i<=eggs; ++i){
        for(int j=1; j<=floors; ++j){
            if(i>j){
                T[i][j] = T[i-1][j];
            }
            else{
                int min_steps = INT_MAX;
                for(int k=1; k<=j; ++k){
                    int max_steps_k = 1 + max(T[i-1][k-1],T[i][j-k]);
                    min_steps = min_steps > max_steps_k ? max_steps_k : min_steps;
                }
                T[i][j] = min_steps;
            }  
        }
    }
    
    printT(T);
    return T[eggs][floors];
}



int main()
{
  int eggs,floors;
  eggs = 2;
  floors = 6; 
  cout << EggDropping(eggs,floors) << endl;
  return 0;
}
