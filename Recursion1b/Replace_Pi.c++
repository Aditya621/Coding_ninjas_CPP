
#include <iostream>

using namespace std;

// Change in the given string itself. So no need to return or print anything
int length(char s[])
{
    int len = 0;
    for(int i = 0 ; s[i] != '\0' ; i++)
    {
        len++;
    }
    return len;
}
void ansReplacePi(char s[] , int start){
    
    // int n;
    // for(int i = 0; s[i] != '\0'; i++)
    //  n=n+1;
    
    if(s[start] == '\0' || s[start+1] == '\0')
        return;
    ansReplacePi(s , start+1);
    int len = length(s);
    s[len+2] = '\0';
    
    if(s[start] == 'p' && s[start+1] == 'i'){
        
        for(int i = len -1 ; i>=start+2 ;i--){
            
            s[i+2] = s[i];
        }
        s[start] = '3';
        s[start+1] = '.';
        s[start +2] = '1';
        s[start+3] = '4';
        
    }
    
}

void replacePi(char input[]) {
	// Write your code here
    ansReplacePi(input , 0);
    

}





int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
