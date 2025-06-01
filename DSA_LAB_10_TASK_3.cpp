#include <iostream>
using namespace std;

int find_max(int arr[], int size, int start, int &max) {
    if (start == size) {
        return max;
    }

    if (arr[start] > max) {
        max = arr[start];
    }

    return find_max(arr, size, start + 1, max);
}

int main() {
    int arr[] = {3, 9, 2, 7, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];  

    int result = find_max(arr, size, 0, max);

    cout << "Maximum value: " << result << endl;

    return 0;
}
