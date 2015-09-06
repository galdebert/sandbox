#include <stdio.h>
#include <vector>

namespace range_loop
{
	void test()
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
}

void test_range_loop()
{
	range_loop::test();
}