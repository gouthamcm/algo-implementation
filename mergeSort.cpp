#include<iostream>

using namespace std;

/*
	Function Name: merge
	Inputs: int arr[], int begin, int mid, int end
	Logic: 
		"Merges" and sorts two subarrays of arr[] in ascending order.
		The sub arrays are (begin, mid) and (mid+1, end)
	Example Call: merge(arr, 0, 2, 4) Merges the first 5 elements of arr in acending order
*/
void merge(int arr[], int begin, int mid, int end) {
	int i, j, k; // Looping Variables
	int n1 = mid - begin + 1; // Number of elements in first sub-array
	int n2 = end - mid; // Number of elements in second sub-array
	
	// Create Temporary Arrays
	int L[n1], R[n2]; 
	
	// Copy data from array to temp arrays
	for(i = 0; i < n1; i++) {
		L[i] = arr[i+begin];
	}
	for(i = 0; i < n2; i++) {
		R[i] = arr[i + mid + 1];
	}
	
	// Merge the arrays in ascending order
	i = 0, j = 0, k = begin;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}
	
	// Copy left over elements in L
	while(i < n1) {
		arr[k++] = L[i++];
	}
	
	// Copy left over elements in R
	while(j < n2) {
		arr[k++] = R[j++];
	}
}

/*
	Function name: mergeSort
	Inputs: int arr[], int begin, int end
	Logic: Sorts the given array recursively and using the merge function
	Example Call: mergeSort(arr, 0, 3) sorts the first 4 elements of arr
*/
void mergeSort(int arr[], int begin, int end) {
	if(begin < end) { // Run only if more than one element needs to be sorted.
		// Find Midpoint to split array
		int m = begin + (end - begin)/2; // Avoids overflow
		
		//Sort first and second half arrays recursively
		mergeSort(arr, begin, m);
		mergeSort(arr, m+1, end);
		
		//Merge the two half arrays
		merge(arr, begin, m, end);
	}
}

/* 
	Function name: printArray
	Inputs: int A[], int size
	Logic: Function to print an array
	Example call: printArray(arr, 5) prints first 5 elements of arr	
*/
void printArray(int A[], int size) {
    for (int i=0; i < size; i++) {
    	cout << A[i] << " ";
	}
	cout << endl;
} 

/*
	Main Function
*/
int main() { 
	// Initialise Temporary Array, program may be modified later to input an array
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  	
    cout << "Given Array is:\n";
    printArray(arr, arr_size); 
  
  	// Sort using mergeSort
    mergeSort(arr, 0, arr_size - 1); 
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size); 
    
    return 0; 
} 
