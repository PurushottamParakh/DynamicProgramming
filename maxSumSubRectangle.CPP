// Example program
#include <iostream>
#include <string>
#include <vector>
#define unsigned int uint
using namespace std;

class KadaneResult{
    int _maxSum;
    int _start;
    int _end;
    
public: 
    KadaneResult(int maxSum, int start, int end):_maxSum(maxSum), _start(start),_end(end){}
    
    KadaneResult kadaneAlgo(vector<int> A){
        int max  = 0;
        int maxStart=-1;
        int maxEnd = -1;
        int currentStart = 0;
        int maxSoFar = 0;
        
        for(int i=0; i<arr.length; ++i){
            maxSoFar += arr[i];
            if(maxSoFar < 0){
                maxSoFar = 0;
                currentStart = i+1;
            }
            
            if(max < maxSoFar){
                maxStart = currentStart;
                maxEnd = i;
                max = maxSoFar;
            }
        }
        return KadaneResult(max,maxStart,maxEnd);
    }        

};

class Result{
    int _maxSum;
    int _L,_R,_U,_D;
    
    public:
        string to_string(){
            return "Result: [ maxSum = "+to_string(_maxSum) + " L="+to_string(_L) + " R="+
            to_string(_R) + " U=" + to_string(_U) + " D="+to_string(D);
        }
    
        Result maxSum(vector< vector<int> > &M){
            
            int rows = M.size();
            int cols = M[0].size();
            
            vector<int> A(rows,0);
            Result result = new Result();
            
            for(int left = 0; left < cols; ++left){
                
                for(int i=0; i<rows; ++i)
                    A[i] = 0;
                    
                for(int right = left; right < cols; ++right){
                    
                    for(int i=0; i<rows; ++i){
                        A[i] += M[i][right];    
                    }
                
                    KadaneResult kadaneResult = kadaneAlgo(A);
                    if(kadaneResult.maxSum > result.maxSum){
                        result.maxSum = kadaneResult.maxSum;
                        result.L = left;
                        result.R= right;
                        result.U = kadaneResult.start;
                        result.D=kadaneResult.end;
                        
                    }
                    
                } 
            }
            return result;
            
        }
    
};

void printT(vector< vector<int> > &T){
    for(uint i=0; i< T.size(); ++i){
        for(uint j=0; j<T[0].size(); ++j){
            cout << T[i][j] << " ";
        }    
        cout<< endl;
    }
}




int main()
{
  vector< vector<int>> M  = { {2,1,-3,-4,5}, {0,6,3,4,1}, {2,-2,-1,4,-5},{-3,3,1,0,3}};
  printT(M);
  
  cout << maxSumSubrectangle(M) << endl;
  
 return 0;
}
