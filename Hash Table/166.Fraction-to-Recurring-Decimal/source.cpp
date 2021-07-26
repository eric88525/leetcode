class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if (!numerator){
            return "0";
        }
        // 確認正負號
        string result =  (numerator >0 ) ^ (denominator>0)? "-":"" ;
        // 都變正值來運算
        long long n = labs(numerator) , d = labs(denominator) , r = n %d;
        // 加上第一次的商
        result += to_string( n/d );
        // 沒餘數 return
        if (!r){
            return result;
        }
        result += ".";
      
        // 紀錄那些餘數有出現過
        unordered_map<int,int> record;
        
        string decimal = "";
        int i=0;
       
        while(r){
            
            r *= 10;
            // 此餘數出現過 透過value找到曾在哪出現過
            if( record.count( r )  ){
                decimal.insert( record[r] , "(" );
                decimal += ")";
                break;
            }
            
            // r / denominator = a...b
            
            // a=商 b=餘
            int a  = r/d , b = r%d;
          
            record[ r] =  i ;        
            
            decimal += to_string( a );
            r = b;
            i++;
        }
        
        return result + decimal;
    }
};
