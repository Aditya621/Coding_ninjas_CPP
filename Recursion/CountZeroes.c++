#include <iostream>

using namespace std;

int countZeros(int n) {
    // Write your code here
   if (n==0)
       return 1;
    if(n<10)
        return 0;
    int smallAns = countZeros(n/10);// 2 zeroes
    int lastDigit = n % 10; // 2 != 0
    
    if(lastDigit == 0)
        return smallAns + 1;
    else
        return smallAns ;

}



int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
