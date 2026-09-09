// https://leetcode.com/problems/insert-delete-getrandom-o1
class RandomizedSet {
public:
    unordered_set<int> st;
    unordered_map<int, int> mp;
    vector<int> temp;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(st.find(val) == st.end()){
            st.insert(val);
            temp.push_back(val);
            mp[val] = temp.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.find(val) != st.end()){
            st.erase(val);
            int k = mp[val];
            int p = temp.back();
            temp[k] = p;
            temp.pop_back();
            mp.erase(val);
            if(p != val) mp[p] = k;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return temp[rand() % temp.size()];
    }
};