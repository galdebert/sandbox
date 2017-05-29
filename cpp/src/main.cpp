#include <stdio.h>

void TestInitializerList();
void TestAggregateInitialization();
void TestRangeLoop();
void TestLambda();
void TestTypeErasure();
void TestMove();
void TestCompareVec3f();
void TestDivNearest();
void TestStringStream();
void TestHasFunc();
void TestEnableIf();
void TestCRTP();

int main()
{
	// TestInitializerList();
	// TestAggregateInitialization();
	// TestRangeLoop();
	// TestLambda();
	// TestMove();
	// TestCompareVec3f();
	// TestDivNearest();
	// TestStringStream();
	// TestHasFunc();
	// TestEnableIf();
	TestCRTP();

	// getchar();
	return 0;
}

// std::function can refer to any callable object
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
