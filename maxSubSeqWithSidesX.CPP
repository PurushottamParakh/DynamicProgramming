// Example program
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct cell {
     int a;
     int b; 
  };


void printT(vector<vector<cell>> &T){
    for(auto x: T){
        for(auto y:x){
            cout << "(" << y.a << ","<<y.b << ")" << " ";
        }
        cout << endl;
    }
}


int maxSubSquareX(vector<vector<char>> &A){
    
    vector<vector<cell>> T(A.size(),vector<cell>(A[0].size()));
    
    for(int i=0; i<A.size();++i){
        for(int j=0; j<A[0].size(); ++j){
            if(A[i][j] == 'O'){
               cell c; c.a = 0; c.b=0;
               T[i][j]=c;
            }    
        }    
    }
    cout << "initial: " <<endl;
    printT(T);
    
    if(A[0][0] == 'X'){
        cell c; c.a=1;c.b=1;
        T[0][0] = c;
    }
    
    for(int j=1; j< A[0].size(); ++j){
        if(A[0][j] == 'X'){
            cell c; c.a=1; 
            c.b = T[0][j-1].b+1;
            T[0][j]=c;
        }    
    }
    cout << " after first row : "<<endl;
    printT(T);
    
    for(int i=1; i<A.size(); ++i){
        if(A[i][0]== 'X'){
            cell c; c.b=1;
            c.a = T[i-1][0].a+1;
            T[i][0] = c;
        }    
    }
    cout << "after first col: "<<endl;
    printT(T);
    
    
    for(int i=1; i<A.size(); ++i){
        for(int j=1; j<A[0].size(); ++j){
        	if(A[i][j] == 'X'){
	            T[i][j].a = T[i-1][j].a + 1;
	            T[i][j].b = T[i][j-1].b + 1;
        	}
        }
    }
    cout << "after filling everything: "<<endl;
    printT(T);
    
    int max = 0;
    
    for(int i=A.size()-1; i>=0; --i){
    	for(int j=A[0].size()-1; j>=0; --j){
    		if(T[i][j].a == 0 || T[i][j].a == 1 || T[i][j].b==1)
    			continue;
    		
    		int mini = min(T[i][j].a,T[i][j].b);
    		
    		int k;
    		for(k=mini; k>1; --k){
    			if(T[i][j-k+1].a >=k && T[i-k+1][j].b >=k)
    				break;
    		}
    		if(max<k)
    			max = k;
    	}
    	
    }
    return max;
}


int main()
{
  vector<vector<char>> A = {{'O', 'O', 'O', 'O', 'X'},
                            {'X', 'O', 'X', 'X', 'X'},
                            {'X', 'O', 'X', 'O', 'X'},
                            {'X', 'X', 'X', 'X', 'X'},
                            {'O', 'O', 'X', 'X', 'X'},
                            };
                            
    cout << maxSubSquareX(A) << endl;
    return 0;
}
