class Solution {
public:
    int strStr(string haystack, string needle) {
        // loop through each substring in haystack. check needle length substring of haystack. if not there, keep going until end of haystack or needle found or not enough room to check for the next needle.
        for(int i = 0; i < haystack.size() && i + needle.size() <= haystack.size(); ++i){
            if(haystack.substr(i, needle.size()).compare(needle) == 0){
                return i;
            }
        }
        return -1;
    }
};