class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int leftMax = height[0], rightMax = height[n-1];
        int l = 1, r = n-2, water = 0;

        while(l<=r){
            if(leftMax<rightMax){
                if(height[l] > leftMax){
                    leftMax = height[l];
                } else water += (leftMax - height[l]);
                l++;
            } else {
                if(height[r] > rightMax){
                    rightMax = height[r];
                } else water += (rightMax - height[r]);
                r--;
            }
        }

        return water;
    }
};