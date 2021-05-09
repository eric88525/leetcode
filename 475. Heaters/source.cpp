class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int max_distant = -100;
        int distant;
        sort (heaters.begin(), heaters.end());
        for( int i=0;i<houses.size();i++){
            
            int h = lower_bound( heaters.begin(),heaters.end(), houses[i])-heaters.begin();
            if ( h==0){
                distant =  abs(houses[i]-heaters[h]);
            }else {
                if ( h < heaters.size() ){
                    distant = min( abs(houses[i]-heaters[h]) , abs(houses[i]-heaters[h-1]));
                }else{
                    distant = abs(houses[i]-heaters[heaters.size()-1]) ;
                }
            }
            max_distant = max( distant , max_distant ) ;                            
        }       
        return max_distant;
    }
};