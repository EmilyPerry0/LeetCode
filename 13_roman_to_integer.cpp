#include <map>

class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> lookupTable = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int total = 0;
        // cases:
        // no next number: add the relevant number to the total, return
        // next number bigger: do the relevant substraction and advance two
        // next number smaller: add the relevant number and advance one
        for(std::string::size_type i = 0; i < s.size(); ++i){
            if(i == s.size() - 1){
                return total += lookupTable[s[i]];
            }else if(lookupTable[s[i+1]] > lookupTable[s[i]]){
                total += lookupTable[s[i+1]] - lookupTable[s[i]];
                ++i;
            }else{
                total += lookupTable[s[i]];
            }
        }
        return total;
    }
};