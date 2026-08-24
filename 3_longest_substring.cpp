#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int longestSubstringSoFar = 0;
      map<char, std::string::size_type> charsInCurrSubstring;
      for(std::string::size_type i = 0; i < s.size(); ++i){
        for(std::string::size_type j = i; j < s.size(); ++j){
            if(!charsInCurrSubstring.contains(s[j])){
                charsInCurrSubstring[s[j]] = j;
                if(j-i+1 > longestSubstringSoFar){
                    longestSubstringSoFar = j-i+1;
                }
            }else{
                i = charsInCurrSubstring[s[j]];
                break;
            }
        }
        charsInCurrSubstring.clear();
      }
      return longestSubstringSoFar;
    }
};