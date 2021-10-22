# 496. Next Greater Element I

Monotonic Stack 
單調的stack，裡面的每元素按造遞增或遞減排序
https://haogroot.com/2020/09/01/monotonic-stack-leetcode/
time: O(N)

## idea

+ 從頭開始檢視nums2，如果stack裡面有比nums2[i]還小的數字，那麼使其對應的 first greater element 等於nums2[i]，直到stack裡面所有的數字都比nums2[i]還小。
+ 概念就是每看一個數字，就替他找到比他大的數字並記錄index


```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>s;
        
        unordered_map<int,int> pos;
        
        for(auto n:nums2){
            while(s.size() && s.top()<n){   
                pos[ s.top() ] = n;
                s.pop();
            }
            s.push(n);
        }
        
        vector<int> ans;
        
        for(int n:nums1) {
            ans.push_back( pos.count(n)?pos[n]:-1   ) ;
        }
        return ans;
    }
};
```

