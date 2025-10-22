class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, s = 0;
        unordered_map<int,int>freq;    // <sum, freq>
        
        freq[0] = 1;      
        // when s = k then s-k = 0;  
        //Now if freq[0] = 0 then it will miss the count

        for(int i=0; i<n; i++){
            s+=nums[i];
            cnt += freq[s-k];
            freq[s]++;
        }
        return cnt;
    }
};

