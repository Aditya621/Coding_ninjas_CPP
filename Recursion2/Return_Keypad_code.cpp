// imp

#include <iostream>
#include <string>

using namespace std;


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
    if(c == 0 || c == 1)
        return " ";
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0){
        output[0] ="";
        return 1;
    }
    int smallNumber = num/10;// 2
    int lastDigit = num%10; // 3
    
    int smallOutputSize = keypad(smallNumber , output);
    string OptionSize = getcharstring(lastDigit);
    
    for(int i = 0 ; i < OptionSize.length() - 1 ; i++){
        for(int j = 0 ; j < smallOutputSize ; j++){
            output[j + (i+1)*smallOutputSize] = output[j];
        }
    }
    
    int k = 0;
    for (int i = 0 ; i < OptionSize.length() ;i++){
        for(int j = 0 ;j <  smallOutputSize ; j++){
            output[k] = output[k] + OptionSize[i];
            k++;
        }
    }
    return smallOutputSize * OptionSize.length();
    
}    

//     if(num == 0 ){
//         output[0] = "";
//         return 1;
        
//     }
//     if(num == 1){
//         output[0] = "";
//         return 1;
//     }
//     int smallNumber = num / 10;// 2
//     string lastDigit =getcharstring(num % 10 );// 3
    
//     int smallOutput = keypad(smallNumber , output);
//     string temp[10000];
//     int k = 0;
//     for(int i = 0 ; i < smallOutput ; i++){
//         for(int j = 0 ; j < lastDigit.length() ; j++){
//     	temp[k] = output[i] + lastDigit[j] ;
//             k++;
//             }
        
//     }
//     for(int i = 0 ; i < k;i++){
//         output[i] = temp[i];
//     }
//     return smallOutput*lastDigit.length(); 
 



int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

