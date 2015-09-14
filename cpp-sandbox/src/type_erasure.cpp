#include <memory>
#include <iostream>
#include <vector>

namespace type_erasure {

using namespace std;

class Object {
 public:
  void DoFunc() { interface_->DoFunc(); }

  template <typename T>
  Object(const T& data) {
    interface_ = make_shared<Concrete<T>>(data);
  }

  // alt:
  // template <typename T>
  // Object(T data) {
  //  interface_ = make_shared<Concrete<T>>(move(data));
  //}

  Object(const Object& other) { interface_ = other.interface_->Clone(); }

 private:
  struct Interface {
    virtual ~Interface() {}
    virtual shared_ptr<Interface> Clone() const = 0;
    virtual void DoFunc() = 0;
  };

  template <typename T>
  struct Concrete : public Interface {
    Concrete(const T& data) : data_(data) {}
    // alt: Concrete(T data) : data_(move(data)) {}
    virtual shared_ptr<Interface> Clone() const override {
      return make_shared<Concrete<T>>(data_);
    }
    virtual void DoFunc() { Func(data_); }
    T data_;
  };

  shared_ptr<Interface> interface_;
};


struct A {
  A() { value_ = 2.0f; }
  float value_;
};
void Func(const A& a) { cout << "Do A " << a.value_ << "\n"; }

struct B {
  B() {
    values_.resize(10);
    for (auto& e : values_) {
      e = 3;
    }
  }

  B(const B& other) { values_ = other.values_; }

  vector<int> values_;
};
void Func(const B& b) { cout << "Do B " << b.values_.size() << "\n"; }

void Func(int i) { cout << "Do int " << i << "\n"; }

void Test() {
  vector<Object> objects;
  objects.push_back(9);
  objects.push_back(A());
  objects.push_back(B());

  for (auto& e : objects) {
    e.DoFunc();
  }
}
}

void TestTypeErasure() { type_erasure::Test(); }