/*
 Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :

Integer n

Output Format :

All possible strings in different lines

Constraints :
1 <= n <= 10^6
Sample Input:

23

Sample Output:

ad
ae
af
bd
be
bf
cd
ce
cf



*/

#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <string>
using namespace std;

string getcharstring(int c){
    if(c == 2)
        return "abc";
    if(c == 3)
        return "def";
    if(c == 4)
        return "ghi";
    if(c == 5)
        return "jkl";
    if(c == 6)
        return "mno";
    if(c == 7)
        return "pqrs";
    if(c == 8)
        return "tuv";
    if(c == 9)
        return "wxyz";
    return " ";
}

void print(int num , string output)
{
    if(num == 0){
        cout<<output<<endl;
        return ;
    }
    string LastDigit = getcharstring(num%10); 
    for(int  i = 0 ; i < LastDigit.length() ; i++){
    print(num / 10, LastDigit[i] +output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    //int Smallnum = num/10;
    print(num ,"");
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
