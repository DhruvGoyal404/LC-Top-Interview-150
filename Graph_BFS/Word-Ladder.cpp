// https://leetcode.com/problems/word-ladder/
class Solution {
public:
    vector<string> generateNeighbours(string first){
        vector<string> op;
        for(int i=0; i<first.length(); i++){
            char chr = first[i];
            for(char ch='a'; ch<='z'; ch++){
                if(ch!=chr){
                    first[i] = ch;
                    op.push_back(first);
                }
            }
            first[i] = chr;
        }
        return op;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        queue<pair<string, int>> q;
        // unordered_set<string> visited;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        // visited.insert(beginWord);
        if(st.find(endWord) == st.end()) return 0;
        while(!q.empty()){
            auto it = q.front();
            string word = it.first;
            int level = it.second;
            q.pop();
            if(word == endWord) return level;
            vector<string> ngbr = generateNeighbours(word);
            for(int i=0; i<ngbr.size(); i++){
                string s = ngbr[i];
                // if(st.find(s)!=st.end() && visited.find(s)==visited.end()){
                if(st.find(s)!=st.end()){
                    // visited.insert(s);
                    q.push({s, level+1});
                    st.erase(s);
                }
            }
        }
        return 0;
    }
};