class Solution {
public:
    int countPrimes(int n) {
        
        vector <bool> prime ( n, true);
        int count = 0;      
        for(int i=2 ; i< n ; i++){    
            // 第一次遇到 代表是prime number        
            if ( prime[i] ){
                count ++;
            }
            // 把他的倍數全部標記成 not prime
            for ( int j=2; i*j<n;j++){              
                prime[i*j] = false;
            }             
        }    
        return count;
    }
};