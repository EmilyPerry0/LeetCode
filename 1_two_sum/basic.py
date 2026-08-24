class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtable = dict()

        idx = 0
        for num in nums:
            hashtable[num] = idx
            idx += 1

        for num in nums:
            if (hashtable.get(target - num) != None):
                # see if there are multiple values for one key
                
                return [hashtable.get(num), hashtable.get(target-num)]