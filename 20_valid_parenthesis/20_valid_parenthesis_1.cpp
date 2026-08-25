// my second attempt (on my own). much better this time.

class Solution {
public:
    bool isValid(string s) {
        // use a stack
        // push for open, pop for close
        // when you go to pop, if its not matching type, false.

        std::stack<char> parentheses;
        std::map<char,char> correspondingCloser = { {'(', ')'}, {'{', '}'}, {'[', ']'}};
        for(std::string::size_type i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                parentheses.push(s[i]);
            }else{
                if(parentheses.empty()){
                    return false;
                }else if(s[i] != correspondingCloser[parentheses.top()]){
                    return false;
                }else{
                    parentheses.pop();
                }
            }
        }
        return parentheses.empty();
    }
};