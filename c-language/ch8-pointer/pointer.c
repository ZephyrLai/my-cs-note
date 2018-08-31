#include <stdio.h>

// 8.1:通过指针变量访问整型变量
void demo_8_1()
{
    int a=10,b=20;
    int *pointer1,*pointer2;
    pointer1=&a;
    pointer2=&b;
    int pointer3=100;
    printf("c=%p\n",pointer3);
    printf("direct access:a=%d,b=%d \n",a,b);
    printf("indirect access:*pointer1=%d,*pointer2=%d\n",*pointer1,*pointer2);
}

// 8.2:输入两种值，然后从大到小输出
void demo_8_2()
{
    int *p1,*p2,*tp,a,b;
    printf("Please input 2 nums:");
    scanf("%d,%d",&a,&b);
    p1=&a;
    p2=&b;
    if(a<b)
    {
        p1=&b;
        p2=&a;
        /* tp=p1;
        p1=p2;
        p2=tp; */
    }
    printf("a=%d,b=%d",*p1,*p2);
}

// 8.3 同8.2，但将交换数字的代码封装成一个函数（注意处理值传递的问题）
// 这里封装的函数，形参只能是指针变量，不能是int变量
// 
void wrap(int *p1,int *p2)
{
    int tmp = *p1;
    *p1=*p2;
    *p2=tmp;
}
void demo_8_3()
{
    int num1,num2,*point1,*point2;
    printf("please input 2 nums:");
    scanf("%d,%d",&num1,&num2);
    if(num1<num2)
    {
        point1=&num1;
        point2=&num2;
        wrap(point1,point2);
    }
    printf("max:%d,min:%d",num1,num2);
}




int main(int argc, char const *argv[])
{
    // demo_8_1();
    // demo_8_2();
    demo_8_3();
    return 0;

}



