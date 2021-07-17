class Solution {
public:
    int myAtoi(string s) {
        
        int i=0 , sign = 1;
        
        while(s[i]==' ') i++;
         
        if( s[i]=='-' ){
            sign*=-1;
            i++;
        }else if(  s[i]=='+'  ){
            i++;
        }
        
        while(s[i]=='0')i++;
             
        int e=i ;
        
        long long int  ans = 0 , bits=1 ;
            
        while( '0'<=s[e] && s[e] <='9'  ){           
            e++;
        }
        
        if(e==i) return 0;
        
        e-=1;
        
        for(e;e>=i;e--){
            
            ans += bits * int(s[e]-'0');  
            
            if(  ans >  INT_MAX   || bits>INT_MAX ){
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            
            bits *= 10;
        }
            
        return ans*sign; 
    }
};