class Solution {
public:
    bool isPalindrome(int x) {
        // reverse number without string
        // credit to Ashok Varma. I am just reproducing for learning sake
        
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        
        long reversed_num = 0;
        int orig_num = x;
        while(x != 0){
            reversed_num = x % 10 + 10 * reversed_num;
            x = x / 10;
        }
        return reversed_num == orig_num;
    }
};