
## 為了防止overflow
```cpp
if (dividend == INT_MIN && divisor == -1) {
  return INT_MAX;
}
```

## 概念
1. 不斷地讓被除數減去 除數*倍率 來求倍率總和
+  假設 15 / 3
  1. 3 -> 6 -> 12 -> 24(超過了)
  2. 可知 15 = 3 * 4 + 3
  3. 然後再對餘數做一次相同的事情 可得 3 = 3 * 1 + 0
  4. 把 4 和 1 相加，可得到 5()