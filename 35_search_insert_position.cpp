class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // just binary search?
        int lower = 0;
        int higher = nums.size() - 1;
        int searchIdx = -1;
        while(lower <= higher){
            searchIdx = (higher+lower) / 2;
            if(nums.at(searchIdx) == target){
                return searchIdx;
            }else if(nums.at(searchIdx) > target){
                higher = searchIdx - 1;
            }else{
                lower = searchIdx + 1;
            }
        }
        if(target < nums.at(searchIdx)){
            return searchIdx;
        }else{
            return searchIdx + 1;
        }
    }
};