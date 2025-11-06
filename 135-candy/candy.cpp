class Solution {
public:
    int candy(vector<int>& ratings) {
        // consider left and right neighbour separately 
        // remember higher ratings needs higher no of candy 
        // not necessarily lower should get lower. 
        // As came across left and right lower also get lower by the end. 

        int n = ratings.size();
        vector<int>left(n), right(n);
        left[0] = 1, right[n-1] = 1;

        for(int i=1; i<n; i++){
            left[i] = (ratings[i] > ratings[i-1]) ? left[i-1] + 1 : 1;
        }

        for(int i=n-2; i>=0; i--){
            right[i] = (ratings[i] > ratings[i+1]) ? right[i+1] + 1 : 1;
        }

        int candy = 0;

        for(int i=0; i<n; i++){
            cout << left[i] << " " << right[i] << endl;
            candy += max(left[i], right[i]);
        }

        return candy;
    }
};