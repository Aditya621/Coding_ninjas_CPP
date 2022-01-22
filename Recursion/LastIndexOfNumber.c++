#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    //base case
    if(size == 0) return -1;
    int ans = lastIndex(input + 1 , size - 1, x);
    
    if(ans == -1){
     if(x == input[0])
    {
        return 0;
    }
        else
            return -1;
    }
    else
    return ans + 1;


}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}


