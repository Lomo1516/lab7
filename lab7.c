#include <stdio.h>

void printArrayWithSwaps(int arr[], int swaps[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d: %d\n", arr[i], swaps[i]);
}

void bubbleSort(int arr[], int n) {
    int swaps[n]; // Array to store the number of swaps for each element
    int total_swaps = 0;

    // Initialize swaps array with 0
    for (int i = 0; i < n; i++)
        swaps[i] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Increment swap count for swapped elements
                swaps[j]++;
                swaps[j + 1]++;
                total_swaps++;
            }
        }
    }

    // Print the number of swaps for each element
    printf("array bubble sort:\n");
    printArrayWithSwaps(arr, swaps, n);

    // Print the total number of swaps
    printf("%d\n\n", total_swaps / 2); // Dividing by 2 as each swap involves two elements
}

void selectionSort(int arr[], int n) {
    int swaps[n]; // Array to store the number of swaps for each element
    int total_swaps = 0;

    // Initialize swaps array with 0
    for (int i = 0; i < n; i++)
        swaps[i] = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_indx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_indx])
                min_indx = j;

        // Swap the found minimum element with the first element
        if (min_indx != i) {
            int temp = arr[i];
            arr[i] = arr[min_indx];
            arr[min_indx] = temp;

            // Increment swap count for swapped elements
            swaps[i]++;
            swaps[min_indx]++;
            total_swaps++;
        }
    }

    // Print the number of swaps for each element
    printf("array selection sort:\n");
    printArrayWithSwaps(arr, swaps, n);

    // Print the total number of swaps
    printf("%d\n\n", total_swaps / 2); // Dividing by 2 as each swap involves two elements
}

int main() {
    // Bubble arrays
    int B_array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int B_array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Selection arrays
    int S_array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int S_array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    bubbleSort(B_array1, sizeof(B_array1) / sizeof(B_array1[0]));
    bubbleSort(B_array2, sizeof(B_array2) / sizeof(B_array2[0]));

    selectionSort(S_array1, sizeof(S_array1) / sizeof(S_array1[0]));
    selectionSort(S_array2, sizeof(S_array2) / sizeof(S_array2[0]));

    return 0;
}
