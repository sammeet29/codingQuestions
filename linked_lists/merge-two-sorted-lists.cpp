/***************************************************************************************************
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

***************************************************************************************************/
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
        if(list1 == nullptr){
            return list2;
        }
        
        if(list2 == nullptr){
            return list1;
        }
        
        bool merge_complete {false};
        ListNode *root {nullptr};
        ListNode *prev {nullptr};
        while(!merge_complete)
        {
            ListNode* current {nullptr};
            if(list1 != nullptr && list2 != nullptr){
                // add the lower number to the list
                if(list1->val < list2->val){
                    current = list1;
                    list1 = list1->next;
                }else{
                    current = list2;
                    list2 = list2->next;
                }
            }else if(list1 == nullptr){
                current = list2;
                merge_complete = true;
            }else if(list2 == nullptr){
                current = list1;
                merge_complete = true;
            }
            
            if(root == nullptr){
                root = current;
            }else{
                prev->next = current;
            }
            
            prev = current;
        }
        
        return root;
    }
};
