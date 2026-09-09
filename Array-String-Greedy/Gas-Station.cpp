// https://leetcode.com/problems/gas-station/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // BRUTEFORCE
        // int n = gas.size();
        // for(int i=0; i<n; i++){
        //     if(gas[i] < cost[i]) continue;
        //     int j = (i+1)%n;
        //     int costForMovingFromThisStation = cost[i];
        //     int gasEarnInNextStationJ = gas[j];
        //     int currGas = gas[i] - costForMovingFromThisStation + gasEarnInNextStationJ;
        //     while(j!=i){
        //         if(currGas < cost[j]) break;
        //         int costForMovingFromThisJ = cost[j];
        //         j = (j+1)%n;
        //         int gasEarnInNextStationJ = gas[j];
        //         currGas = currGas - costForMovingFromThisJ + gasEarnInNextStationJ;
        //     }
        //     if(j==i) return i;
        // }
        // return -1;

        // GREEDY!!!!!!!!
        int k = accumulate(gas.begin(), gas.end(), 0);
        int p = accumulate(cost.begin(), cost.end(), 0);
        if (k<p) return -1;
        int total = 0;
        int result = 0;
        for(int i=0; i<gas.size(); i++){
            total=total + gas[i] - cost[i];
            if(total < 0){
                total = 0;
                result = i+1;
            }
        }
        return result;
    }
};