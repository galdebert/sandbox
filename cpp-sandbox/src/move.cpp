#include <memory>
#include <iostream>
#include <vector>

namespace test_move {

using namespace std;

class A {
 public:
  A() {
    cout << "default_ctr\n";
    mem_ = nullptr;
  }

  A(int x) {
    cout << "ctr(x)\n";
    mem_ = new int(x);
  }

  void Init(int x) { mem_ = new int(x); }

  A(const A& other) {
    cout << "copy_ctr\n";
    if (other.mem_) {
      mem_ = new int();
      *mem_ = *other.mem_;
    } else
      mem_ = nullptr;
  }

  A(A&& other) {
    cout << "move_ctr\n";
    mem_ = other.mem_;
    other.mem_ = nullptr;
  }

  //A& operator=(const A& other) {
  //  cout << "op=\n";
  //  return *this;
  //}

  static A GetRValue() { static A sa(1); return sa; }

  int* mem_;
};

void Func_1(const A& a) {
  cout << "in Func_1\n";
}

void Func_2(A a) {
  cout << "in Func_2\n";
}

class B
{
  template<typename T>
  void Func(T&& o) {
    cout << "in B::Func(T&& o)\n";
    a_ = o;
  }
  A a_;
};

void Test() {
  cout << "A a1(1);\n"; 
  A a1(1);

  cout << "A a2 = a1;\n"; 
  A a2 = a1;

  cout << "a1 = a2;\n"; 
  a1 = a2;

  cout << "A a3 = move(a1);\n"; 
  A a3 = move(a1);

  cout << "A a4 = A(3);\n"; 
  A a4 = A(3);

  
  A lvalue(2);
  cout << "------------ lvalue\n";
  cout << "void Func_1(const A& a)\n";
  Func_1(lvalue);
  cout << "void Func_2(A a)\n";
  Func_2(lvalue);


  cout << "------------ rvalue\n";
  cout << "void Func_1(const A& a)\n";
  Func_1(A(2));
  cout << "void Func_2(A a)\n";
  Func_2(A(2));


  cout << "------------ move(rvalue)\n";
  cout << "void Func_1(const A& a)\n";
  Func_1(std::move(A(2)));
  cout << "void Func_2(A a)\n";
  Func_2(std::move(A(2)));

}
}

void TestMove() { test_move::Test(); }