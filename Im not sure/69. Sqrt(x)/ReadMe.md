# 69. Sqrt(x)
This question can be solved by newton's method. Accrording to newton's method, if we have a equation
$$f(x) = x^2 - N$$
and we start from $x_0$, the $x_1$ would be 

$$x_{n+1} = (x_{n} + \frac{N}{x_{n}})/2$$
Let's try to find the approximately of $sqrt(N)$, denote as $s$,and the approximately number $s$ should follow some rules.
$$
s*s \leq N \\
(s+1)(s+1) >  N
$$

For example:
```cpp
mySqrt(17) = 4 // sqrt(17) = 4.12...
```
$$
4*4 \leq 17\\
(4+1)(4+1) > 17
$$
```cpp
mySqrt(16) = 4 // sqrt(16) = 4
```
$$
4*4 \leq 16\\
(4+1)(4+1) > 16
$$

We can find $s$ by 
```cpp
while (ans * ans > n  || (ans + 1) * (ans + 1) <= n)
    ans = (ans + n / ans) / 2;
```
and start from $x_0 = \frac{N}{2}$, due to 

$$
\frac{N}{2} > \sqrt{N}
$$

## code
```cpp
class Solution {
public:
    int mySqrt(int n) {
        
        if (n == 0)
            return 0;
        if (n < 4)
            return 1;

        unsigned int ans = n / 2;
        if (ans > 65535)  // 65535 = 2^16 - 1
            ans = 65535; // prevent overflow

        while (ans * ans > n  || (ans + 1) * (ans + 1) <= n)
            ans = (ans + n / ans) / 2;
        return ans;
    }
};
```



