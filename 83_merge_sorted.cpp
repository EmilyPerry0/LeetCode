class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> orig_nums1 = nums1;
        int placeIn1 = 0;
        int placeIn2 = 0;
        for(int i = 0; i < m+n; ++i){
            if(placeIn2 < n && (placeIn1 >= m || nums2.at(placeIn2) < orig_nums1.at(placeIn1))){
                nums1[i] = nums2.at(placeIn2);
                placeIn2++;
            }else{
                nums1[i] = orig_nums1.at(placeIn1);
                placeIn1++;
            }
        }
    }
};