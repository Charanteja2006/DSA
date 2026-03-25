class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tot = accumulate(gas.begin(),gas.end(),0);
        int req = accumulate(cost.begin(),cost.end(),0);
        if(req-tot>0) return -1;

        int sum = 0;
        int st = 0;
        for(int i=0;i<n;i++){
            sum += gas[i]-cost[i];
            if(sum<0){
                sum = 0;
                st = i+1;
            }
        }

        return st;
    }
};