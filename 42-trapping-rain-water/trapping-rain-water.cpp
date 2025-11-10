class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>rightMax(n);

        int leftMax = height[0];
        rightMax[n-1] = 0;


        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        } cout << endl;

        int water = 0;

        for(int i=1; i<n; i++){
            int wt = min(leftMax, rightMax[i]) - height[i];
            if(wt>0)water +=wt ;
            leftMax = max(leftMax, height[i]);
        }

        return water;
    }
};