class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), mxWater = 0;
        for(int i=0, j=n-1; i<j; ){
            int water = min(height[i], height[j]) * (j-i);
            mxWater = max(mxWater, water);
            if(height[j] >= height[i]){
                i++;
            } else {
                j--;
            }

        }
        return mxWater;
    }
};