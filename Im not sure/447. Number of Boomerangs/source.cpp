
class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {      
		int ans = 0;
        
        // distance_map紀錄 
        // <距離:點數量>	
        unordered_map<int, int > distance_map;
        
        // 對每個點都跑一次 檢查和其他點的距離 存入distance_map
		for (int i = 0; i < points.size(); i++) {
					
			for (int j =0 ; j < points.size(); j++) {  
                
                // 自己不記錄自己
                if(i==j) continue;      
                
                // 算距離
				int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + 
                               (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
				distance_map[distance]++;
			}
            
            // 假設跟x距離為4的點有n個
            // 那排列組合就會有n*(n-1)種
			for (auto x : distance_map) {
                if(x.second<2) continue;
				ans += x.second*(x.second - 1);
			}
            distance_map.clear();
		}
		return ans;
	}
};