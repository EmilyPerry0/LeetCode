class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int currDigitIndex = digits.size() - 1;
        while(currDigitIndex >= 0 && digits.at(currDigitIndex) == 9){
            digits.at(currDigitIndex) = 0;
            currDigitIndex--;
        }
        if(currDigitIndex < 0){
            digits.insert(digits.begin(), 1);
        }else{
            digits.at(currDigitIndex) = digits.at(currDigitIndex) + 1;
        }
        return digits;
    }
};