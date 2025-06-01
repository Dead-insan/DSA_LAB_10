#include <iostream>
#include<string>
using namespace std;
bool is_palindrome(string array,int size,int i=0,bool check=false)
{
    if(i>=size)
    {return true;}
    if(array[i]!=array[size])
    {  return false;}
    return is_palindrome(array, size-1,i + 1);;
}
int main()
{
    string array = "madxam";
    int size = array.length() - 1;
    int i = 0;

    bool check = is_palindrome(array, size, i);

    if (check)
        cout << "IS A palindrome";
    else
        cout << "Ain't one";

    return 0;
}
