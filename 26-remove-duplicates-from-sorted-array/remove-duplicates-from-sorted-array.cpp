
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            set<int>st;
            for(auto x: nums){
                st.insert(x);
            }
    
            int s = st.size();

            int i=0;
    
            for(auto x: st){
                nums[i]=x;
                i++;
            }
    
            return st.size();
        }
    };