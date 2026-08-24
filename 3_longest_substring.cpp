#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int longestSubstringSoFar = 0;
      map<char, std::string::size_type> charsInCurrSubstring;
      std::string::size_type left_idx = 0;
      
      for(std::string::size_type right_idx = 0; right_idx < s.size(); ++right_idx)
      {
        if(charsInCurrSubstring.contains(s[right_idx]))
        {
            while(left_idx <= charsInCurrSubstring[s[right_idx]])
            {
                charsInCurrSubstring.erase(s[left_idx]);
                ++left_idx;
            }
        }
        charsInCurrSubstring[s[right_idx]] = right_idx;

        if(right_idx - left_idx + 1 > longestSubstringSoFar)
        {
            longestSubstringSoFar = right_idx - left_idx + 1;
        }
      }
      return longestSubstringSoFar;
    }
};