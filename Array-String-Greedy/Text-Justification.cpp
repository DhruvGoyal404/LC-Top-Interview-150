// https://leetcode.com/problems/text-justification/description/
class Solution {
public:
    int MAX_WIDTH;

    string findLine(int i, int j, int eachGaddhaSpace, int extraGaddhaSpace, vector<string> &words){
        string line;
        for(int k=i; k<j; k++){
            line+=words[k];
            if(k==j-1) continue; // last word of my line -> no space after last word of a line, we would have already added the spaces in all other words apart from last word
            for(int z = 1; z<=eachGaddhaSpace; z++){
                line+=" ";
            }
            if(extraGaddhaSpace > 0){
                line+=" ";
                extraGaddhaSpace--;
            }
        }
        while(line.length() < MAX_WIDTH){
            line+=" ";
        }
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        MAX_WIDTH=maxWidth;

        int i=0;
        while(i<n){
            int lettersCount = words[i].length();
            int j = i+1;
            int gaddhe = 0;
            while(j<n && words[j].length() + 1 + gaddhe + lettersCount <= MAX_WIDTH){
                lettersCount += words[j].length();
                gaddhe+=1;
                j++;
            }

            int remainingSlots = MAX_WIDTH - lettersCount;
            int eachGaddhaSpace = gaddhe == 0 ? 0:remainingSlots / gaddhe;
            int extraSpaceGaddha = gaddhe == 0 ? 0:remainingSlots % gaddhe;
            if(j==n){
                eachGaddhaSpace = 1;
                extraSpaceGaddha = 0;
            }
            result.push_back(findLine(i, j, eachGaddhaSpace, extraSpaceGaddha, words));
            i = j;
        }
        return result;
    }
};