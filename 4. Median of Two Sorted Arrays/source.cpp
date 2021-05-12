class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()){
            return findMedianSortedArrays( nums2 , nums1  );
        }

        int m = nums1.size() , n = nums2.size();
        
        int max_left =0,max_right = m, half = (m+n+1) / 2;
        
        int max_of_left   = 0,min_of_right =0;
        
        while( max_left <= max_right){
            
            int i = (max_left + max_right )/ 2;
            int j = half-i;
            
            if (  i >0 && nums2[j] < nums1[i-1]){
                max_right = i-1;
            }else if ((i<m) && nums1[i] < nums2[j-1]) {
                max_left = i + 1;
            }else{
                                
                if (i==0)  max_of_left = nums2[j-1]; 
                else if (j==0) max_of_left = nums1[i-1];
                else max_of_left = max( nums1[i-1] , nums2[j-1]  );
                
                if((m+n)%2 == 1){
                    return max_of_left;
                }
                
                if (i==m)  min_of_right = nums2[j]; 
                else if (j==n) min_of_right = nums1[i];
                else min_of_right = min( nums1[i] , nums2[j]  );  
                
                return (max_of_left+min_of_right) / 2.0;

            }
        }    
return 0;
    }      

};
