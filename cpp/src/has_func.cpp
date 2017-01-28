// http://stackoverflow.com/questions/87372/check-if-a-class-has-a-member-function-of-a-given-signature

#include <type_traits>
#include <string>
#include <iostream>
#include "type_name.h"

struct Allocator {};

template <typename T> struct has_alloc_ctr
{
private:
	using Allocator_lref = typename std::add_lvalue_reference<Allocator>::type;

	// if expr_a can compile
	//     test(int) is chosen because it's more specific than test(...)
	//     decltype(expr_a, expr_b) = decltype(expr_b) = char
	// if expr_a cannot compile
	//     test(int) is NOT chosen, test(...) is chosen instead
	template <typename C> static auto test(int) -> decltype(C(std::declval<Allocator_lref>()), std::declval<char>());
	template <typename C> static int test(...);

public:
	enum { value = (sizeof(test<T>(int())) == sizeof(char)) };
};

template <class T> struct is_allocator_aware
{
	template <typename C> static char test_fun(typename C::allocator_aware*);
	template <typename C> static int test_fun(...);
public:
	enum { value = (sizeof(test_fun<T>(0)) == sizeof(char)) };
};


struct A
{
};
static_assert(has_alloc_ctr<A>::value, "A has no A(Allocator& alloc)");
static_assert(is_allocator_aware<A>::value, "A::allocator_aware does not exist");

struct B
{
	B(Allocator& alloc) {}
};
static_assert(has_alloc_ctr<B>::value, "B has no B(Allocator& alloc)");

struct C
{
	C(Allocator& alloc) {}
	static_assert(has_alloc_ctr<C>::value, "C has no C(Allocator& alloc)");
};

struct D
{
	using allocator_aware = int;
	D(Allocator& alloc) {}
	static_assert(is_allocator_aware<D>::value, "D::allocator_aware does not exist");
};

//struct D
//{
//	using allocator_aware = int;
//	D() {}
//	D(Allocator& alloc) : _alloc(alloc) {}
//	Allocator _alloc;
//};
//static_assert(has_alloc_ctr<D>::value, "C has no C(Allocator& alloc)");
//


#define PRINT_TYPE_NAME(x) \
std::cout << #x " is of type: "<< type_name<x>() << '\n'

void TestHasFunc()
{
	using Allocator_lref = typename std::add_lvalue_reference<Allocator>::type;
	PRINT_TYPE_NAME(Allocator_lref);

	std::cout << "has_alloc_ctr_2<A>::value = " << has_alloc_ctr<A>::value << '\n';
	std::cout << "has_alloc_ctr_2<B>::value = " << has_alloc_ctr<B>::value << '\n';
}


