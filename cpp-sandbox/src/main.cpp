#include <stdio.h>

void test_initializer_list();
void test_aggregate_initialization();
void test_range_loop();
void test_lambda();

int main()
{
	test_initializer_list();
	test_aggregate_initialization();
	test_range_loop();
	test_lambda();

	getchar();
	return 0;
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