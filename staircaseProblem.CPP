
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int noOfStaircaseWays(int N){
    vector<int> F(N+1);
    F[0]=1;
    F[1]=1;
    F[2]=2;
    
    for(int i=3; i<=N; ++i){
        F[i] = F[i-1]+F[i-2]; // if the number of steps is more + F[i-3] + F[i-4] etc
    }
    return F[N];
}

int main()
{
    int N=5; 
    cout << noOfStaircaseWays(N) <<endl;
    return 0;
}
