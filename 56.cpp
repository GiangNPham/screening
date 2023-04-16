class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b){
            return a[0] < b[0];
        });
        int start = intervals[0][0], ending = intervals[0][1];
        if (intervals.size() == 1){
            ans.push_back({start, ending});
            return ans;
        }
        for (int i = 1; i < intervals.size(); i++){
            vector<int> cur = intervals[i];
            if (cur[0] <= ending){
                ending = max(cur[1], ending);
            }
            else {
                ans.push_back({start, ending});
                start = cur[0], ending = cur[1];
                
            }
            if (i == intervals.size() - 1){
                ans.push_back({start, ending});
            }
        }
        return ans;
    }
};

// 2 submissions