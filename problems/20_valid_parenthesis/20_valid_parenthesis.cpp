class Solution {
public:
    bool isValid(string s) {
        // i'm thinking something to do with recusion, maybe?
        // recurse on the substring from the open to the corresponding close
        // if empty, true
        // if we ever fail to find or the first char is a close, false
        if(s.size() == 0){
            return true;
        }else if(s[0] == ']' || s[0] == '}' || s[0] == ')'){
            return false;
        }else{
            int close_idx = findCloser(s, s[0]);
            if(close_idx == -1){
                return false;
            }else{
                return isValid(s.substr(1,close_idx-1)) && isValid(s.substr(close_idx + 1));
            }
        }
    }

    int findCloser(std::string a, char c){
        std::map<char,char> correspondingCloser = { {'(', ')'}, {'{', '}'}, {'[', ']'}};
        char toFind = correspondingCloser[c];
        int numSameOpens = 0;
        for(std::string::size_type i = 1; i < a.size(); ++i){
            if(a[i] == toFind && numSameOpens == 0){
                return i;
            }else if(a[i] == c){
                numSameOpens++;
            }else if(a[i] == toFind){
                numSameOpens--;
            }
        }
        return -1;
    }
};