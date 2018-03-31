/*Given a 2D matrix of 0s and 1s. Find largest rectangle of all 1s
 * in this matrix.
 * 
 * Maintain a temp array of same size as number of columns. 
 * Copy first row to this temp array and find largest rectangular area
 * for histogram. Then keep adding elements of next row to this temp
 * array if they are not zero. If they are zero then put zero there.
 * Every time calculate max area in histogram.
 * 
 * Time complexity - O(rows*cols)
 * Space complexity - O(cols) - if number of cols is way higher than rows
 * then do this process for rows and not columns.
 */
 
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


int maxAreaHistogram(vector<int>  &A){
    stack<int> indices;
    A.push_back(0);
    int max_area = 0;
    int i=0;
    
    while(i < A.size()){
        
        if(indices.empty() || A[i] > A[indices.top()]){
            indices.push(i);
            ++i;
        }
        else{
                int height = A[indices.top()];
                indices.pop();
                int area, width;
                
                if(indices.empty())
                    width = i;
                else
                    width = i - indices.top() -1;
                    
                area = height * width;
                max_area = (area >max_area)? area:max_area;
        }
        
    }
    return max_area;
}

int maxSizeRect(vector< vector<int> > &M){
    
    int rows = M.size();
    int cols = M[0].size();
    
    vector<int> A(cols,0);
    
    int maxArea = 0;
    for(int i=0; i < rows; ++i){
        
        for(int j=0; j < cols ; ++j){
            A[i] = M[i][j]==0? 0: A[i] + M[i][j];
        }
        // A is our histogram till including ith row
        int maxAreaA = maxAreaHistogram(A);
        if(maxArea < maxAreaA)
            maxArea = maxAreaA;
    }
    return maxArea;
}


int main()
{
    vector< vector<int> > M = { {1,0,0,1,1,1},{1,0,1,1,0,1},{0,1,1,1,1,1},{0,0,1,1,1,1}};
    cout << maxSizeRect(M) << endl;
}
