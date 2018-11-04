# 分治法
## 一、概念
1. 包括三步：分解、治理、合并
2. 分解：将大问题分解无限细分，直到容易处理为止；
3. 治理：将无限细分之后容易处理的小问题处理掉；
4. 合并：将小问题的结构回归整理为大问题的结果
## 二、应用
### 1. 二分查找
1. 思路概括
    1. 首先是有序数列，如果不是有序数列，首先要排序（时间复杂度=O(nlogn)）;
    2. 取正中间索引（索引值=mid）的元素，如果比待比较元素小，则取索引从0 ~ mid-1的元素，重复2的操作；如果比待比较元素大，则取索引从mid+1 ~ n-1的元素，重复2操作；
2. 核心代码
    ``` c++
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
    ```  
### 2. 合并排序
1. 思路概括：   
    1. 分解：什么都不管，拿到数组就是递归对半拆分，直到拆到的手头的子数组中只有一个元素为止；
    1. 治理+合并：将相邻子列进行两两合并排序；
2. 核心代码：
    ``` c++
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
    ```
### 3. 快速排序