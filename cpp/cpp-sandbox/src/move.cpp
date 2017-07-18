#include <iostream>
#include <memory>
#include <string.h>
#include <vector>

// move semantics are useful for *containers* of resources: allocated buffer, objects on the heap, file, socket...
// most known examples are std::vector, std::unique_ptr, but all std container support move semantics
// this allows to transfer / steal / move the resources ("heavy" content, expensive to copy) in between instances of a container
// you can be explicit about when to move, but often the move is automatically called

namespace test_move
{

using namespace std;

class A
{
public:
	//--------------------------------
	// default constructor
	A() { cout << "A default_constructor called\n"; }

	//--------------------------------
	// constructor
	A(int size_)
	{
		cout << "A constructor(int) called\n";

		m_buffer = malloc(size_);
		m_size = size_;
	}

	//--------------------------------
	// destructor
	~A()
	{
		// don't log destructor cout << "destructor\n"; because it's not interesting here
		free(m_buffer);
	}

	//--------------------------------
	// copy constructor
	A(const A& other)
	{
		cout << "A copy_constructor called\n";

		// allocation + copy
		if (other.m_buffer)
		{
			m_buffer = malloc(other.m_size);
			memcpy(m_buffer, other.m_buffer, other.m_size);
			m_size = other.m_size;
		}
	}

	//--------------------------------
	// copy assignment
	A& operator=(const A& other)
	{
		cout << "A copy_assignement called\n";

		// clear this
		if (m_buffer != nullptr)
		{
			free(m_buffer);
			m_buffer = nullptr;
			m_size = 0;
		}

		// allocation + copy
		if (other.m_buffer)
		{
			m_buffer = malloc(other.m_size);
			memcpy(m_buffer, other.m_buffer, other.m_size);
			m_size = other.m_size;
		}

		return *this;
	}

	//--------------------------------
	// move constructor
	A(A&& other) // A&& is a "rvalue reference", it's *not* const
	{
		cout << "A move_constructor called\n";

		// transfer/steal/move resource from other
		m_buffer = other.m_buffer;
		m_size = other.m_size;

		// make other an empty shell
		other.m_buffer = nullptr;
		other.m_size = 0;
	}

	//--------------------------------
	// move assignment
	A& operator=(A&& other) // A&& is a "rvalue reference", it's *not* const
	{
		cout << "A move_assignement called\n";

		// clear this
		if (m_buffer != nullptr)
		{
			free(m_buffer);
			m_buffer = nullptr;
			m_size = 0;
		}

		// transfer/steal/move resource from other
		m_buffer = other.m_buffer;
		m_size = other.m_size;

		// make other an empty shell
		other.m_buffer = nullptr;
		other.m_size = 0;

		return *this;
	}

	void* m_buffer = nullptr;
	int m_size = 0;
};

struct B
{
	A m_a;
};

static A g_a;

void Read_ByConstRef(const A& a) { cout << a.m_size << "\n"; }

void Read_ByValue(A a) { cout << a.m_size << "\n"; }

void Set_ByConstRef(const A& a) { g_a = a; }

void Set_ByValue(A a) { g_a = a; }

void Set_ByValue_ThenMove(A a) { g_a = std::move(a); }

#define LOG_CALL(x)                                                                                                                                                                \
	cout << "\n" << #x << ";\n";                                                                                                                                                   \
	x;

void Test()
{
	cout << "========================================\n";
	cout << "\ntest_move::Test() begin\n";

	LOG_CALL(A a1(1))             // constructor
	LOG_CALL(A a2 = a1)           // copy_constructor
	LOG_CALL(a1 = a2)             // copy_assignmnent
	LOG_CALL(A a3(std::move(a2))) // construct explicit move  => move_assignment
	LOG_CALL(A a4 = A(3))         // construct from temporary => 1 call to constructor, because 1 copy_construction is elided
	LOG_CALL(a4 = A(3))           // assign from temporary    => move_assignment

	cout << "\n------------ default move operations with: struct B { A m_a; };\n";
	LOG_CALL(B b1)                // constructor
	LOG_CALL(B b2 = b1)           // copy_constructor
	LOG_CALL(b1 = b2)             // copy_assignmnent
	LOG_CALL(B b3(std::move(b2))) // construct explicit move  => move_assignment
	LOG_CALL(B b4 = B())          // construct from temporary => 1 call to constructor, because 1 copy_construction is elided
	LOG_CALL(b4 = B())            // assign from temporary    => move_assignment

	cout << "\n------------ lvalue\n";
	LOG_CALL(Read_ByConstRef(a1))      // none
	LOG_CALL(Read_ByValue(a1))         // copy_constructor
	LOG_CALL(Set_ByConstRef(a1))       // copy_assignement
	LOG_CALL(Set_ByValue(a1))          // copy_constructor copy_assignement
	LOG_CALL(Set_ByValue_ThenMove(a1)) // copy_constructor move_assignement

	cout << "\n------------ rvalue\n";
	LOG_CALL(Read_ByConstRef(A(3)))      // none
	LOG_CALL(Read_ByValue(A(3)))         // none (copy elided)
	LOG_CALL(Set_ByConstRef(A(3)))       // copy_assignement
	LOG_CALL(Set_ByValue(A(3)))          // copy_assignement (copy elided)
	LOG_CALL(Set_ByValue_ThenMove(A(3))) // move_assignement (copy elided)

	cout << "\n------------ prepare sunk lvalue\n";
	A s1(1), s2(1), s3(1), s4(1), s5(1);
	cout << "\n------------ sunk lvalue\n";
	LOG_CALL(Read_ByConstRef(std::move(s1)))      // none
	LOG_CALL(Read_ByValue(std::move(s2)))         // move_constructor
	LOG_CALL(Set_ByConstRef(std::move(s3)))       // copy_assignement
	LOG_CALL(Set_ByValue(std::move(s4)))          // move_constructor copy_assignement
	LOG_CALL(Set_ByValue_ThenMove(std::move(s5))) // move_constructor move_assignement

	// Read(a) { read a }
	// => always use by const ref

	// Set(a) { m_a = a }
	// we read a to set a to m_a
	//
	// A is expensive to copy and cheap to move
	//
	//                           Set(const A& a) { m_a = a; }                Set(A a) { m_a = a; }
	//----------------------------------------------------------------------------------------------------
	// Set(a) a is lvalue        copy_assignement                  >         copy_constructor move_assignement
	// Set(a) a is rvalue        copy_assignement                 <<<        move_assignement
	// Set(a) a is sunk lvalue   copy_assignement                 <<<        move_constructor move_assignement

	cout << "\ntest_move::Test() end\n";
	cout << "========================================\n";
}
}

void TestMove() { test_move::Test(); }
