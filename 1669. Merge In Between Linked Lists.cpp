/// @author Merna Islam
/// @date 20/03/2024.
/// @link https://leetcode.com/problems/merge-in-between-linked-lists/


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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int idx = 1;
        ListNode* beforeA = list1;
        while(idx != a){
            beforeA = beforeA->next;
            ++idx;
        }

        ListNode* afterB = beforeA->next;
        ++idx;
        beforeA->next = list2;
        while(idx != b+2){
            afterB = afterB->next;
            ++idx;
        }

        ListNode* endOfList2 = list2;
        while(endOfList2->next != nullptr){
            endOfList2 = endOfList2->next;
        }

        endOfList2->next = afterB;
        return list1;
    }
};