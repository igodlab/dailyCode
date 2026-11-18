#pragma once
// LeetCode's TreeNode plus helpers using LeetCode's level-order notation.
//
//   TreeNode* root = lc::build_tree("[3,9,20,null,null,15,7]");
//   lc::print(lc::to_string(root));   // "[3,9,20,null,null,15,7]"
//   lc::free_tree(root);

#include <cstddef>
#include <optional>
#include <queue>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

// Global namespace on purpose, to match LeetCode's signatures.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

namespace lc {

namespace detail {
// "[1,null,2]" -> {1, nullopt, 2}
inline std::vector<std::optional<int>> parse_level_order(std::string_view s) {
    std::vector<std::optional<int>> out;
    std::string token;
    auto flush = [&] {
        if (token.empty()) return;
        if (token == "null") out.emplace_back(std::nullopt);
        else                 out.emplace_back(std::stoi(token));
        token.clear();
    };
    for (char c : s) {
        if (c == '[' || c == ']' || c == ' ') continue;
        if (c == ',') flush();
        else          token += c;
    }
    flush();
    return out;
}
} // namespace detail

inline TreeNode* build_tree(const std::vector<std::optional<int>>& vals) {
    if (vals.empty() || !vals[0]) return nullptr;
    auto* root = new TreeNode(*vals[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    std::size_t i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (i < vals.size() && vals[i]) {
            node->left = new TreeNode(*vals[i]);
            q.push(node->left);
        }
        ++i;
        if (i < vals.size() && vals[i]) {
            node->right = new TreeNode(*vals[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

inline TreeNode* build_tree(std::string_view s) {
    return build_tree(detail::parse_level_order(s));
}

// Serialises back to LeetCode notation, trailing nulls trimmed.
inline std::string to_string(const TreeNode* root) {
    std::vector<std::optional<int>> vals;
    std::queue<const TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const TreeNode* node = q.front();
        q.pop();
        if (node) {
            vals.emplace_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            vals.emplace_back(std::nullopt);
        }
    }
    while (!vals.empty() && !vals.back()) vals.pop_back();

    std::ostringstream os;
    os << '[';
    for (std::size_t i = 0; i < vals.size(); ++i) {
        if (i) os << ',';
        if (vals[i]) os << *vals[i];
        else         os << "null";
    }
    os << ']';
    return os.str();
}

inline void free_tree(TreeNode* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}

} // namespace lc
