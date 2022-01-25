class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> intervals1;
        stack<int> s1,s2;
        for (int i = 0; i < intervals.size(); i++){
            for (int j = 0; j < intervals[i].size(); j++){
                s1.push(intervals[i][j]);
                // intervals[i][j] = NULL;
            }   
        }
        // intervals.clear();
        s2.push(s1.top());
        s1.pop();
        while(!s1.empty()){
            if(s1.size() == 1){
                s2.push(s1.top());
                s1.pop();
            }
            else{
                int v1 = s1.top();
                s1.pop();
                if(v1 <= s1.top()){
                    s1.pop();
                }
                else{
                    s2.push(v1);
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        
        
        for(int i=0; i< intervals.size(); i++){
            for(int j=0; j<intervals[i].size(); j++){
                if(!s2.empty()){
                    intervals[i][j] = s2.top();
                    s2.pop();
                }
                else{
                    // intervals.erase(intervals.begin() + i );
                    
                }
                
            }
        }
        // intervals.resize(intervals.size() - 1);
        return intervals;
    }
};