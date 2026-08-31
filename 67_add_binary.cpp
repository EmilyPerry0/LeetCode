class Solution {
public:
    string addBinary(string a, string b) {
        int longestLen = std::max(a.size(), b.size());
        string result = "";
        bool carryOver = false;
        for(int i = 0; i < longestLen; ++i){
            string aDigit, bDigit;
            if(i >= a.size()){
                bDigit = b[b.size() - i - 1];
                aDigit = "0";
            }else if(i >= b.size()){
                aDigit = a[a.size() - i - 1];
                bDigit = "0";
            }else{
                aDigit = a[a.size() - i - 1];
                bDigit = b[b.size() - i - 1];
            }
            if((aDigit == "1" && bDigit == "0" && !carryOver) || (bDigit == "1" && aDigit == "0" && !carryOver) || (aDigit == "0" && bDigit == "0" && carryOver)){
                result = "1" + result;
                carryOver = false;
            }else if(!carryOver && aDigit == "0" && bDigit == "0"){
                result = "0" + result;
            }else if(carryOver && aDigit == "1" && bDigit == "1"){
                result = "1" + result;
            }else{
                result = "0" + result;
                carryOver = true;
            }

        }
        if(carryOver){
            return "1" + result;
        }else{
            return result;
        }
    }
};