/*
 Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :

A numeric string

Constraints :
1 <= Length of String S <= 10
Sample Input:

1123

Sample Output:

aabc
kbc
alc
aaw
kw


*/
#include <iostream>

using namespace std;

#include <string.h>
using namespace std;

int getCodes(string input, string output[]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input[0] == '\0'){
        output[0] = "";
        return 1;
    }
    int first = input[0] - 48;
    char firstChar = first + 'a' - 1;
    char SecondChar = '\0';
    string smallOutput1[5000];
    string smallOutput2[5000];
    
   int size = getCodes(input.substr(1) ,smallOutput1);
    int size2 = 0;
    
    if(input[1] != '\0'){
        int Second = first*10 + (input[1] - 48);
        if(Second >= 10 && Second <= 26){
            SecondChar = Second + 'a' - 1;            
            size2 = getCodes(input.substr(2),smallOutput2);
        }
    }
    int k = 0;
    for(int i = 0; i< size ;i++){
        output[k] = firstChar + smallOutput1[i];
        k++;
    }
    for(int i = 0; i< size2 ;i++){
        output[k] =SecondChar+ smallOutput2[i];
        k++;
    }
    return k;
    
}



int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
