
#include <bits/stdc++.h>

using namespace std;

void printT(vector<int> T){
    for(auto x:T)
        cout << x << " ";
    cout << endl;
}

vector<int> LIS(vector<int> &Arr){
    vector<int> T(Arr.size(),1); // default length of subsequence with one char is 1  
    for(int i=1; i<Arr.size(); ++i){
        for(int j=0; j<i; ++j){
            if(Arr[j] < Arr[i])
                T[i] = max(T[i],T[j]+1);
        }    
    }
    return T;
}

int bitonicSequence(vector<int> A){
    
    // LIS from left to right
    vector<int> T1(LIS(A)); 
    
    
    // LIS from right to left
    reverse(A.begin(),A.end());
    vector<int> T2(LIS(A));
    reverse(T2.begin(), T2.end());
    
    // sum of LIS from both direction - 1
    vector<int> T3(A.size(),0);
    
    for(int i=0; i<A.size(); ++i)
        T3[i] = T1[i] + T2[i] - 1;
        
    printT(T1);
    printT(T2);
    printT(T3);
    return *max_element(T3.begin(),T3.end());
}


int main()
{
    vector<int> A = {2,-1,4,3,5,-1,3,2};
    cout << bitonicSequence(A) << endl;
    return 0;
}
