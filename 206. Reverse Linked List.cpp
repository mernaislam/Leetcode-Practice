/// @author Merna Islam
/// @date 21/03/2024.
/// @link https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        vector<int> vec;

        ListNode* current = head;
        while(current != nullptr){
            vec.push_back(current->val);
            current = current->next;
        }
        reverse(vec.begin(), vec.end());

        ListNode* result = new ListNode();
        ListNode* first = result;
        for(int i = 0; i < vec.size(); i++){
            ListNode* temp = new ListNode();
            temp->val = vec[i];
            result->next = temp;
            result = result->next;
        }
        return first->next;
    }
};