# 668. Kth Smallest Number in Multiplication Tables

+ 問題是想找出在array中，第k個最小數
+ 解可以用 binart search 來找到某個 N ， 且在矩陣中小於N的數字數量應該 <小於K個



|N| 1    | 2    | 3    | 4    | 5    | 6    |
|----| ---- | ---- | ---- | ---- | ---- | ---- |
|number smaller than N | 0    | 1    | 3    | 5    | 6    | 7    |



```C++
class Solution {
public:
    // return how many number in array is smaller than num
    int kSmaller(int n, int m, int num ) {

        int c =0;
        for (int i = 1; i <= n; ++i) {
            // 可以直觀的理解為，將 num 每 i個分成一堆，能分成幾堆
            // i = 1 => 1 2 3 4
            // i = 2 => 2 4 6 8
            c += min(  m , num/i );
        }
        return c;
    }

    int findKthNumber(int m, int n, int k) {

        int lo = 1 , high = m*n;

        while( lo < high ){
            
            int mid = lo + (high-lo)/2;
            int smaller_than_mid = kSmaller(n,m,mid);

            if ( smaller_than_mid < k  ) {
                lo = mid + 1;
            }else{
                high = mid;
            }
        }
        return lo;
    }
};
```

