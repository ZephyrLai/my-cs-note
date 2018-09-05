### 一、定义和使用结构体变量
1. 结构体类型定义  
    1. 由用户自己定义的，将多种不同数据类型的数据组合在一起的数据结构，称为“结构体”（类似于Java中的“对象”）；  
    1. 声明一个结构体的一般形式：  
        struct 结构体名  
            {成员列表};  
        例如：
        ``` c
        struct Student // 习惯将结构体名首字母大写
        {
            int id;         
            char name[10];  
        };
        ```
1. 结构体变量的定义（3种方法）  
    1. 先定义结构体类型，再声明该类型的变量，例  
        ``` c
        // 定义结构体类型
        struct Student 
        {
            int id;         
            char name[10];  
        };  
        ···
        //声明变量
        struct Student student;
        ```
    1. 在声明结构体类型的同时定义结构体变量，例  
        ``` c
        struct Student 
        {
            int id;         
            char name[10];  
        }student01,student02;  // 将变量声明在结构体的最后
        ```
    1. 不指定类型名，直接定义结构体类型变量，例  
        ``` c
        // 没有结构体类型名称
        // 也就是说之后不能声明当前类型的新变量
        struct
        {
            int id;         
            char name[10];  
        }student01,student02;
        ```
1. 结构体变量的基本使用  
    1. 初始化
        ``` c
        // 方式1.在定义结构体的时候，声明变量并初始化
        struct Student
        {
            int id;         
            char name[10];  
        }student01={001,"haha"};
        // 方式2.单独声明变量并初始化
        // 2.1 全部初始化
        struct Student = {001,"haha"};
        // 2.2 部分初始化
        struct Student = {.id=001};
        ```
    2. 引用（形如“链式”）
        ``` c
        // 定义
        struct Date{
            int year;
            int month;
            int day;
        };
        struct Student{
            char name[20];
            struct Date birthday;
        }stu1;
        // 引用
        stu1.name;
        stu1.birthday.year;
        ```
    3. 类型的结构体成员能像普通变量一样进行基本的运算
    4. 同类的结构体变量可以进行赋值运算

### 二、使用结构体数组
1. 定义（2种形式）
    1. 在定义结构体的时候声明，例：
    ``` c
    struct Student{
        char name[20];
    }stu[3];
    ```
    1. 单独定义结构体数组
    ``` c
    struct Student stu[3];
    ```
1. 初始化
### 三、结构体指针
1. 指向结构体变量的指针
1. 指向结构体数组的指针
1. 使用结构体变量、结构体变量的指针作为函数的参数

