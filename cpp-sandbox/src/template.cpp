namespace template_ {
// ------------------------ type alias ------------------------
// juste like typedef but easier to use

using MyFuncAdd = void (*)(int, int);
typedef void (*MyFuncAdd2)(int, int);

// ------------------------ auto decltype with template ------------------------

// function template - decltype as return value
template <typename A, typename B>
auto MyTemplateFunc(A a, B b) -> decltype(a + b) {
  return a + b;
}

// ------------------------ alias template ------------------------

template <typename T>
using MyPtr = T*;

//
template <typename A, typename B>
class SomeContainer {
  using a_type = A;
  using b_type = B;
  A a;
  B b;
};

class MyBase {
 public:
  void MyFunc();
  virtual void MyVirtualFunc();
};

// hide a template parameter
template <typename A>
using SomeContainer2 = SomeContainer<A, MyBase>;

template <typename A>
using AType = typename SomeContainer2<A>::a_type;
}