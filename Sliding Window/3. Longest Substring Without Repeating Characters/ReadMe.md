# 3. Longest Substring Without Repeating Characters

- 用 start 來記錄不重複字母的起始點
- 如果之前看過某字母，當倫的 start 應該從他的下一位置開始 例如:
  - [a b c a b c b b] 碰到第二次 a 時，start 應該更新為 `上一次見到a的位置+1`
  - 如果都沒重複，那 start 維持在 0

```cpp
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> last_index(255, -1);
        int ans = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            start = max(start, last_index[s[i]]);
            ans = max(i - start + 1, ans);
            last_index[s[i]] = i + 1;
        }
        return ans;
    }
};
```
