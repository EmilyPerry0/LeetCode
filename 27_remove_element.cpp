class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // idea: one pointer that starts at the end. loop through nums. if nums at i is val, replace it with the number at the pointer that stared from the end. once i is past the pointer, we are done. return pointerIndex + 1
        int pointerIndex = nums.size() - 1;
        for(int i = 0; i < nums.size() && i <= pointerIndex; ++i){
            while(nums.at(pointerIndex) == val){
                pointerIndex--;
                if(pointerIndex < 0 || i > pointerIndex){
                    goto endloop;
                }
            }
            if(nums.at(i) == val){
                nums.at(i) = nums.at(pointerIndex);
                pointerIndex--;
            }
        }
endloop:
        return pointerIndex + 1;
    }
};