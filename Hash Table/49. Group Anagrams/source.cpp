class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        unordered_map<  string   ,  vector<string>   > record;
        
        for(auto s : strs){
            string temp = s;
            sort(s.begin(),s.end());
            
            record[s].push_back( temp );
            
        }
        
        vector<  vector<string>  > result;
        
        for(auto k:record){
            result.push_back(    k.second    );
        }
        return result;
    }
};
