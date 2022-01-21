#include<iostream>

using namespace std;


int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if(size == 0)return 0;
    int ans = allIndexes(input , size-1 , x , output);
    if(ans == -1)
    {
        if(input[size -1] == x)
        {
            return size-1;
        } 
        else
        {
            return 0;
            
        }
    }
    if(input[size -1] == x)
    {
    output[ans] = size-1;
      return ans + 1;
        
    } 
    else
    {
      return ans; 
    
    }
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
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


