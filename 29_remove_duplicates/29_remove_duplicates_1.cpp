#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       //next idea: one marker for the next index to change, one marker for the current index to analyze
       // if the value at the current marker is the same as the one at the next index to change, skip it and increment the current marker.
       // return the current marker + 1 as the next value to change
       int lastChangedIndex = 0;
       for(int i = 1; i < nums.size(); ++i){
        if(nums.at(i) != nums.at(lastChangedIndex)){
            lastChangedIndex++;
            nums.at(lastChangedIndex) = nums.at(i);
        }
       }
       return lastChangedIndex + 1;
    }
};