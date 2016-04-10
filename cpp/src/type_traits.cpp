#include <type_traits>

// trivial vs. standard layout vs. POD
namespace type_traits {
// is_trivial, is_standard_layout and is_pod
// trivial: a trivially copyable class with a trivial default constructor
// (performs no action),
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
  int j;
#pragma clang diagnostic pop
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
  POD() = default; // not necessary but explicitly using default contructor in
  // c++11
  int i;
  int j;
};

enum class MyEnum { A, B, C };

static_assert(std::is_pod<MyEnum>::value, "MyEnum is not pod");
// static_assert(std::is_pod<MyBase>::value, "MyBase is not pod");

static_assert(std::is_trivial<VTBL>::value == false,
              "std::is_trivial<VTBL>::value != false");
static_assert(std::is_standard_layout<VTBL>::value == false,
              "std::is_standard_layout<VTBL>::value != false");
static_assert(std::is_pod<VTBL>::value == false,
              "std::is_pod<VTBL>::value != false");

static_assert(std::is_trivial<T>::value == true,
              "std::is_trivial<T>::value != true");
static_assert(std::is_standard_layout<T>::value == false,
              "std::is_standard_layout<T>::value != false");
static_assert(std::is_pod<T>::value == false, "std::is_pod<T>::value != false");

static_assert(std::is_trivial<DTR>::value == false,
              "std::is_trivial<DTR>::value != false");
static_assert(std::is_standard_layout<DTR>::value == true,
              "std::is_standard_layout<DTR>::value != true");
static_assert(std::is_pod<DTR>::value == false,
              "std::is_pod<DTR>::value != false");

static_assert(std::is_trivial<CTR>::value == false,
              "std::is_trivial<CTR>::value != false");
static_assert(std::is_standard_layout<CTR>::value == true,
              "std::is_standard_layout<CTR>::value != true");
static_assert(std::is_pod<CTR>::value == false,
              "std::is_pod<CTR>::value != false");

static_assert(std::is_trivial<DCTR>::value == false,
              "std::is_trivial<DCTR>::value != false");
static_assert(std::is_standard_layout<DCTR>::value == true,
              "std::is_standard_layout<DCTR>::value != true");
static_assert(std::is_pod<DCTR>::value == false,
              "std::is_pod<DCTR>::value != false");

static_assert(std::is_trivial<POD>::value == true,
              "std::is_trivial<POD>::value != true");
static_assert(std::is_standard_layout<POD>::value == true,
              "std::is_standard_layout<POD>::value != true");
static_assert(std::is_pod<POD>::value == true,
              "std::is_pod<POD>::value != true");
}
