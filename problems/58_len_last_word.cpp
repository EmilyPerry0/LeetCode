class Solution {
public:
    int lengthOfLastWord(string s) {
        // loop through s
        // if curr char is a space, reset counter to 0 and save last word length if it was a word
        // if not, increment 1
        // return the length of the last word
        int len = 0;
        int lastWordLen;
        for(int i = 0; i < s.size(); ++i){
            if(s.at(i) == ' '){
                if(len > 0){
                    lastWordLen = len;
                }
                len = 0;
            }else if(i == s.size() - 1){
                lastWordLen = len + 1;
            }else{
                len++;
            }
        }
        return lastWordLen;
    }
};