class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasum = 0, costsum = 0;
        for(int i = 0; i<gas.size(); i++){
            gasum += gas[i];
            costsum += cost[i];
        }
        if(gasum<costsum) return -1;
        int store = 0, start = 0;
        for(int i = 0; i<gas.size(); i++){
            if(store+gas[i]<cost[i]){
                store = 0;
                start = i+1;
            }
            else
                store += gas[i]-cost[i];
        }
        return start;
    }
};
