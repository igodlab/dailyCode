#pragma once
// LeetCode's ListNode plus helpers to build/inspect lists from vectors.
//
//   ListNode* head = lc::build_list({1, 2, 3});
//   lc::print(lc::to_vector(head));   // [1, 2, 3]
//   lc::free_list(head);              // keeps AddressSanitizer quiet

#include <vector>

// Defined in the global namespace on purpose: LeetCode's signatures use bare
// `ListNode*`, so solutions can be pasted in and out unchanged.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

namespace lc {

inline ListNode* build_list(const std::vector<int>& vals) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

inline std::vector<int> to_vector(const ListNode* head) {
    std::vector<int> out;
    for (; head; head = head->next) out.push_back(head->val);
    return out;
}

inline void free_list(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

} // namespace lc
