// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define unsigned int uint
using namespace std;

class job{
  int _start;
  int _end;
  int _profit;
  
  public:
    job(int start, int end, int profit): _start(start),_end(end),_profit(profit){}
    
    int getprofit(){
        return _profit;
    }
    
    int getStart(){
       return _start; 
    }
    
    int getEnd(){
        return _end;    
    }
    
};

void printjobs(vector<job> &jobs){
  for(uint i=0; i<jobs.size();++i)
    cout << jobs[i].getprofit() << " ";
  cout << endl;
}

void printArray(const vector<int> &T){
    for(auto x:T)
        cout << x << " ";    
    cout << endl;   
}

bool donotOverlap(job i, job j){
  int is= i.getStart();
  int js = j.getStart();
  int ie = i.getEnd();
  int je = j.getEnd();
  
  if(ie > je)
    return donotOverlap(j,i);
  
  if(is <= js && js < ie)
    return false;
    
  if(js <= is)
    return false;
    
  return true;
}

int schedule(vector<job> &jobs){
    
    sort(jobs.begin(), jobs.end(), [](job &a, job& b){return a.getEnd() < b.getEnd();});
    printjobs(jobs);
    
    vector<int> T(jobs.size());
    for(uint i=0; i<jobs.size(); ++i)
        T[i] = jobs[i].getprofit();

    for(uint i=1; i<T.size(); ++i){
        for(uint j=0; j<i; ++j){
            if( donotOverlap(jobs[j],jobs[i]) )
                T[i] = max(T[i],T[j] + jobs[i].getprofit());
        }   
        printArray(T); 
    }  
    return *max_element(T.begin(), T.end());
}



int main()
{
  vector<job> jobs;
  jobs.push_back(job(1,3,5));
  jobs.push_back(job(2,5,6));
  jobs.push_back(job(4,6,5));
  jobs.push_back(job(6,7,4));
  jobs.push_back(job(5,8,11));
  jobs.push_back(job(7,9,2));
  
  printjobs(jobs); 
  cout << schedule(jobs) << endl;
  return 0;
}
