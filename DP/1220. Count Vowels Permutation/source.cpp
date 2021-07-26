class Solution {
public:
    
    // canFollow[i] 表示前面能出現誰
    // 0 = a  1 = e 2 = i ...
    vector<vector<int>> canFollow = { {1,2,4},{0,2},{1,3},{2},{2,3} };
    
    int countVowelPermutation(int n) {
        

        // 大數修正
        long long fixer = (1e9+7);
        
        // 在前一狀態 對應字母能有幾種組合
        vector<long long> pre_combination(5,1);

        // 紀錄最後的狀態
        vector<long long> all_combination(5,1);
        
        // 從第二個位置開始計算出現種類
        while(--n){
            pre_combination = all_combination;
            for(int i=0;i<5;i++){
                all_combination[i] = 0;
                for(auto &pattern:canFollow[i] ){
                    all_combination[i] += pre_combination[pattern]  ;
                    all_combination[i] %= fixer;
                }        
            }
        }     

        long long  result = 0;

        // 把最後的狀態種類記錄下來
        for(auto &i:all_combination){
            result += i;
        }
        return result %= fixer ; 
    }  
    
};