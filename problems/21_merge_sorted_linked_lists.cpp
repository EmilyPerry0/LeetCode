/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr){
            return nullptr;
        }
        
        ListNode* headNode = new ListNode(0, nullptr);
        ListNode* currNode;
        ListNode* newNode;
        int currVal = 0;

        if(list2 == nullptr || (list1 != nullptr && list1->val < list2->val)){
            headNode->val = list1->val;
            list1 = list1->next;
        }else{
            headNode->val = list2->val;
            list2 = list2->next;
        }
        currNode = headNode;

        while(list1 != nullptr || list2 != nullptr){
            if(list2 == nullptr || (list1 != nullptr && list1->val < list2->val)){
                currVal = list1->val;
                list1 = list1->next;
            }else{
                currVal = list2->val;
                list2 = list2->next;
            }
            newNode = new ListNode(currVal, nullptr);
            currNode->next = newNode;
            currNode = newNode;
        }
    return headNode;
    }
};