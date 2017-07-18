#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>

struct Vec3f
{
	float x;
	float y;
	float z;
};

inline bool less_vec3f_1(const Vec3f& a, const Vec3f& b)
{
	if (a.x < b.x)
		return true;
	if (a.x > b.x)
		return false;
	if (a.y < b.y)
		return true;
	if (a.y > b.y)
		return false;
	return a.z < b.z;
}

inline bool less_vec3f_2(const Vec3f& a, const Vec3f& b)
{
	if (a.x != b.x)
		return a.x < b.x;
	if (a.y != b.y)
		return a.y < b.y;
	return a.z < b.z;
}

inline bool less_vec3f_3(const Vec3f& a, const Vec3f& b)
{
	int x = (a.x == b.x ? 9 : (a.x < b.x ? 0 : 18)); // 0 9 18
	int y = (a.y == b.y ? 3 : (a.y < b.y ? 0 : 6));  // 0 3 6
	int z = (a.z == b.z ? 1 : (a.z < b.z ? 0 : 2));  // 0 1 2
	return x + y + z < 14;
}

template <typename F> inline void ProfileSort(const std::string& title, F less, std::vector<Vec3f>& arr)
{
	std::cout << title << " = ";
	auto sorted = arr;

	auto start = std::chrono::steady_clock::now();
	std::sort(sorted.begin(), sorted.end(), less);
	auto finish = std::chrono::steady_clock::now();

	auto seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
	std::cout << seconds << '\n';
}

struct CmpIO
{
	Vec3f A;
	Vec3f B;
	bool r;
};

template <typename F> void ProfileCmp(const std::string& title, F less, std::vector<CmpIO>& ios)
{
	std::cout << title << " = ";

	auto start = std::chrono::high_resolution_clock::now();

	for (auto& io : ios)
	{
		io.r = less(io.A, io.B);
	}

	auto finish = std::chrono::high_resolution_clock::now();

	auto seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
	std::cout << seconds << '\n';
}

template <typename F> void Repeat(int count, F func)
{
	for (int i = 0; i < count; ++i)
		func();
}

void TestCompareVec3f()
{
	std::cout << "===TestCompareVec3f===\n";

	const float extent = 1000.0f;
	const int count = 1000'000; std::mt19937 gen;
	std::uniform_real_distribution<float> distrib(-extent, extent);

	const int nb = 5;

	std::vector<Vec3f> arr(count);
	for (auto& v : arr)
	{
		v.x = distrib(gen);
		v.y = distrib(gen);
		v.z = distrib(gen);
	}
	Repeat(nb, [& a = arr]() { ProfileSort("sort less_vec3f_1", less_vec3f_1, a); });
	Repeat(nb, [& a = arr]() { ProfileSort("sort less_vec3f_2", less_vec3f_2, a); });
	Repeat(nb, [& a = arr]() { ProfileSort("sort less_vec3f_3", less_vec3f_3, a); });

	std::vector<CmpIO> ios(count);
	for (auto& io : ios)
	{
		io.A.x = distrib(gen);
		io.A.y = distrib(gen);
		io.A.z = distrib(gen);
		io.B.x = distrib(gen);
		io.B.y = distrib(gen);
		io.B.z = distrib(gen);
		io.r = false;
	}
	Repeat(nb, [& ios = ios]() { ProfileCmp("compute less_vec3f_1", less_vec3f_1, ios); });
	Repeat(nb, [& ios = ios]() { ProfileCmp("compute less_vec3f_2", less_vec3f_2, ios); });
	Repeat(nb, [& ios = ios]() { ProfileCmp("compute less_vec3f_3", less_vec3f_3, ios); });

	auto count_true = std::count_if(ios.begin(), ios.end(), [](auto& x) { return x.r; });

	std::cout << "count_true = " << count_true << '\n';
	std::cout << "\n\n";
}
