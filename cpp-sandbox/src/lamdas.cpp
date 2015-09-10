#include <vector>
#include <algorithm>

namespace lambda {
void test() {
  std::vector<int> v;
  for (int i = 0; i < 10; ++i) v.push_back(i);

  int sum_1 = 0;
  std::for_each(v.begin(), v.end(), [&](int x) { sum_1 += x; });
  printf("sum_1=%d\n", sum_1);

  int sum_2 = 0;
  std::for_each(v.begin(), v.end(), [&sum_2](int x) { sum_2 += x; });
  printf("sum_2=%d\n", sum_2);

  auto IsEqual = [](int a, int b) -> bool { return a == b; };
  IsEqual(1, 2);
}
}

void test_lambda() { lambda::test(); }