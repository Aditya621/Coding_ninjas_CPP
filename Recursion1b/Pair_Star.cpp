#include <iostream>

using namespace std;

// Change in the given string itself. So no need to return or print the changed string.
int length(char input[]){
	int len = 0;
	for(int i =0;input[i] != '\0';i++){
		len++;
	}
	return len;
}


void addStar(char s[] , int start){
   
    if(s[start] == '\0')
        return ;
     
    addStar(s , start + 1);
    if(s[start] == s[start+1]){
         int n = length(s);
        s[n+1] = '\0';
        for(int i = n-1 ; i>=start+1 ; i--){
            s[i+1] = s[i];
        }
        s[start +1] = '*';
    }
    
}
// void addStar(char input[] ,char  output[] , int i)
// {
//     int size = length(input);
//     // Append current character
//     output = output + input[i];
 
//     // If we reached last character
//     if (i == size - 1)
//         return;
 
//     // If next character is same,
//     // append '*'
//     if (input[i] == input[i + 1])
//         output = output + '*';      
 
//     addStar(input, output, i+1);
// }

void pairStar(char input[]) {
    // Write your code here
    addStar(input,0);
    // addStar(input , output , 0);

}


int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
