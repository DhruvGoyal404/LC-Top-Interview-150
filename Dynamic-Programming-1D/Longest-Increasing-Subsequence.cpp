// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution{
public:
    int findLongestChain(vector<int>& pairs) {
        int n = pairs.size();
        vector<int> t(n, 1);
        int maxL = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[j] < pairs[i]){
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        return maxL;
    }

    int lengthOfLIS(vector<int> &nums){
        return findLongestChain(nums);
    }
};