#include <iostream>

using namespace std;


// void mergeTwoArrayAns(int s[] , int l , int mid , int r){
//     int n1 ,n2;
//     n1 = mid - l + 1;
//     n2 = r - mid;
//     int arr1[n1] ;
//     int arr2[n2];
    
//     for(int i = 0 ; i < n1; i++){
//         arr1[i] = s[i + l];
//     }
//     for(int j = 0 ; j < n2; j++){
//         arr2[j] = s[j + mid + 1];
//     }
//     int i = 0 ;
//     int j = 0;
//     int k = l;
    
//     while(i < n1 && j < n2){
//         if(arr1[i] <= arr2[j] ){
//             s[k] = arr1[i];
//             i++;
//         }
//         else{
//             s[k]=arr2[j];
//             j++;
//         }
//         k++;
//     }
//     while(i < n1){
//         s[k] = arr1[i];
//         i++;
//         k++;
//     }
//     while(j < n2){
//         s[k] = arr2[j];
//         j++;
//         k++;
//     }  
// }

// void sortTwoArray(int s[] , int start , int end){
//     if(start >= end)
//         return;
//     int mid = (start+end) / 2;
//     sortTwoArray(s , start , mid);
//     sortTwoArray(s , mid + 1 , end);
    
//     mergeTwoArrayAns(s , start , mid , end);
// }

void mergeTwoSortedArray(int arr[] , int si  ,int ei){
    int size = ei - si + 1;
    int mid = (si + ei) / 2;
    
    int *output = new int[size];//in heap
    int i = si;
    int j = mid + 1;
    int k = 0;
    
    while(i <= mid && j <= ei){
        if(arr[i] < arr[j]){
            output[k] = arr[i];
            i++;k++;
        }
        else{
            output[k] = arr[j];
            j++;
            k++;
        }
    }
    
    while(i <= mid){
        output[k] = arr[i];
        k++;i++;
    }
    while(j <= ei){
        output[k] = arr[j];
        j++;k++;
    }
    int m = 0;
    for(int i = si ; i <= ei ; i++){
        arr[i] = output[m];
        m++;
    }
    
    //dealloacte memeory
    delete [] output;
}


void sortTwoArray(int s[] , int s_index ,int e_index){
    if(s_index >= e_index){
        return;
    }
    int mid = (s_index + e_index) / 2 ;
    
    sortTwoArray(s , s_index , mid);
    sortTwoArray(s , mid + 1 , e_index);
    
    mergeTwoSortedArray(s , s_index , e_index);
}



void mergeSort(int input[], int size){
	// Write your code here
    if(size == 0 && size == 1)
        return;
    sortTwoArray(input , 0 , size - 1);
        
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}