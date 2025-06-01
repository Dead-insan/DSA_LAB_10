#include<iostream>
using namespace std;
int find_max(int arr[],int size,int i,int &max)
{
    if (size <= 0) {
           cout << "Invalid array size." << endl;
           return 0;
       }

    if(i>size)
    {
        return max;
    }
    if(max<arr[i])
    {
        max=arr[i];
        
    }
    return find_max(arr,size, i+1,max);
}
void if_its_sum_of_arrays_memeber(int arr[], int size, int first, int second, int max)
{
    if (size <= 0)
    {
        cout << "Error: No array exists :( " << endl;
        return;
    }

    if (first >= size - 1)
    {
        cout << "Element is the greatest but ain't a magic number" << endl;
        return;
    }

    if (second >= size)
    {
        // Move to next 'second element (index 2) after first ', reset second = first + 1
        if_its_sum_of_arrays_memeber(arr, size, first + 1, first + 2, max);
        return;
    }

    if (arr[first] + arr[second] == max)
    {
        cout << "It's a magic number because: " << arr[first] << " + " << arr[second] << " equals " << max << endl;
        return;
    }

    // Try next number with same 'first'
    if_its_sum_of_arrays_memeber(arr, size, first, second + 1, max);
}

int main()
{
    int arr[] = {23, 15, 2, 13, 17, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];

    int result = find_max(arr, size - 1, 0, max);
    cout << "Maximum element in the array is: " << result << endl;

    if_its_sum_of_arrays_memeber(arr, size, 0, 1, result);

    return 0;
}

