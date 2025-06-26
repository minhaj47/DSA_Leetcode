class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k=k%n;
            reverse(nums, 0, n-1);
            reverse(nums, 0, k-1);
            reverse(nums, k, n-1);
        }
        void reverse(vector<int>&arr, int start, int end){
            for(int i=start, j=end; i<j; i++, j--){
                swap(arr[i], arr[j]);
            }
        }
    };