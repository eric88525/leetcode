# 350.Intersection of Two Arrays II

+ 找出兩陣列中重疊的最多元素

先sort，當 a1[i] == a1[j] 時，加入答案

反之調整 i j 的位置

```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {  
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());  
        int i=0 , j=0 ;    
        vector<int> ans;    
        while(i<nums1.size() && j<nums2.size()){    
            if ( nums1[i] < nums2[j]){
                i++;
            }else if (nums1[i] > nums2[j]){
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++,j++;
            }         
        }     
        return ans; 
    }
};
```

