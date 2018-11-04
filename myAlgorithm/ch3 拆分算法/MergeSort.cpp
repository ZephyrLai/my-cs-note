#include <iostream>
#include <windows.h>

using namespace std;

/**
合并排序
*/
void merge(int arr[],int low,int mid,int high)
{
	// 申请辅助数组
	int *temp = new int[high-low+1];
	int i = low, j = mid+1;
	int k = 0;
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid) temp[k++] = arr[i++];
	while(j<=high) temp[k++] = arr[j++];
	
	for(int count = 0; count < k; count++)
	{
		arr[low++] = temp[count];
	}
	
}

void mergeSort(int arr[],int low,int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;	
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}

}

int main()
{
    int num;
	int arr[6] = { 13,54,5,32,26,3};
	mergeSort(arr, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}
    system("pause");
    return 0;
}