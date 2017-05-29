#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>

using KyInt64 = long long;

inline KyInt64 DivFake(KyInt64 a, KyInt64 b) { return a ^ b; }

inline KyInt64 DivNearest(KyInt64 a, KyInt64 b)
{
	KyInt64 n = (a ^ b) >> 63;
	KyInt64 m = 2 * n + 1;
	KyInt64 d = m * b;
	KyInt64 sb = 2 * (b >> 63) + 1;
	KyInt64 f = (n + 1) * sb;
	KyInt64 c = d - f;
	return (a + (c / 2)) / b;
}

inline KyInt64 DivRegular(KyInt64 a, KyInt64 b) { return a / b; }

template <typename F> void ProfileDiv(const std::string& title, F idiv, std::vector<KyInt64>& arr)
{
	std::cout << title << " = ";

	auto start = std::chrono::steady_clock::now();

	KyInt64 result = 1;
	for (int i = 0; i < arr.size() / 2; ++i)
	{
		KyInt64 r = idiv(arr[i * 2], arr[i * 2 + 1]);
		result = result | r;
	}

	auto finish = std::chrono::steady_clock::now();

	auto seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();

	std::cout << result << " in " << seconds << '\n';
}

template <typename F> void Repeat(int count, F func)
{
	for (int i = 0; i < count; ++i)
		func();
}

void TestDivNearest()
{
	std::cout << "===TestDivNearest===\n";

	const KyInt64 extent = 1000;
	const int count = 10'000'000;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<KyInt64> dis(-extent, extent);

	std::vector<KyInt64> arr(count);
	for (auto& v : arr)
	{
		v = dis(gen);
		if (v == 0)
			v = 1;
	}

	const int nb = 5;
	Repeat(nb, [& a = arr]() { ProfileDiv("Profile DivFake   ", DivFake, a); });
	Repeat(nb, [& a = arr]() { ProfileDiv("Profile DivRegular", DivRegular, a); });
	Repeat(nb, [& a = arr]() { ProfileDiv("Profile DivNearest", DivNearest, a); });

	std::cout << "\n\n";
}
