#include <algorithm>
#include <vector>

namespace algorithms {
void test() {
  std::vector<int> v = {1, 2, 3, 4};

  int searched = 2;
  if (std::any_of(v.cbegin(), v.cend(),                           // Sdfsdfsdf
                  [searched](int x) { return x == searched; })) { /// sdfsdsdfz
    printf("at least one int in v is odd\n");                     // sfsdfs
  }

  bool isSorted = std::is_sorted(v.cbegin(), v.cend());
  printf("vector is %s sorted\n", isSorted ? "" : "not");

  // all_of, none_of, copy_if, find_if
}
}