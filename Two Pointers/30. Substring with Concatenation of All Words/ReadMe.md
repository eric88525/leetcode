# 30. Substring with Concatenation of All Words

- 當看到重複單字，重複把最前面的單字去掉直到把重複的排除
- 不相關的單字，清空所有，並把 start 設為他的一個位置

```cpp
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        // 單字長度 n
        int n = words[0].size();
        // voc 用來記錄 word 單字的出現數量
        map<string,int> voc;
        vector<int> ans;

        for(auto w:words)
            voc[w]++;

        // 由於每次會取 n 長度的單字來判斷，因此起始點要檢查 n 次
        // 想像 words 只有一個單字，要在任何情況都能檢測到此單字的話，勢必得從 0~n-1 為起始
        for(int i=0;i<n;i++){

            int start = i,end = i; // 紀錄開始搜尋 index 和下次取單字的 index
            int count = 0;  // 當 count == words 的數量代表此字串符合要求
            map<string,int> seen; // 記錄看過什麼單字

            while(end < s.size()){
                string w = s.substr(end,n);
                end += n;

                if(voc.count(w)){
                    seen[w]++;
                    count++;
                    // 遇到重複 依序刪除最早看過的單字直到刪除重複單字
                    while(seen[w] > voc[w]){
                        seen[s.substr(start,n)]--;
                        start += n;
                        count--;
                    }
                    if(count == words.size()){
                        ans.push_back(start);
                    }
                }else{ //遇到不符合的單字 跳過並清空 seen
                    start = end;
                    count = 0;
                    seen.clear();
                }
            }
        }

        return ans;
    }
};

```
