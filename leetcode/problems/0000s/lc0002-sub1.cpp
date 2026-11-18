// 2. Add Two Numbers — https://leetcode.com/problems/add-two-numbers/
#include <lc/prelude.hpp>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        return dummy.next;
    }
};

int main() {
    ListNode* l1 = lc::build_list({2, 4, 3});
    ListNode* l2 = lc::build_list({5, 6, 4});
    ListNode* res = Solution{}.addTwoNumbers(l1, l2);
    lc::print(lc::to_vector(res));   // [7, 0, 8]
    lc::free_list(l1);
    lc::free_list(l2);
    lc::free_list(res);
}
