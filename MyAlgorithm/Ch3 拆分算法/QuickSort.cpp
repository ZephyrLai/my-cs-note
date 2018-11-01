#include <iostream>
#include <windows.h>

using namespace std;

/**
 * 快速排序 
 */

int mySplit(int arr[],int startIndex,int endIndex)
{
    int i = startIndex, j = endIndex,mid = 0;
    int compareNum = arr[startIndex];
    while(i<j)
    {
        while(i<j && arr[j]>compareNum )
            j--;
        if(i<j)
            swap(arr[i++],arr[j]);
        while(i<j && arr[i]<compareNum)
            i++;
        if(i<j)
            swap(arr[i],arr[j--]);
    }
    return i;
}

int mySplit02(int arr[],int low,int high)
{
    int i = low+1,j = high;
    int compareNum = arr[low];
    while(i<j)
    {
        while(i<j && arr[i]<compareNum) i++; 
        while(i<j && arr[j]>compareNum) j--;
        if(i<j)
            swap(arr[i++],arr[j--]); 
        if(arr[i]>compareNum)
        {
            swap(arr[i-1],arr[low]);
            return i-1;
        }
        swap(arr[i],arr[low]);    
    }
    return i;
}


void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = mySplit02(arr,low,high);//每次确定一个元素的正确位置
        quickSort(arr,low,mid-1);
        quickSort(arr,mid+1,high);
    }

}

int main()
{
    /* code */
    int arr[5] ={2,5,98,4,65} ;
    quickSort(arr,0,4);
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    system("pause");
    return 0;
}
