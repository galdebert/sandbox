#include <memory>
#include <iostream>
#include <vector>

namespace test_move {

using namespace std;

class A {
 public:
  // default ctr
  A() {
    cout << "default_ctr\n";
    mem_ = nullptr;
  }

  // ctr
  A(int x) {
    cout << "ctr(x)\n";
    mem_ = new int(x);
  }

  // dtr
  ~A() {
    // don't log dtr cout << "dtr\n";
    delete mem_;
  }

  // copy constructor
  A(const A& other) {
    cout << "copy_ctr\n";
    if (other.mem_) {
      mem_ = new int();
      *mem_ = *other.mem_;
    } else {
      mem_ = nullptr;
    }
  }

  // move constructor
  A(A&& other) {
    cout << "move_ctr\n";
    mem_ = other.mem_;
    other.mem_ = nullptr;
  }

  // copy assignment
  A& operator=(const A& other) {
    cout << "copy_assign\n";
    if (other.mem_) {
      if (mem_ == nullptr)
        mem_ = new int();
      *mem_ = *other.mem_;
    } else {
      if (mem_ != nullptr)
      {
        delete mem_;
        mem_ = nullptr;
      }
    }

      return *this;
  }

  // move assignment
  A& operator=(A&& other) {
    cout << "move_assign\n";
    mem_ = other.mem_;
    other.mem_ = nullptr;
    return *this;
  }

  int* mem_;
};

static A g_a;

void Read_ByConstRef(const A& a) {
  cout << *a.mem_ << "\n";
}

void Read_ByValue(A a) {
  cout << *a.mem_ << "\n";
}

void Set_ByConstRef(const A& a) {
  g_a = a;
}

void Set_ByValue(A a) {
  g_a = a;
}

void Set_ByValue_ThenMove(A a) {
  g_a = std::move(a);
}

#define LOG_CALL(x)           \
  cout << "\n" << #x << "\n"; \
  x;

void Test() {
  LOG_CALL(A a1(1))
  LOG_CALL(A a2 = a1)
  LOG_CALL(a1 = a2)
  LOG_CALL(A a3 = move(a2))
  LOG_CALL(A a4 = A(3))
  LOG_CALL(a4 = A(3))

  cout << "\n------------ lvalue\n";
  LOG_CALL(Read_ByConstRef(a1))       // none
  LOG_CALL(Read_ByValue(a1))          // copy_ctr
  LOG_CALL(Set_ByConstRef(a1))        // copy_assign
  LOG_CALL(Set_ByValue(a1))           // copy_ctr copy_assign
  LOG_CALL(Set_ByValue_ThenMove(a1))  // copy_ctr move_assign

  cout << "\n------------ rvalue\n";
  LOG_CALL(Read_ByConstRef(A(3)))       // none
  LOG_CALL(Read_ByValue(A(3)))          // none (copy ellided)
  LOG_CALL(Set_ByConstRef(A(3)))        // copy_assign
  LOG_CALL(Set_ByValue(A(3)))           // copy_assign (copy ellided)
  LOG_CALL(Set_ByValue_ThenMove(A(3)))  // move_assign (copy ellided)

  cout << "\n------------ prepare sunk lvalue\n";
  A s1(1), s2(1), s3(1), s4(1), s5(1);
  cout << "\n------------ sunk lvalue\n";
  LOG_CALL(Read_ByConstRef(std::move(s1)))       // none
  LOG_CALL(Read_ByValue(std::move(s2)))          // move_ctr
  LOG_CALL(Set_ByConstRef(std::move(s3)))        // copy_assign
  LOG_CALL(Set_ByValue(std::move(s4)))           // move_ctr copy_assign
  LOG_CALL(Set_ByValue_ThenMove(std::move(s5)))  // move_ctr move_assign

  // Read: use by const ref
  //
  //                             faster if 
  // Set:         by const ref   cheap to move?  by value(+move)     
  //            ----------------------------------------------------
  // lvalue       copy_assign          >         copy_ctr move_assign             
  // rvalue       copy_assign         <<<        move_assign              
  // sunk lvalue  copy_assign         <<<        move_ctr move_assign             
}
}

void TestMove() {
  test_move::Test();
}