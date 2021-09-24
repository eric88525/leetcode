#  139. Word Break

+ 用dp[i] 來代表 此處是合法結尾的右側邊界
+ 例如

```
dict = ["leet"]

0 1 2 3 4 5 6 7 8
  l e e t c o d e
==================
t f f f f t f f f
```

+ 進行枚舉，讓 i 從頭跑到尾，往左延伸字串

```
i = 1
l
==========
i=2
e
le
==========
i=3
e
ee
lee
===========
```

+ 如果 dp[j] == true 代表有前一個字串拼在前面，可以接續著拼
+ 最後return dp[last]

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int> dict;
        for(auto w:wordDict){
            dict[w]=1;
        }
        
        vector<bool> dp(s.size()+1,false);
        
        dp[0] = true;
        
        for(int i=1;i<=s.size();i++){         
            for(int j=i-1;j>=0;j--){ 
                
                if (dp[j]){
                    
                    string word = s.substr(j,i-j);
                    
                    if (dict.count(word)){
                        dp[i] = true;
                        break;
                    }                   
                }        
            }
        }
        return dp[dp.size()-1]  ; 
    }

};
```

