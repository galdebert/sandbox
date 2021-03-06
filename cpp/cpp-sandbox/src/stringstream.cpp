#include <iostream>
#include <sstream>

// how to use stringstream to format a string with a one-liner ?
// pseudo code: string str = "some integer" << i << '\n';

namespace test_stringstream
{

class StrStream
{
public:
	std::stringstream ss;
	std::string str() const { return ss.str(); }
	struct Make
	{
	};
};

template <typename T> StrStream& operator<<(StrStream& stream, const T& x)
{
	stream.ss << x;
	return stream;
}

std::string operator<<(StrStream& stream, const StrStream::Make&) { return stream.ss.str(); }

class StrStream2 : public std::stringstream
{
public:
	template <typename T> StrStream2& operator<<(const T& x)
	{
		*(static_cast<std::stringstream*>(this)) << x;
		return *this;
	}
};

void Test()
{
	int i = 54;

	{
		std::stringstream ss;
		ss << "some integer " << i << '\n';
		std::string str = ss.str();
		std::cout << str;
	}

	{
		std::string str = (StrStream2() << "some integer " << i << '\n').str();
		std::cout << str;
	}

	//	{
	//		std::string str = (StrStream() << "some integer " << i << '\n').str();
	//		std::cout << str;
	//	}

	//	{
	//		std::string str = StrStream() << "some integer " << i << '\n' << StrStream::Make();
	//		std::cout << str;
	//	}
}
}

void TestStringStream() { test_stringstream::Test(); }
