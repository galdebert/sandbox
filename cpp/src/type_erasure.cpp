#include <memory>
#include <iostream>
#include <vector>

namespace type_erasure {

using namespace std;

// The idea
// Object (without virtual func) can store any Data type (without virtual func)
// Object::Func() will call Func(const Data&)

// How:
// Object has a ptr to Object::Interface
// Object::Interface has virtual function DoFunc()
// Object::Concrete<T> inherit from Object::Interface
// Object::Concrete<T>::DoFunc() call Func(const T&)
// Object::Object<T> constructor create a Object::Concrete<T> on the heap
// In less object oriented terms, we simply prepend a vtableptr to the Data object: Object = ptr to [vtableptr][Data]
class Object {
public:
  void DoFunc() { interface_->DoFunc(); }

  template <typename T> Object(const T &data) {
    interface_ = make_shared<Concrete<T>>(data);
  }

  Object(const Object &other) { interface_ = other.interface_->Clone(); }

private:
  struct Interface {
    virtual ~Interface() {}
    virtual shared_ptr<Interface> Clone() const = 0;
    virtual void DoFunc() = 0;
  };

  template <typename T> struct Concrete : public Interface {

    Concrete(const T &data) : data_(data) {}

    virtual shared_ptr<Interface> Clone() const override {
      return make_shared<Concrete<T>>(data_);
    }

    virtual void DoFunc() override { Func(data_); }
    T data_;
  };

  shared_ptr<Interface> interface_;
};

// Func(const A&), Func(const B&), Func(int)
// note that struct A, B have no virtual functions
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