class Solution {
public:
       
    int findKthLargest(vector<int>& nums, int k) {     
        buildMaxHeap(nums);       
        int heapSize = nums.size();
        
        // 要找地k大 就要做k-1次
        for( int i=0 ; i<k-1 ; i++ ){            
            swap( nums[0] , nums[--heapSize]);      
            // 被交換去最後的 就直接忽略它
            // 因此heapsize會逐漸變少
            heapify(nums,0,  heapSize);
        }      
        return nums[0];
    }
    
    // 重新調整堆積的過程
    void heapify(vector<int> &nums , int i , int heapSize) {
      
        int largest = i , left = (i << 1) +1 , right = (i<<1)+2;

        // 在比大小同時，也要確認節點存在
        if (left < heapSize &&  nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < heapSize &&  nums[right] > nums[largest]) {
            largest = right;
        }
        
        // 如果需要替換 就替換
        if (i != largest) {
            swap(nums[i], nums[largest]);
            heapify(nums, largest, heapSize);
        }
    }

    // 建立maxHeap
    void buildMaxHeap( vector<int> &nums  ) {

        int heapSize = nums.size();

        // 從最後一個父節點開始檢查大小
        int lastNode = (heapSize >> 1) - 1;

        for (int i = lastNode; i >= 0; i--) {
            heapify(nums, i, heapSize);
        }
    }    
 
};