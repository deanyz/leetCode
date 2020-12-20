- [ ] 18题答案不简洁，不够清晰。还需改进
- [ ] 测试程序自动生成

leetcode-extension --> problem.cpp 
gen_test.sh --> problem_test.cpp
            --> CMakeLists.txt

```c++
//problem_test.cpp
#include "problem.cpp"
#include <gtest/gtest.h>

// test case

int main()
{

}

```

```cmake

add_executable(problem_test test/proble_test.cpp)

```

