#pragma once
// Printing helpers: lc::print(a, b, c) prints space-separated values + newline.
// Handles nested ranges (vector<vector<int>>), pairs, tuples, optionals, bools.

#include <iostream>
#include <unordered_map>

namespace lc {

  template <typename T>
    void printVector(const T& x) {
      std::cout << "[";
      bool fst_elem = true;
      for (auto& xi : x) {
        if (!fst_elem) std::cout << ", ";
        std::cout << xi;
        fst_elem = false;
      }
      std::cout << "]\n";
    }

  template <typename K, typename V>
    void printMap(const std::unordered_map<K, V>& m, std::ostream& os = std::cout) {
      os << '{';
      bool first = true;
      for (const auto& [key, value] : m) {
        if (!first) os << ", ";
        os << key << ": " << value;
        first = false;
      }
      os << "}\n";
    }

} // namespace lc
