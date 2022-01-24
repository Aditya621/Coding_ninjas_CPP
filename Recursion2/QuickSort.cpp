#include<iostream>

using namespace std;


/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;*/

// void swap(int* a, int* b) 
// { 
//     int t = *a; 
//     *a = *b; 
//     *b = t; 
// }

// 	int partition(int arr[] , int si ,int ei){
//         int pivot = arr[ei]; //pivot element
//         int i = si-1;//-1
        
//         for(int j = si ; j<ei ; j++){
//             if(arr[j] <= pivot){
//                 i++;
//                 swap(&arr[i] , &arr[j]);
//             }
//         }
//         swap(&arr[i + 1], &arr[ei]); 
//     return (i + 1);
//     }
	
// 	void quickSort(int input[], int si, int ei)
// 	{
//     		// your code goes here 
//         if(si >= ei)
//             return;
//         int pi = partition(input , si ,ei);
//         quickSort(input , si , pi-1);
//         quickSort(input , pi+1 , ei);
// 	}

int partition(int a[] , int si ,int ei){
	int pivot = a[si];
	int countSmallerNumbers = 0;

	for(int i = si + 1; i <= ei; i++) {
		if(a[i] <= pivot)
			countSmallerNumbers++;
	}

	int pivotIndex = countSmallerNumbers + si;
	a[si]  = a[pivotIndex];

	a[pivotIndex] = pivot ;
	int i = si;
	int j = ei;

	while(i < pivotIndex && j > pivotIndex){
		if(a[i] <= pivot)
			i++;
		else if(a[j] > pivot)
			j--;
		else
		{
			//swap 
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	return pivotIndex;

}

void QuickSort(int a[] ,int si ,int ei){
	if(si >= ei)
		return;
	int p = partition(a, si,ei);
	QuickSort(a,si,p-1);
	QuickSort(a,p+1,ei);
}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size == 1 || size == 1)
        return ;
    QuickSort(input, 0, size - 1);
    

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


