/*
 Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :

Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15
Sample Input:

3
15 20 12

Sample Output:

[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 


*/
#include <iostream>
using namespace std;


void PrintArray(int input[] , int n , int startIndex , int output[] , int m){
    
    if(n == startIndex){
        for(int i = 0 ; i< m ; i++)
            cout<<output[i]<<" ";
        cout<<endl;
        return ;
    }
    int smallOutput1[40];
    int smallOsize = 0;
    PrintArray(input , n, startIndex + 1 , output , m);
   {
        int i ;
        for(int i = 0 ; i < m ; i++){
            smallOutput1[i] = output[i];
        }
        smallOutput1[i] = input[startIndex];
        PrintArray(input , n , startIndex + 1 ,smallOutput1, m + 1);
    }

    //  output[m] = input[startIndex];
    // PrintArray(input , n , startIndex + 1 ,output, m + 1);
          
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[100000];
    PrintArray(input , size ,0 , output , 0);
    
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
