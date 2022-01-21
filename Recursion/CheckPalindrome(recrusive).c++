#include <iostream>

using namespace std;

bool findPlaindrome(char s[] , int start , int end){
    if(start == end)
        return true;
    if(s[start] != s[end])
        return false;
    
    if(start < end + 1)
    return findPlaindrome(s , start+1, end-1);
//     if(ans == true)
//         return true;
//     else
//         return false;
    return true;
    
}


bool checkPalindrome(char input[]) {
    // Write your code here
    int n;
    for(int i = 0; input[i] != '\0'; i++)
     n=n+1;
    
    if(n == 0 || n == 1)
        return true;
    return findPlaindrome(input , 0 , n-1);
    

}




int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
