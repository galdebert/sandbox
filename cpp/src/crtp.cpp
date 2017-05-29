#include <iostream>

using namespace std;

namespace vfuncs
{

struct Base
{
	void f()
	{
		g();
		h();
	}

	virtual void g() = 0;
	virtual void h() = 0;
};

struct A : public Base
{
	void g() override { cout << "vfuncs::A::g()\n"; }
	void h() override { cout << "vfuncs::A::h()\n"; }
};

struct B : public Base
{
	void g() override { cout << "vfuncs::B::g()\n"; }
	void h() override { cout << "vfuncs::B::h()\n"; }
};

void Test()
{
	A a;
	a.f();

	B b;
	b.f();
}

} // namespace vfuncs

namespace crtp
{

template <typename TDerived> struct Base
{
	void f()
	{
		static_cast<TDerived*>(this)->g();
		static_cast<TDerived*>(this)->h();
	}
};

struct A : public Base<A>
{
	void g() { cout << "crtp::A::g()\n"; }
	void h() { cout << "crtp::A::h()\n"; }
};

struct B : public Base<B>
{
	void g() { cout << "crtp::B::g()\n"; }
	void h() { cout << "crtp::B::h()\n"; }
};

void Test()
{
	A a;
	a.f();

	B b;
	b.f();
}
} // namespace crtp

void TestCRTP()
{
	vfuncs::Test();
	crtp::Test();
}
