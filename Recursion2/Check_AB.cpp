/*
 Check AB
Send Feedback
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.
Input format :

String S

Output format :

'true' or 'false'

Constraints :

1 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :

abb

Sample Output 1 :

true

Sample Input 2 :

abababa

Sample Output 2 :

false



*/

#include <iostream>

using namespace std;


bool CheckInput(char input[] , int start){
    if(input[start] == '\0')
        return true;
    if(input[start] != 'a')
        return false;
    
    if(input[start+1] != '\0' && input[start+2] != '\0'){
        if(input[start+1] == 'b' && input[start+2] == 'b'){
            return CheckInput(input , start + 3);
        }
    }
        return CheckInput(input , start + 1);
}

bool checkAB(char input[]) {
	// Write your code here
    bool ans;
    ans = CheckInput(input , 0);
    return ans;

}





int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
