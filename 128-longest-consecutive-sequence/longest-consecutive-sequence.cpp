class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;

        if(nums.size() == 0) return 0;
        int ans = 1;

        for(auto x: nums){
            st.insert(x);
        }

        for(auto it: st){

            // just look for first element only
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int crr = it;
                while(st.find(crr+1) != st.end()){
                    cnt++;
                    crr++;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
        
    }
};
