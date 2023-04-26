// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;    // 在两个链表都不为nullptr时,通过两个位置及上一位进位相加得到本位数值及进位
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            // 进位
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        // 当有一个链表到头时,只对剩下的一个链表进行计算
        while (l1 != nullptr) {
            int sum = l1->val + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            // 进位
            carry = sum / 10;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int sum = l2->val + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            // 进位
            carry = sum / 10;
            l2 = l2->next;
        }

        // 如果最终进位为0则不需要继续申请
        if (carry) {
            tail->next = new ListNode(carry);
        }

        return head;
    }
};