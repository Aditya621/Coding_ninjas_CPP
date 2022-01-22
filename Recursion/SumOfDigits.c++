#include <iostream>

using namespace std;
int sumOfDigits(int n) {
    // Write your code here
    if(n == 0)
        return 0;
    if(n < 10)
        return n;
    int N = n / 10;
    int Ans1 = n%10;
    int ans = sumOfDigits(N);
    return ans +Ans1;
    

}



int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
