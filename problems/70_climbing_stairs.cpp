#include <map>

class Solution {
public:
    std::map<int,int> solvedMap;
    int climbStairs(int n) {
        // recursion
        if(this->solvedMap.contains(n)){
            return this->solvedMap.at(n);
        }else if(n == 1){
            return 1;
        }else if(n == 2){
            return 2;
        }else{
            int left = climbStairs(n-1);
            int right = climbStairs(n-2);
            this->solvedMap[n] = left + right;
            return left+right;
        }
    } 
};