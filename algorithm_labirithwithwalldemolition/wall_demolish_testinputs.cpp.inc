#include <vector>
struct TestCase {
  size_t rows;
  size_t cols;
  std::vector<std::vector<int>> field;
};

std::vector<TestCase> test_cases = {
  /* sample test cases */
  {5,
   6,
   {{0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 1, 0}}
  },
  {3,
   4,
   {{0, 0, 1, 0},
    {1, 1, 1, 0},
    {1, 0, 0, 0}}
   },
  {3,
   4,
   {{0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0}}
   }
};