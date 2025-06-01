#include<iostream>
using namespace std;
int calculate_sum_of_array(int arr[],int size,int & sum)
{
    if(size<0)
    {
        return sum;
    }
    sum += arr[size];
       return calculate_sum_of_array(arr, size - 1, sum);
   }

int main()
{
    int arr[5];
    int size=5;
    for (int i=0; i<5; i++) {
        arr[i]=i;
    }
    int sum=0;
    sum= calculate_sum_of_array(arr,size-1,sum);
    cout<<sum;
    
}
