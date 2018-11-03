<script type="text/javascript" async src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML"> </script>

### 一、时间复杂度
1. 如下代码
    ``` c++
    int demoFunc(int n)
    {
        int count = 0;              //运行一次
        for(int i=0;i<n;i++)        //运行n次
        {
            for(int j=0;j<n;j++)    //运行n次
            {
                count++;            //运行n^n次
            }
        }
        return count;               //运行1次
    }
    ```
    则示例代码中所有代码运行的总次数可以用一个函数 __T(n)__ 表示，且T(n)=1+n+n+n^n +1，而当n足够大时，T(n)→n^n，其余项都可以忽略不计,用极限表示就是：$lim\frac{T(n)}{f(n)}=C≠0$，所以用O(f(n))表示算法的时间复杂度

