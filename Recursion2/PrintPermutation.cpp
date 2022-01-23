/*
 Print Permutations
Send Feedback
Given an input string (STR), print all possible permutations of the input string.
Note:

The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

Input Format:

The only input line contains a string (STR) of alphabets in lower case

Output Format:

Print each permutations in a new line

Note:

You do not need to print anything, it has already been taken care of. Just implement the function.  

Constraint:

1<=length of STR<=8
Time Limit: 1sec

Sample Input 1:

cba

Sample Output 1:

abc
acb
bac
bca
cab
cba


*/
#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

void Helper(string input,string output )
    {
      int start = 0;

    if(input.length() == 0){
        cout<<output;
        cout<<endl;
        return ;
    }
    
    for(int i = 0 ; i< input.length() ; i++){
        char ch = input[i];
        string a = input.substr(start,i) ;
        string b = input.substr(i+1);
        string ans = a + b;
        Helper(ans, output + ch ); // 2+2+2 = 6 size  
        //assume that size store all the row === 6
        }
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output;
    Helper(input,output);
    
    
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}