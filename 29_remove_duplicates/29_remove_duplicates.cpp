#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // initial idea: create a hash table to store the already used numbers.
        // create a new var to keep track of the next index to place the next unique numbers (this will be returned at the end)
        // loop through nums. at each place, if the curr value is not in the hash table, add it, replace the number at nextIndex, increment nextIndex

        int nextIndex = 0;
        std::unordered_map<int, bool> hashTable;
        for(int i = 0; i < nums.size(); ++i){
            if(!hashTable.contains(nums.at(i))){
                hashTable[nums.at(i)] = true;
                nums.at(nextIndex) = nums.at(i);
                nextIndex++;
            }
        }
        return nextIndex;
    }
};