#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralCopy( const vector<vector<int>>& inputMatrix ) 
{
  // your code goes here
  int rows, cols;
  //if (!inputMatrix.empty())
    rows = inputMatrix.size();
  //else
  //  rows = 0;
  //if (!rows && !inputMatrix[0].empty())
    cols = inputMatrix[0].size();
  //else
  //  cols = 0;
  
  int upper =0;
  int lower = cols-1;
  int left = 0;
  int right = rows-1;
  vector<int> myvector;
  cout<< "Rows-"<<rows <<endl;
  cout<< "Cols-"<<cols <<endl;
  
   while(((upper <= lower) && (left <= right)))
   {
     for(int i = left; i<right; i++)
     {
       myvector.push_back(inputMatrix[upper][i]);
       upper++;
     }
     for(int i = upper; i<lower ; i++)
     {
       myvector.push_back(inputMatrix[i][right]);
       right--;
     }
     if(upper<= lower){
       for(int i = right; i>left ; i--)
       {
         myvector.push_back(inputMatrix[lower][i]);
         lower--;
       }}
     if(left <= right){
     for(int i = lower; i>upper ; i--)
     {
       myvector.push_back(inputMatrix[i][left]);
       left++;
     }}
   }
  
  return myvector;
  
}

int main() {
  return 0;
}