#include<iostream>

using namespace std;


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


void printArray(int A[], int size) {
    for (int i=0; i < size; i++) {
    	cout << A[i] << " ";
	}
	cout << endl;
} 


int main() { 
	// Ask the array from the user to be sorted
    int arr[],arr_size;
    cout<<"Enter the size of the array : ";
    cin>>arr_size;
    cout<<"Enter the array : "<<endl;
    for(int i=0;i<n;i++)
	    cin>>a[i]; 
  	
    cout << "Given Array is:\n";
    printArray(arr, arr_size); 
  
  	// Sort using mergeSort
    mergeSort(arr, 0, arr_size - 1); 
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size); 
    
    return 0; 
} 
