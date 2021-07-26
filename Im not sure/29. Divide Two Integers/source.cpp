class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // speciall case (overflow)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
      
        // decide the sign (use xor)
        long sign = dividend >0 ^ divisor>0 ? -1:1;
        
        long _dividend  =  labs(dividend) ;    
        long _divisor  =  labs(divisor) ; 
        long ans = 0;
        while(_dividend >= _divisor){
            
            long count=1;
            long temp = _divisor; 
     
          while( temp << 1  <= _dividend ){
                count <<=1;
                temp <<= 1;   
            }
            _dividend -= temp;
            ans += count;
        }
        return sign * ans;
    }
};
