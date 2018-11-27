#include <iostream>
#include <map>
using namespace std;

//定义结构体
typedef struct ListNode{
    int value;      // 值域
    ListNode *next,*random; // 指针域
}*LNPointer; // 结构体定义结尾处要加分号

/**
 * STL map 基本使用
 */
int main(int argc, char const *argv[])
{
    ListNode a = {10,NULL};    
    ListNode b = {20,NULL};
    ListNode c = {30,NULL};
    ListNode d = {40,NULL};
    ListNode e = {50,NULL};
    a.next = &b;   
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;  

    map<int,LNPointer> dataMap;
    dataMap[a.value]=&a;
    dataMap[b.value]=&b;
    dataMap[c.value]=&c;
    cout << dataMap[10]->value << endl;
    cout << dataMap[20]->value << endl;
    cout << dataMap[30]->value << endl;

    system("pause");
    /* code */
    return 0;
}