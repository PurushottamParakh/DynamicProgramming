// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void printT(vector<int> T){
    for(auto x:T)
        cout << x << " ";
    cout << endl;
}

int maxSumIncSubSeq(vector<int> &A){
    vector<int> T(A);
    vector<int> I(A.size(),0);
    for(int i=0; i<A.size(); ++i)
        I[i] = i;
        
    for(int i=0; i<A.size(); ++i){
        for(int j=0; j<i; ++j){
            if(A[j]<A[i] && T[j]+A[i] > T[i]){
                    T[i] = T[j] + A[i];
                    I[i] = j;
            }    
        }    
    }
    
    // core logic ends here------
    
    cout << "T = ";
    printT(T);
    cout << "I = ";
    printT(I);
    
    int max = *max_element(T.begin(),T.end());
    int max_index = -1;
    for(int i=0; i<T.size(); ++i)
        if(T[i]==max){
            max_index = i;
            break;
        }
    
    vector<int> subseq;
    while(max){
        subseq.push_back(A[max_index]);
        max -= A[max_index];
        max_index = I[max_index];
    }    
    cout << "subseq = ";
    printT(subseq);
    
    return *max_element(T.begin(),T.end());
}


int main()
{
    vector<int> A = {4,6,1,3,8,4,6};
    cout << maxSumIncSubSeq(A)<<endl;
    return 0;
}
