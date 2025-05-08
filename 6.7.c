#include <stdio.h>
#include <stdlib.h>

//swap 2 int numbers
void swap( int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void blocksort(int arr[], int n) {
	//size each block
	int blocksize = 3;
	
	//for a block
	for (int i = 0; i < n; i += blocksize) {
		for (int j = 0; j < i + blocksize && j < n; j++) {
			for (int k = i; k < j; k++) {
				if (arr[k] > arr [j]) {
					swap (&arr[k], &arr[j]);
				}
			}
		}
	}
	
	//merge block
	for (int i = 0; i < n ; i++) {
		for (int j = i + 1; j < n; j++ ) {
			if (arr[i] > arr [j]) {
				swap (&arr[i], &arr[j]);
			}
		}
	}
}

//remove duplicate
int removedup(int arr[], int n) {
	if (n==0 || n == 1) return n;
	
	int index = 0; //position to overwrite
	
	for (int i = 0; i < n;) {
		arr[index++] = arr[i];
		
		//skip dup
		while (i + 1 < n && arr[i] == arr[i + 1]) {
			i++;
		}
		i++;
	}
	return index;
}

//print array
void printarray (int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main () {
	int n;
	
	puts("How many numbers: ");
	scanf("%d", &n);
	
	int *arr = (int *)malloc(n * sizeof(int));
	
	if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;  // Exit program
    }
    
    printf("Enter %d numbers: ", n);
    for ( int i = 0; i < n; i++) {
    	scanf ("%d", &arr[i]);
	}
	
	printf("Array before sorted: ");
	printarray(arr, n);
	
	blocksort(arr, n);
	
	printf("Array after sorted: ");
	printarray(arr, n);
	
	//remove duplicates
	n = removedup(arr, n);
	printf("Array after removing duplicates:\n");
	printarray(arr, n);
	
	free(arr);
	return 0;
}
