# LeetCode solutions (C++20)

```
include/lc/        header-only helpers  →  #include <lc/prelude.hpp>
  print.hpp        lc::print(...) for nested containers, pairs, tuples, optionals
  list_node.hpp    ListNode, lc::build_list, lc::to_vector, lc::free_list
  tree_node.hpp    TreeNode, lc::build_tree("[1,null,2]"), lc::to_string, lc::free_tree
  prelude.hpp      common std headers + all of the above
problems/
  0001-0099/lc0001.cpp ...   one executable per file, picked up automatically
```

## Build & run

```bash
cmake -S . -B build                 # Debug by default (ASan + UBSan on)
cmake --build build --target lc0001 && ./build/lc0001
cmake --build build -j              # build everything
```

If linking fails with `cannot find ...libclang_rt.asan...`, your compiler lacks the
sanitizer runtime: reconfigure with `-DLC_SANITIZE=OFF` (or install `compiler-rt`).
For timing, use `-DCMAKE_BUILD_TYPE=Release`.

## Adding a problem

Drop `problems/<bucket>/lcNNNN.cpp` in place; no CMake edits needed. The first time,
run `cmake --build build` (or `cmake -S . -B build`) so CMake notices the new file and
creates its target; after that `--target lcNNNN` works.
Keep `class Solution` at the top so it can be pasted straight into LeetCode.
