/*
 Return Permutations - String
Send Feedback
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :

String S

Output Format :

All permutations (in different lines)

Sample Input :

abc

Sample Output :

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

#include <string.h>
using namespace std;



int returnPermutations(string input, string output[100000]){
    /* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
         int start = 0;

    if(input.size() == 0){
        output[0] = " ";
        return 0;
    }

            int size;
    string output1[100000];
            for(int i = 0 ; i< input.size() ;i++){
                char ch = input[i];
                string a = input.substr(start,i) ;
                string b = input.substr(i+1);
                string ans = a + b;
                size = returnPermutations(ans, output1 + ch ); // 2+2+2 = 6 size  
                //assume that size store all the row === 6
            }
            int k;
            for(int i =0 ;i < size ;i++){
                for(int j = 0 ; j <= output1[i].length() ; j ++)
                    output[k ++] = output1[j];
                // k++;
            }
            return k;
    // string output1[100000];
    // int smallAns = returnPermutations(input.substr(1),output1);//bc,cb
    // int k = 0;
    // for(int i = 0;i < smallAns;i ++)
    // {
    //     for(int j = 0;j <= output1[i].length();j ++)
    //     {
    //         output[k ++] = output1[i].substr(0,j) + input[0] + output1[i].substr(j);
    //     }
    // }
    return k;
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
