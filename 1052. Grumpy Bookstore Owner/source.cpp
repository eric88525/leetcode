class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {       
        
        int happy=0,more_happy=-1;
        int temp = 0; 
        
        for(int i=0;i<customers.size();i++){              
            //boss happy or not
            happy += grumpy[i] ? 0:customers[i];
            // find max more happy
            // add current cus
            temp  +=   grumpy[i] ? customers[i]:0;
            // sliding window: pop first add last
            if(i>=X) temp -= grumpy[i-X] ? customers[i-X]:0;
            more_happy =  max(more_happy,temp) ;
        }  
        return happy+more_happy;
    }
};
