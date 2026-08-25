class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // my thoughts: compare the nth letter of each string until there is a mismatch. store the in progress string along the way
        std::string inProgress = "";

        for(int i = 0; i < strs[0].size(); ++i){
            // compare all to the first string's current letter
            for(int j = 1; j < strs.size(); ++j){
                if(strs[j][i] != strs[0][i]){
                    goto endloop;
                }
            }
            inProgress += strs[0][i];
        }
endloop: // first time using a goto in c++. this is crazy.
    return inProgress;
    }
};