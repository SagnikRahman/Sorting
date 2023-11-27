#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int tempArray[n];
    for (int size = 1; size < n; size *= 2) {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * size) {
            int mid = leftStart + size - 1;
            int rightEnd = (leftStart + 2 * size - 1 < n - 1) ? leftStart + 2 * size - 1 : n - 1;
            int left = leftStart;
            int right = mid + 1;
            int index = leftStart;
            while (left <= mid && right <= rightEnd) {
                if (arr[left] <= arr[right]) {
                    tempArray[index] = arr[left];
                    left++;
                } else {
                    tempArray[index] = arr[right];
                    right++;
                }
                index++;
            }
            while (left <= mid) {
                tempArray[index] = arr[left];
                left++;
                index++;
            }
            while (right <= rightEnd) {
                tempArray[index] = arr[right];
                right++;
                index++;
            }
            for (int i = leftStart; i <= rightEnd; i++) {
                arr[i] = tempArray[i];
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
