/// @author Merna Islam
/// @date 12/03/2024.
/// @link https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/


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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> preSum;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        preSum[0] = dummy;

        int sum = 0;
        while(head){
            sum += head->val;
            if(preSum.find(sum) != preSum.end()){
                ListNode* toRemove = preSum[sum]->next;
                int tempSum = sum + toRemove->val;
                while(toRemove != head){
                    preSum.erase(tempSum);
                    toRemove = toRemove->next;
                    tempSum += toRemove->val;
                }
                preSum[sum]->next = head->next;
            } else {
                preSum[sum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }

};