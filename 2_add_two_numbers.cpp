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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // while both of the next are not null
            // make a new ListNode
            // if only one next is not null:
                // that is the new current ListNode and we are done
            // else:
                // sum = add up two current vals
                // val = sum of the two % 10 + previous remainder
                // (int) new previous remainder = val / 10
        int prevRemainder = 0;
        ListNode* prevNode = new ListNode();
        ListNode* headNode = new ListNode();

        // set first one
        int sum = l1->val + l2->val;
        int currVal = sum % 10 + prevRemainder;
        prevRemainder = (sum + prevRemainder) / 10;
        headNode->val = currVal;
        prevNode->next = headNode;
        prevNode = headNode;

        ListNode* currL1 = l1->next;
        ListNode* currL2 = l2->next; // are these necessary?


        while(currL1 != nullptr || currL2 != nullptr){
            if(currL1 == nullptr){
                int currVal = (currL2->val + prevRemainder) % 10;
                prevRemainder = (currL2->val + prevRemainder) / 10;
                ListNode* currListNode = new ListNode(currVal, nullptr);
                prevNode->next = currListNode;
                prevNode = currListNode;
                currL2 = currL2->next;
            }else if(currL2 == nullptr){
                int currVal = (currL1->val + prevRemainder) % 10;
                prevRemainder = (currL1->val + prevRemainder) / 10;
                ListNode* currListNode = new ListNode(currVal, nullptr);
                prevNode->next = currListNode;
                prevNode = currListNode;
                currL1 = currL1->next;             
            }else{
                int sum = currL1->val + currL2->val;
                int currVal = (sum + prevRemainder) % 10;
                prevRemainder = (sum + prevRemainder) / 10;
                ListNode* currListNode = new ListNode(currVal, nullptr);
                prevNode->next = currListNode;
                prevNode = currListNode;
                currL1 = currL1->next;
                currL2 = currL2->next;
            }
        }

        if(prevRemainder != 0){
            ListNode* currListNode = new ListNode(prevRemainder, nullptr);
            prevNode->next = currListNode;
        }
        return headNode;
    }
};