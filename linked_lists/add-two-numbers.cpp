/***************************************************************************************************
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
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
