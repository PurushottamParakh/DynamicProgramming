#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int LIS(vector<int> &Arr){
    vector<int> T(Arr.size(),1); // default length of subsequence with one char is 1  
    for(int i=1; i<Arr.size(); ++i){
        for(int j=0; j<i; ++j){
            if(Arr[j] < Arr[i])
                T[i] = max(T[i],T[j]+1);
        }    
    }
    return T[Arr.size()-1];
}

int main(){
    vector<int> Arr = {3, 4, -1, 0, 6, 2, 3};
    cout << LIS(Arr) << endl;
    return 0;
}
