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
        ListNode* res = new ListNode();
        stack<int> res_stack;

        int carry = 0;

        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* res_cur = res;

        while(cur1 || cur2){
            int sum = 0;

            if(cur1) sum += cur1->val;
            if(cur2) sum += cur2->val;
            sum += carry;

            carry = sum / 10;
            sum %= 10;

            res_cur->val = sum;

            if(cur1) cur1 = cur1->next;
            if(cur2) cur2 = cur2->next;
            if(cur1 || cur2) res_cur = res_cur->next = new ListNode();
        }

        if(carry > 0) res_cur->next = new ListNode(carry);

        return res;
    }
};