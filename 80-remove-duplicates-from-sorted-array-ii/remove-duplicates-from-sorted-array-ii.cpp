class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // if (n == 0) return 0;

        int j = 0, cnt = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
                cnt = 1;
            } else if (cnt < 2) {
                nums[++j] = nums[i];
                cnt++;
            }
        }

        return j + 1;
    }
};
