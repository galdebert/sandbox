// http://stackoverflow.com/questions/87372/check-if-a-class-has-a-member-function-of-a-given-signature

#if 0

#include "type_name.h"
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

struct Allocator
{
};
using Allocator_lref = typename std::add_lvalue_reference<Allocator>::type;

template <typename T> struct has_alloc_ctr
{
private:
	// if expr_a can compile
	//     test(int) is chosen because it's more specific than test(...)
	//     decltype(expr_a, expr_b) = decltype(expr_b) = char
	// if expr_a cannot compile
	//     test(int) is NOT chosen, test(...) is chosen instead
	template <typename C> static auto test(int) -> decltype(C(std::declval<Allocator_lref>()), std::declval<char>());
	template <typename C> static int test(...);

public:
	enum
	{
		value = (sizeof(test<T>(int())) == sizeof(char))
	};
};

template <class T> struct is_allocator_aware
{
	template <typename C> static char test_fun(typename C::allocator_aware*);
	template <typename C> static int test_fun(...);

public:
	enum
	{
		value = (sizeof(test_fun<T>(0)) == sizeof(char))
	};
};

struct A
{
};
// static_assert(has_alloc_ctr<A>::value, "has_alloc_ctr<A>::value");
// static_assert(is_allocator_aware<A>::value, "is_allocator_aware<A>::value");

struct B
{
	B(Allocator& alloc) {}
};
static_assert(has_alloc_ctr<B>::value, "has_alloc_ctr<B>::value false");
static_assert(std::is_constructible<B, Allocator&>::value, "std::is_constructible<B, Allocator&>::value false");

struct C
{
	C(Allocator& alloc) {}
	// static_assert(has_alloc_ctr<C>::value, "has_alloc_ctr<C>::value false");
};

struct D
{
	using allocator_aware = int;
	D(Allocator& alloc) {}
	static_assert(is_allocator_aware<D>::value, "is_allocator_aware<D>::value false");
};

// What's happening in DynamicConfigValue

template <typename T> typename std::enable_if<std::is_constructible<T, Allocator&>::value>::type construct_value(T*) { std::cout << "construct with allocator\n"; }

template <typename T> typename std::enable_if<!std::is_constructible<T, Allocator&>::value>::type construct_value(T*) { std::cout << "construct without allocator\n"; }

// in Stingray
// template <class FIRST, class SECOND, bool firstaware, bool secondaware> struct Pair {}
template <typename T, int Tallocaware> struct TypeAndAwareness
{
};

// in Stingray
// template <class K, class D, class HASH = default_hash, class EQUAL = equal_to >
// class HashMap{
//	typedef Pair<key_type, data_type, IS_ALLOCATOR_AWARE(key_type), IS_ALLOCATOR_AWARE(data_type)> value_type;
template <typename T> struct Container
{
	using value_type = TypeAndAwareness<T, std::is_constructible<T, Allocator&>::value>;
	class iterator
	{
		T* p;
	};
	void construct() { construct_value(value); }
	T* value;
};

// in Stingray
// class DynamicConfigValue {
//	typedef stingray::HashMap<DynamicString, DynamicConfigValue, string_hash> Map;
//	class iterator {
//		Map::iterator _it;
//	};
struct Recursive
{
	class iterator
	{
		// triggers evaluation of TypeAndAwareness<T, std::is_constructible<T, Allocator&>::value> with T=Recursive
		// whereas we are will inside the definition of Recursive
		// => error C2139: 'Recursive': an undefined class is not allowed as an argument to compiler intrinsic type trait '__is_constructible'
		Container<Recursive>::iterator itr;
	};
	void init() { container->construct(); }
	Container<Recursive>* container;
};

#define PRINT_TYPE_NAME(x) std::cout << #x " is of type: " << type_name<x>() << '\n'

void TestHasFunc()
{
	using Allocator_lref = typename std::add_lvalue_reference<Allocator>::type;
	PRINT_TYPE_NAME(Allocator_lref);

	std::cout << "has_alloc_ctr<A>::value = " << has_alloc_ctr<A>::value << '\n';
	std::cout << "has_alloc_ctr<B>::value = " << has_alloc_ctr<B>::value << '\n';

	A* a = nullptr;
	construct_value(a);
	B* b = nullptr;
	construct_value(b);
	(void)a;
	(void)b;

	Recursive recursive;
	recursive.init();
}

#endif