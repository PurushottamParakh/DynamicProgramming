
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class pairp{
    public:
    int first;
    int second;
    int pick = 0;
    pairp(int x, int y, int z):first(x),second(y),pick(z){}
    
    string toString(){
        return to_string(first) +" "+ to_string(second) +" "+ to_string(pick);    
    }
};


void printSequence(vector<int> &A, vector<vector<pairp>> &T){
        int i = 0;
        int j = A.size() - 1;
        int step;
        for (int k = 0; k < A.size(); k++) {
            
            cout << "i = "<<i <<", j="<<j <<" ";
            step = T[i][j].pick;
            //this is the value of pick and its index
            cout << "value: " << to_string(A[step]) << " " << "index: " << to_string(step) << " "<<endl;
            if (step <= i) {
                i = i + 1;
            } else {
                j = j - 1;
            }
            
        }
    }

pairp optimalStrategy(vector<int> A){
    
    vector<vector<pairp>> T(A.size(),vector<pairp>(A.size(),pairp(0,0,0)));
    
    for(int i=0; i<A.size(); ++i){
        T[i][i].first = A[i];
        T[i][i].pick= i;
    }
    
    for(int i=0; i<A.size(); ++i){
        for(int j=0;j<A.size();++j){
            cout << "("<<T[i][j].first << ","<<T[i][j].second<<") ";    
        }    
        cout << endl;
    }
    
    for(int l=2; l<=A.size();++l){
        for(int i=0; i<A.size(); ++i){
            int j = i+l-1;
            if(j<A.size() && i+1<A.size()){
                if(A[i] + T[i+1][j].second > T[i][j-1].second + A[j]){
                    T[i][j].first =  A[i] + T[i+1][j].second;
                    T[i][j].second = T[i+1][j].first;
                    T[i][j].pick = i;
                }
                else{
                    T[i][j].first = T[i][j-1].second + A[j];
                    T[i][j].second = T[i][j-1].first;
                    T[i][j].pick = j;
                    
                }
            }
        }    
    }
    
    cout << endl;
    for(int i=0; i<A.size(); ++i){
        for(int j=0;j<A.size();++j){
            cout << "("<<T[i][j].first << ","<<T[i][j].second<<","<< T[i][j].pick<<") ";    
        }    
        cout << endl;
    }
    printSequence(A,T);
    return T[0][A.size()-1];
}


int main()
{
    vector<int> coins = {3,9,1,2};
    
    pairp p = optimalStrategy(coins);
    cout << p.toString() << endl;
}
