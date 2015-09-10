#include <initializer_list>
#include <vector>

namespace initializer_list {

struct MyClass {
  // initializer_list constructor
  MyClass(const std::initializer_list<int>& init_list) {
    for (auto x : init_list) m_vector.push_back(x);
  }

  std::vector<int> m_vector;
};

void test() {
  int array[] = {1, 2, 3};  // as before cpp11

  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v3({1, 2, 3});

  MyClass myClass1 = {1, 2, 3};
  MyClass myClass2{1, 2, 3};
  MyClass myClass3({1, 2, 3});
}
}

void test_initializer_list() { return initializer_list::test(); }