#include <iostream>
#include <map>
using namespace std;

//定义结构体
typedef struct ListNode{
    int value;      // 值域
    ListNode *next,*random; // 指针域
}*LNPointer; // 结构体定义结尾处要加分号

/**
 * 题目：2个已排序链表的合并
 * 思想：使用临时结点
 */
int main(int argc, char const *argv[])
{
     // 链表初始化 start
    ListNode a1;    
    ListNode a2;    
    ListNode a3;    
    ListNode a4;    
    ListNode b1;
    ListNode b2;
    ListNode b3;
    ListNode b4;
    
    a1.value=10;
    a2.value=30;
    a3.value=50;
    a4.value=70;
    b1.value=20;
    b2.value=40;
    b3.value=100;
    b4.value=200;
    
    a1.next = &a2;    
    a2.next = &a3;    
    a3.next = &a4;    
    a4.next = NULL;    
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = NULL;
    // 链表初始化 end

    ListNode node  = {0,NULL};
    LNPointer tempNode  = &node;
    LNPointer pointer  = tempNode;
    LNPointer l1  = &a1;
    LNPointer l2  = &b1;
    while(l1 && l2)
    {
        if(l1->value <= l2->value)
        {
            tempNode->next = l1; 
            l1 = l1->next;
        }else
        {
            tempNode->next = l2; 
            l2 = l2->next;
        }
        tempNode = tempNode->next;
    }
    if(l1)
    {
        tempNode ->next = l1; // 剩下的字串直接拼接
    }
    if(l2)
    {
        tempNode ->next = l2;
    }

    cout << "new array:" << endl;
    while(pointer)
    {
        cout << pointer->value << endl;
        pointer = pointer->next;
    }
    system("pause");
   
    return 0;
}
