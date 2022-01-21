#include <iostream>

using namespace std;

// Change in the given string itself. So no need to return or print anything
int calLength(char s[]){
    int len = 0;
    for(int i = 0 ; s[i] != '\0' ;i++){
        len++;
    }
    return len;
}

void find(char s[],int start)
{
    if(s[start] == '\0')return;
    
    find(s,start+1);
    if(s[start] == 'x'){
        int len = calLength(s);
        int i;
        for(i = start + 1 ; i<len ; i++)
        {
            s[i-1]=s[i];
        }
        s[i-1] = '\0';
    }
    
    
}
void removeX(char input[]) {
    // Write your code here
    find(input ,0);

}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
