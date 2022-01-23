/*
 Print Subset Sum to K
Send Feedback
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :

Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Sample Input:

9 
5 12 3 17 1 18 15 3 17 
6

Sample Output:

3 3
5 1


*/

#include <iostream>
using namespace std;

void printAnsArray(int input[], int n , int startIndex,int output[],int m,int k)
{
 if(n == startIndex){
     if(k==0){
        for(int i = 0 ; i< m ; i++)
            cout<<output[i]<<" ";
        cout<<endl;
         return;
     }
     else
         return ;
    }
    int smallOutput1[10000];
    //if 5 is not added in  k
        printAnsArray(input,n,startIndex+1,output,m,k);
//if 5 is added to k
    if(k>0){
        int i;
        for( i = 0 ; i < m ; i++){
            smallOutput1[i] = output[i];
        }
        smallOutput1[i] = input[startIndex];
        printAnsArray(input,n,startIndex+1,smallOutput1,m+1,k-input[startIndex]);
    }
    // output[m]=input[startIndex];
    //  printAnsArray(input,n,startIndex+1,output,m+1,k-input[startIndex]);

    
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code he re
    int output[100000];
    printAnsArray(input , size,0 , output,0,k);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
