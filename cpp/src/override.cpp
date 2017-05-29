namespace override
{
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
	// virtual void MyVirtualFunc2() override; // error: solves the "fragile base
	// class"
};
}
