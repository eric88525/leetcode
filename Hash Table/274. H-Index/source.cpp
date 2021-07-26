class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort( citations.begin() , citations.end() );
        
        int j ,i;        
        for(  i = citations.size()-1 ,j=1 ; i>=0  ; i--){ 
            
            if ( citations[i] < j  ) break ;
            j++;
        }
     return max( j-1 , 0 );
        
    }
};
