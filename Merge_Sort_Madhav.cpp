#include<iostream>
using namespace std;

 /*
	Logic: 
		"Merges" and sorts two subarrays of arr[] in ascending order.
		The sub arrays are (begin, mid) and (mid+1, end)
		The array is divided and sorted and finally combined with the help of a recursive function
*/
void merge(int arr[], int start, int mid, int end) {
	int i, j, k; 
	int n1 = mid - start + 1; // Number of elements in first half of the array
	int n2 = end - mid; // Number of elements in second half of the array

 	// Create Temporary Arrays
	int L[n1], R[n2]; 

 	// Copy data from array to temp arrays
	for(i = 0; i < n1; i++) {
		L[i] = arr[i+start];
	}
	for(i = 0; i < n2; i++) {
		R[i] = arr[i + mid + 1];
	}

 	// Merge the arrays in ascending order
	i = 0, j = 0, k = start;
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

void mergeSort(int arr[], int start, int end) {
	if(start < end) { // Run only if more than one element needs to be sorted.
		// Find Midpoint to split array
		int m = start + (end - start)/2; // Avoids overflow

 		//Sort first and second half arrays recursively
		mergeSort(arr, start, m);
		mergeSort(arr, m+1, end);

 		//Merge the two half arrays
		merge(arr, start, m, end);
	}
}
//Function to print the arrays
void printArray(int A[], int size) {
    for (int i=0; i < size; i++) {
    	cout << A[i] << " ";
	}
	cout << endl;
} 

int main() { 
	//Example program
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
