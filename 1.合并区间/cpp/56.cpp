class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> segments;
        for (auto& interval: intervals) {
            if (segments.size() == 0 
                || segments.back().back() < interval[0]) {
                segments.push_back(interval);
            } else if (segments.back().back() < interval[1]){
                segments.back().back() = interval[1];
            }
        }
        return segments;  
    }
};
