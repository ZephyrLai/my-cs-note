#include <iostream>
using namespace std;

//定义结构体
typedef struct ListNode{
    int value;      // 值域
    ListNode *next; // 指针域
}*LNPointer; // 结构体定义结尾处要加分号


int main(int argc, char const *argv[])
{
    // 链表初始化 start
    ListNode a;    
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;
    ListNode f;
    a.value=10;
    b.value=20;
    c.value=30;
    d.value=40;
    e.value=50;
    f.value=60;
    a.next = &b;    // 注意要加取地址符
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;  // NULL 大写   
    f.next = NULL;  // NULL 大写   
    ListNode *pointer = &a;
    cout << "origin array:" << endl;
    while(pointer)
    {
        cout << pointer->value << endl;
        pointer = pointer->next;
    }
    // 链表初始化 end
    int beginIndex = 2; // 逆序起始位置
    int endIndex = 4; // 逆序终止位置
    int count = endIndex - beginIndex +1; // 逆序长度，注意要+1
    pointer = &a;
    LNPointer preHeader = NULL;
    LNPointer header = pointer;
    LNPointer subTail = NULL;
    LNPointer newHeader = NULL;
    LNPointer next = NULL;
    while(header && beginIndex--)
    {
        preHeader = header;
        header = header->next;
    }
    subTail = header;
    // 子列逆序
    while(count--)
    {
        next = header -> next;
        header->next = newHeader;
        newHeader = header;
        header = next;
    }
    subTail->next = header;
    preHeader->next = newHeader;
    
    // 输出结果
    pointer = &a;
    cout << "new array:" << endl;
    while(pointer)
    {
        // 只有用指针指向的结构体才可以使用 -> 
        cout << pointer->value << endl;
        pointer = pointer->next;
    }
    system("pause");
    return 0;
}
