class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // 依照結束時間排序
        sort( intervals.begin() , intervals.end() , [](vector<int> &a , vector<int>&b){return a[1] < b[1]; }  ); 

        int removeNums=0 ,lastEnd = intervals[0][1];


        for(int i=1;i< intervals.size();i++){    

            // 每次紀錄上次的結束時間點     
            if(  lastEnd >  intervals[i][0]   ){
                removeNums++;
            }else{
                // 沒overlap 更新時間點
                lastEnd =   intervals[i][1] ;
            }       
        }
        return removeNums;
    }
};