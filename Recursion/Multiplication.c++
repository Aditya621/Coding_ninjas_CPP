#include <iostream>

using namespace std;
int multiplyNumbers(int m, int n) {
    // Write your code here
    if(n == 0)return 0;
    int ans = multiplyNumbers(m,n-1);// m * n-1 = 3 * 4 = 12
    return ans + m; // 12 +3 =15;
}



int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
