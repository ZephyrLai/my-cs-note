#include <iostream>
using namespace std;

//定义结构体
typedef struct ListNode{
    int value;      // 值域
    ListNode *next; // 指针域
}*LNPointer; // 结构体定义结尾处要加分号

LNPointer mySort(int num,LNPointer pointer);

/**
 * (函数封装版)
 * 题目：已知链表头指针、数值x，将所有小于x的结点放在大于等于x的结点之前，且保证这些结点的相对位置 
 * 思路：巧用临时结点
 */
int main(int argc, char const *argv[])
{
    // 链表初始化 start
    ListNode a1;    
    ListNode a2;    
    ListNode a3;    
    ListNode a4;    
    ListNode a5;    
    ListNode a6;    
    
    a1.value=10;
    a2.value=90;
    a3.value=50;
    a4.value=60;
    a5.value=40;
    a6.value=15;
    
    a1.next = &a2;    
    a2.next = &a3;    
    a3.next = &a4;    
    a4.next = &a5;    
    a5.next = &a6;    
    a6.next = NULL;    
    // 链表初始化 end

    //设定x、链表头指针
    int x = 50;
    LNPointer resultPointer = mySort(x,&a1);

    cout << "new array:" << endl;
    while(resultPointer)
    {
        cout << resultPointer->value << endl;
        resultPointer = resultPointer->next;  
    }
    system("pause");

    return 0;
}
LNPointer mySort(int num,LNPointer pointer)
{
    // 临时结点初始化
    ListNode node1 = {0,NULL};
    ListNode node2 = {0,NULL};
    LNPointer newSmallHeaderRecord = &node1;
    LNPointer newBigHeaderRecord = &node2;
    LNPointer newSmallHeader = newSmallHeaderRecord;
    LNPointer newBigHeader = newBigHeaderRecord;
    while(pointer)
    {
        if(pointer->value < num)
        {
            newSmallHeader->next = pointer;
            newSmallHeader = pointer ;
        }
        else
        {
            newBigHeader->next = pointer;
            newBigHeader = pointer ;
        }
        pointer= pointer->next;
    }
    newSmallHeader->next = newBigHeaderRecord->next;
    newBigHeader->next = NULL;
    return newSmallHeaderRecord->next;
}
