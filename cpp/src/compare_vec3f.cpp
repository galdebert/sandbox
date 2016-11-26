#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <iostream>

struct Vec3f { float x; float y; float z; };

__forceinline bool less_vec3f_1(const Vec3f& a, const Vec3f& b)
{
  if (a.x < b.x) return true;
  if (a.x > b.x) return false;
  if (a.y < b.y) return true;
  if (a.y > b.y) return false;
  return a.z < b.z;
}

__forceinline bool less_vec3f_2(const Vec3f& a, const Vec3f& b)
{
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.z < b.z;
}

__forceinline bool less_vec3f_3(const Vec3f& a, const Vec3f& b)
{
  int x = (a.x == b.x ? 9 : (a.x < b.x ? 0 : 18)); // 0 9 18
  int y = (a.y == b.y ? 3 : (a.y < b.y ? 0 : 6));  // 0 3 6
  int z = (a.z == b.z ? 1 : (a.z < b.z ? 0 : 2));  // 0 1 2
  return x + y + z < 14;
}

template<typename F>
__forceinline void ProfileSort(const std::string& title, F less, std::vector<Vec3f>& arr)
{
  std::cout << title << " = ";
  auto sorted = arr;

  auto start = std::chrono::steady_clock::now();
  std::sort(sorted.begin(), sorted.end(), less);
  auto finish = std::chrono::steady_clock::now();

  auto seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
  std::cout << seconds << '\n';
}


template<typename F>
void ProfileCmp(const std::string& title, F less, std::vector<Vec3f>& arr)
{
  std::cout << title << " = ";

  auto start = std::chrono::steady_clock::now();

  bool result = false;
  for (int i = 0; i < arr.size() / 2; ++i)
  {
	bool r = less(arr[i*2], arr[i*2+1]);
    result = result ^ r;
  }

  auto finish = std::chrono::steady_clock::now();

  auto seconds = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
  std::cout << result << " in "<< seconds << '\n';
}

template <typename F>
void Repeat(int count, F func) {
  for (int i = 0; i < count; ++i)
    func();
}

void TestCompareVec3f() {
  std::cout << "===TestCompareVec3f===\n";

  const float extent = 1000.0f;
  const int count = 1000'000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dis(-extent, extent);

  std::vector<Vec3f> arr(count);
  for (auto &v : arr) {
    v.x = dis(gen);
    v.y = dis(gen);
    v.z = dis(gen);
  }

  const int nb = 5;
  Repeat(nb, [&a=arr]() { ProfileSort("sort less_vec3f_1", less_vec3f_1, a); });
  Repeat(nb, [&a=arr]() { ProfileSort("sort less_vec3f_2", less_vec3f_2, a); });
  Repeat(nb, [&a=arr]() { ProfileSort("sort less_vec3f_3", less_vec3f_3, a); });

  Repeat(nb, [&a=arr]() { ProfileCmp("cmp less_vec3f_1", less_vec3f_1, a); });
  Repeat(nb, [&a=arr]() { ProfileCmp("cmp less_vec3f_2", less_vec3f_2, a); });
  Repeat(nb, [&a=arr]() { ProfileCmp("cmp less_vec3f_3", less_vec3f_3, a); });

  std::cout << "\n\n";
}
