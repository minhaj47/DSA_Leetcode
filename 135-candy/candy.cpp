class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 1, candy = 1;

        while(i<n){
            if(ratings[i] == ratings[i-1]){
                cout << 1 << " ";
                candy++, i++;
                continue;
            }

            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++, i++;
                cout << peak << " ";
                candy+=peak;
            }

            int down = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                cout << down << " ";
                candy+=down;
                i++, down++;
            }

            if(down>peak) candy += (down - peak);
        }
        return candy;
    }
};