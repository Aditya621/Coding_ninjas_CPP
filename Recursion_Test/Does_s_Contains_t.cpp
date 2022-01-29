/*
 Does s contain t ?
Send Feedback
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :

Line 1 : String s
Line 2 : String t

Output Format :

true or false

Sample Input 1 :

abchjsgsuohhdhyrikkknddg
coding

Sample Output 1 :

true

Sample Input 2 :

abcde
aeb

Sample Output 2 :

false


*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;



bool CheckAns(char large[] , char small[] , int len1 , int len2)
{
    if(len1 == 0 && len2 != 0)
        return false;
    else if(len2 == 0 && len1 != 0)
        return true;
    else if(len1 == 0 && len2 == 0)
        return true;
    
    
    if(large[len1-1] == small[len2-1])
    {
        return CheckAns(large,small,len1-1,len2-1);
    }else
    {
        return CheckAns(large,small,len1-1,len2);
    }
    
}

bool checksequenece(char large[] , char*small) {
    int len1 = strlen(large);
    int len2 = strlen(small);
    return  CheckAns(large , small ,len1,len2);
}


int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
