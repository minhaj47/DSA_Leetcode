class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>merged;
        int n = intervals.size(), i=0;

        while(i<n && intervals[i][1] < newInterval[0]) merged.push_back(intervals[i++]);

        int start = newInterval[0]; 
        int end = newInterval[1];

        while(i<n && intervals[i][0] <= newInterval[1]) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        merged.push_back({start, end});

        while(i<n) merged.push_back(intervals[i++]);

        return merged;
    }
};