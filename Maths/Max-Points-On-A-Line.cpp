// https://leetcode.com/problems/max-points-on-a-line/
class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }

    vector<int> calculateSlope(int x1, int y1, int x2, int y2){
        int k = y2 - y1;
        int l = x2 - x1;
        if(l < 0) {
            k = -k;
            l = -l;
        }
        int p = gcd(k, l);
        k/=p; l/=p;
        return {k, l};
    }

    int maxPoints(vector<vector<int>>& points) {
        int maxi = 1;
        for(int i=0; i<points.size(); i++){
            int first = points[i][0], second = points[i][1];
            map<pair<int, int>, int> mp;
            for(int j=0; j<points.size(); j++){
                if(j == i) continue;
                vector<int> slope = calculateSlope(first, second, points[j][0], points[j][1]);
                mp[{slope[0], slope[1]}]++;
            }
            for(auto it : mp) maxi = max(maxi, it.second+1);
        }
        return maxi;
    }
};