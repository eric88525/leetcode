class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> idxmap(255,-1);
        int sidx = 0;
        int max_len = 0;
        
        int n = s.size();
        
        for (int i =0;i<n;i++){
            
            sidx = max(  sidx , idxmap[int(s[i])] + 1 );       
            idxmap[int(s[i])] = i;
            if( i - sidx + 1  > max_len ){             
                max_len =  i - sidx + 1;    
            }        
        }
        return max_len;
        
    }
};
