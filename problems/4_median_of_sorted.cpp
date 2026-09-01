class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // compare the two medians. if same, that's answer.
        // if median_1 > median_2, repeat with first half of arr_1 and second half of arr_2 (otherwise, swap)
        double median_1 = getMedian(nums1);
        double median_2 = getMedian(nums2);
        if(median_1 == median_2){
            return median_1;
        }else if (median_1 > median_2){
            return findMedianSortedArrays(vector<int>& sub_1(nums1[0], nums1[nums1.size()/2]), vector<int>& sub_2(nums2[nums2.size()/2 + 1], nums2[nums2.size()]);
        }else{
            return 0.0;
        }


    }

    double getMedian(vector<int>& nums){
        if(nums.size() == 1){
            return nums.at(0);
        }else if(nums.size() % 2 == 1){
            return nums.at(nums.size() / 2); 
        }else{
            return (nums.at(nums.size() / 2) + nums.at(nums.size() / 2 - 1)) / 2.0;
        }
    }
};