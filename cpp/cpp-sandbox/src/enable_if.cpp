#include <iostream>
#include <string>
#include <type_traits>

//------------------------------------------------------------------
// template <bool B, class T = void> struct enable_if;
// If B is true, std::enable_if has a public member typedef type, equal to T; otherwise, there is no member typedef.
//------------------------------------------------------------------

namespace detail
{
struct inplace_t
{
};
}
void* operator new(std::size_t, void* p, detail::inplace_t) { return p; }
void operator delete(void*, void*, detail::inplace_t) {}

// #1, enabled via the return type
template <class T, class... Args>
typename std::enable_if<std::is_trivially_constructible<T, Args&&...>::value>::type // void if this substitution is chosen
construct(T*, Args&&...)
{
	std::cout << "constructing trivially constructible T\n";
}

// #2 enabled via the return type
template <class T, class... Args>
std::enable_if_t<!std::is_trivially_constructible<T, Args&&...>::value> // void if this substitution is chosen
construct(T* t, Args&&... args)
{
	std::cout << "constructing non-trivially constructible T\n";
	new (t, detail::inplace_t{}) T(args...);
}

// #3, enabled via a function parameter
template <class T> void destroy(T*, typename std::enable_if<std::is_trivially_destructible<T>::value>::type* = 0) { std::cout << "destroying trivially destructible T\n"; }

// #4, enabled via a template parameter
template <class T, typename std::enable_if<!std::is_trivially_destructible<T>::value && (std::is_class<T>::value || std::is_union<T>::value), int>::type = 0> void destroy(T* t)
{
	std::cout << "destroying non-trivially destructible T\n";
	t->~T();
}

// #5, enabled via a template parameter
template <class T, typename = std::enable_if_t<std::is_array<T>::value> > void destroy(T* t) // note, function signature is unmodified
{
	for (std::size_t i = 0; i < std::extent<T>::value; ++i)
	{
		destroy((*t)[i]);
	}
}
/*
template<class T,
    typename = std::enable_if_t<std::is_void<T>::value> >
void destroy(T* t){} // error: has the same signature with #5
*/

// the partial specialization of A is enabled via a template parameter
template <class T, class Enable = void> class A
{
}; // primary template

template <class T> class A<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
{
}; // specialization for floating point types

void TestEnableIf()
{
	std::aligned_union_t<0, int, std::string> u;

	construct(reinterpret_cast<int*>(&u));
	destroy(reinterpret_cast<int*>(&u));

	construct(reinterpret_cast<std::string*>(&u), "Hello");
	destroy(reinterpret_cast<std::string*>(&u));

	A<int> a1;    // OK, matches the primary template
	A<double> a2; // OK, matches the partial specialization
	(void)a1;
	(void)a2;
}