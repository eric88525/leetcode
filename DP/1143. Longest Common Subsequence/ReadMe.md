

# 1143. Longest Common Subsequence

https://www.youtube.com/watch?v=NnD96abizww&ab_channel=TusharRoy-CodingMadeSimple

dp(i,j) : 在s1 的 i 和 s2 的 j 位置時候的最大長度

if s1[i] == s2[j] , dp(i,j) = dp(i-1,j-1) + 1 前一個字母的最大長度+1

else  dp(i,j) = max(dp(i-1,j)  dp(i,j-1)) 

```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        
        int n1 = text1.size() , n2 = text2.size();
        
        vector<vector<int>> dp( n1+1 ,  vector<int>(n2+1,0) );
        
        
        for(auto i=1;i<=n1;i++){
            
            for(auto j=1;j<=n2;j++){
                
                if( text1[i-1] == text2[j-1] ){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max( dp[i-1][j] ,dp[i][j-1] ); 
                }
            }         
        }    
        return dp[n1][n2]; 
    }
};
```

