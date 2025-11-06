class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int storage = 0;
        int start = 0,end = 0;
        while(1){
            if(start>=n) return -1;
            storage+=gas[end%n];
            if(storage<cost[end%n]){
                start = ++end;
                storage = 0;
            } else {
                if(start==(end-n)) return start;
                storage-=cost[end%n];
                end++;
            } 
        }
    }
};