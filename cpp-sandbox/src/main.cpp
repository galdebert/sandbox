#include <vector>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <type_traits>
#include <initializer_list>

// ------------------------ initialier list ------------------------
namespace initialier_list
{

struct MyClass
{
	// initializer_list constructor
	MyClass(const std::initializer_list<int>& init_list)
	{
		for (auto x : init_list)
			m_vector.push_back(x);
	}

	std::vector<int> m_vector;
};

void Test()
{
	int array[] = { 1, 2, 3 }; // as before cpp11

	std::vector<int> v1 = { 1, 2, 3 };
	std::vector<int> v2{ 1, 2, 3 };
	std::vector<int> v3({ 1, 2, 3 });

	MyClass myClass1 = { 1, 2, 3 };
	MyClass myClass2{ 1, 2, 3 };
	MyClass myClass3({ 1, 2, 3 });
}

}

// ------------------------ aggregate initialization ------------------------
namespace aggregate_initialization
{

struct A
{
	A(int x_, int y_) : x(x_), y(y_), z(0) {}
	virtual ~A() {}

	int x;
	int y;
	int z;
};

struct B
{
	virtual ~B() {}

	int x;
	int y;
	int z;
};

struct C
{
	int x;
	int y;
	int z;
};

struct D
{
	int x;
	int y;
	int z;
};

void Test()
{
	// uniform initialization look for:
	// 1. initializer_list constructor
	// 2. regular constructor with the params
	// 3. aggregate initializer

	A a1 = { 1, 1 };      // regular constructor
	//A a2 = { 1, 1, 1 }; // ERROR aggregate initializer

	//B b1 = { 1, 1 };    // ERROR regular constructor
	//B b2 = { 1, 1, 1 }; // ERROR aggregate initializer

	// POD
	C c1 = { 1, 1 };    // aggregate initializer
	C c2 = { 1, 1, 1 }; // aggregate initializer
}

}


struct MyPOD
{
	MyPOD(int x_, double y_) : x(x_), y(y_), sz(nullptr) {}
	int x;
	double y;
	char* sz;
};


// trivial vs. standard layout vs. POD
namespace pod
{
// is_trivial, is_standard_layout and is_pod
// trivial: a trivially copyable class with a trivial default constructor (performs no action),
//          or array of such type/class, possibly cv-qualified
// standard_layout means same memory layout than in C

struct VTBL // not trivial, not standard_layout, not POD
{
	int i;
	int j;
	virtual ~VTBL();
};

struct T // trivial, not standard_layout, not POD
{
	int i;
private:
	int j;
};

struct DTR // not trivial, standard_layout, not POD
{ 
	int i;
	int j;
	~DTR();
};

struct CTR // not trivial, standard_layout, not POD
{
	CTR(int i_, int j_) : i(i_), j(j_) {}
	int i;
	int j;
};

struct DCTR // not trivial, standard_layout, not POD
{
	DCTR() : i(0), j(0) {}
	int i;
	int j;
};

struct POD // trivial, standard_layout, POD
{
	POD() = default; // not necessary but explicitly using default contructor in c++11
	int i;
	int j;
};


static_assert(std::is_trivial<VTBL>::value == false, "std::is_trivial<VTBL>::value != false");
static_assert(std::is_standard_layout<VTBL>::value == false, "std::is_standard_layout<VTBL>::value != false");
static_assert(std::is_pod<VTBL>::value == false, "std::is_pod<VTBL>::value != false");

static_assert(std::is_trivial<T>::value == true, "std::is_trivial<T>::value != true");
static_assert(std::is_standard_layout<T>::value == false, "std::is_standard_layout<T>::value != false");
static_assert(std::is_pod<T>::value == false, "std::is_pod<T>::value != false");

static_assert(std::is_trivial<DTR>::value == false, "std::is_trivial<DTR>::value != false");
static_assert(std::is_standard_layout<DTR>::value == true, "std::is_standard_layout<DTR>::value != true");
static_assert(std::is_pod<DTR>::value == false, "std::is_pod<DTR>::value != false");

static_assert(std::is_trivial<CTR>::value == false, "std::is_trivial<CTR>::value != false");
static_assert(std::is_standard_layout<CTR>::value == true, "std::is_standard_layout<CTR>::value != true");
static_assert(std::is_pod<CTR>::value == false, "std::is_pod<CTR>::value != false");

static_assert(std::is_trivial<DCTR>::value == false, "std::is_trivial<DCTR>::value != false");
static_assert(std::is_standard_layout<DCTR>::value == true, "std::is_standard_layout<DCTR>::value != true");
static_assert(std::is_pod<DCTR>::value == false, "std::is_pod<DCTR>::value != false");

static_assert(std::is_trivial<POD>::value == true, "std::is_trivial<POD>::value != true");
static_assert(std::is_standard_layout<POD>::value == true, "std::is_standard_layout<POD>::value != true");
static_assert(std::is_pod<POD>::value == true, "std::is_pod<POD>::value != true");

}

// ------------------------ override ------------------------
class MyBase
{
public:
	void MyFunc();
	virtual void MyVirtualFunc();
};

class MyDerive : public MyBase
{
public:
	void MyFunc(); // masking
	virtual void MyVirtualFunc() override;
	//virtual void MyVirtualFunc2() override; // error: solves the "fragile base class"
};


void algorithms()
{
	std::vector<int> v = { 1, 2, 3, 4 };

	int searched = 2;
	if (std::any_of(v.cbegin(), v.cend(), [searched](int x){ return x == searched; }))
		printf("at least one int in v is odd\n");

	bool isSorted = std::is_sorted(v.cbegin(), v.cend());
	printf("vector is %s sorted\n", isSorted ? "" : "not");

	// all_of, none_of, copy_if, find_if
}


// ------------------------ type alias ------------------------
// juste like typedef but easier to use

using MyFuncAdd = void (*) (int, int);
typedef void(*MyFuncAdd2) (int, int);


// ------------------------ auto decltype with template ------------------------

// function template - decltype as return value
template<typename A, typename B>
auto MyTemplateFunc(A a, B b) -> decltype(a + b) { return a + b; }


// ------------------------ alias template ------------------------

template<typename T>
using MyPtr = T*;

// 
template<typename A, typename B>
class SomeContainer
{
	using a_type = A;
	using b_type = B;
	A a;
	B b;
};

// hide a template parameter
template<typename A>
using SomeContainer2 = SomeContainer<A, MyBase>;

template<typename A>
using AType = typename SomeContainer2<A>::a_type;


// ------------------------ tuple ------------------------

//template<typename ... T>
//using MyTuple = std::tuple < int, T ... >;
//
//template<typename ... T>
//using MyTuple = std::tuple<int, T ...>




// ------------------------ range_loop ------------------------
void range_loop()
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	for (auto x : v)
	{
		printf("%d ", x);
	}
	printf("\n");
}

void lambda_1()
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	int sum_1 = 0;
	std::for_each(v.begin(), v.end(), [&](int x) {
		sum_1 += x;
	});
	printf("sum_1=%d\n", sum_1);

	int sum_2 = 0;
	std::for_each(v.begin(), v.end(), [&sum_2](int x) {
		sum_2 += x;
	});
	printf("sum_2=%d\n", sum_2);

	auto IsEqual = [](int a, int b) -> bool { return a == b; };
	IsEqual(1, 2);
}

enum class MyEnum { A, B, C };

void TypeTraits()
{
	static_assert(std::is_pod<MyEnum>::value, "MyEnum is not pod");
	//static_assert(std::is_pod<MyBase>::value, "MyBase is not pod");
}

//std::function can refer to any callable object

// decltype
// using
// nullptr
// Range - based for loops
// Override and final
// Strongly - typed enums aka scoped enums
// Smart pointers
// Lambdas
// non-member begin() and end()
// static_assert
// type traits
// Move semantics

// 

int main()
{
	initialier_list::Test();
	aggregate_initialization::Test();
	range_loop();
	lambda_1();

	getchar();
	return 0;
}
