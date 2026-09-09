// https://leetcode.com/problems/ipo/description/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> mp;
        for(int i=0; i<profits.size(); i++) mp.push_back({capital[i], profits[i]});
        sort(mp.begin(), mp.end());
        int i=0;
        priority_queue<int> pq;
        while(k--){
            while(i<profits.size() && mp[i].first <= w){
                pq.push(mp[i].second);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};