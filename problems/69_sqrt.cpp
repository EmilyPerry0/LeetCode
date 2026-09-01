#include <limits>
class Solution {
public:
    int mySqrt(int x) {
        // i believe binary search is a great thing to use here, let's find out.
        int imax = std::numeric_limits<int>::max();

        if(x == 1 || x == 0){
            return x;
        }

        int lower = 0;
        int higher = std::min(x, 46340);
        int searchNum = (higher + lower) / 2;
        
        while(!(searchNum * searchNum == x || searchNum * searchNum < x && (searchNum+1) * (searchNum+1) > x)){
            searchNum = (higher + lower) / 2;
            if(searchNum >= 46340){
                return 46340;   
            }else if(searchNum * searchNum > x){
                higher = searchNum - 1;
            }else{
                lower = searchNum + 1;
            }
        }
        return searchNum;
    }
};