
namespace aggregate_initialization {

struct A {
  A(int x_, int y_) : x(x_), y(y_), z(0) {}
  virtual ~A() {}

  int x;
  int y;
  int z;
};

struct B {
  virtual ~B() {}

  int x;
  int y;
  int z;
};

struct C {
  int x;
  int y;
  int z;
};

void test() {
  // uniform initialization look for:
  // 1. initializer_list constructor
  // 2. regular constructor with the params
  // 3. aggregate initializer

  A a1 = {1, 1}; // regular constructor
  // A a2 = { 1, 1, 1 }; // ERROR aggregate initializer

  // B b1 = { 1, 1 };    // ERROR regular constructor
  // B b2 = { 1, 1, 1 }; // ERROR aggregate initializer

  // POD
  C c1 = {1, 1};    // aggregate initializer
  C c2 = {1, 1, 1}; // aggregate initializer

  (void)c1; // avoid warning : unused variable 'c1'
  (void)c2; // avoid warning : unused variable 'c2'
}
}

void TestAggregateInitialization() { aggregate_initialization::test(); }