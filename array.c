/* 1. Construct the following program in C using dynamic memory allocation:

           (i) Search an element from an array

           (ii) Remove duplicate elements from an array.

          (iii) Sort the elements of the array.*/
 
#include <stdio.h>
#include <stdlib.h>


void searchElement(int *arr, int n, int searchElement);
void removeDuplicatesAndPrint(int *arr, int n);
void sortArray(int *arr, int n);

int main() {
    int n, searchElementValue, i,a;
    int *arr;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &searchElementValue);
    searchElement(arr, n, searchElementValue);
    removeDuplicatesAndPrint(arr,n);
    sortArray(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

void searchElement(int *arr, int n, int searchElement) {
    int i, found = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == searchElement) {
            printf("Element %d found at index %d\n", searchElement, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array\n", searchElement);
    }
}

void removeDuplicatesAndPrint(int *arr, int n) {
    int count[1000] = {0}; 
    int temp[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (count[arr[i]] == 0) {
            temp[j++] = arr[i];
            count[arr[i]]++;
        }
    }

    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    n = j;

    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void sortArray(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}         

