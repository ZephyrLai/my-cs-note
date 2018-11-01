#include <iostream>
#include <windows.h>
using namespace std;

int binarySearch(int arr[],int length,int num)
{
    int low = 0,high = length-1;
    while(low < length)
    {
        int mid = (low+high)/2;
        if(arr[mid] == num)
            return mid;
        if(arr[mid]<num)
        {
            length = mid-1;
        }else
        {
            low = mid+1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {15,26,85,232,65,874,365,24,3,6};
    int result = binarySearch(arr,10,24);
    cout << result << endl;
    system("pause");
    return 0;
}