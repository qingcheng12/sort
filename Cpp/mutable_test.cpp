//============================================================================
// Name        : 10test.cpp
// Author      : zh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/**
 * 在C++中，mutable也是为了突破const的限制而设置的。
 * 被mutable修饰的变量，将永远处于可变的状态，即使在一个const函数中。
 * 
 * /

#include <iostream>
using namespace std;

class ClxTest
{
public:
	ClxTest();
	~ClxTest();

	void Output() const;
	int GetOutputTimes() const;

private:
	mutable int m_iTimes;
};

ClxTest::ClxTest()
{
	m_iTimes = 0;
}

ClxTest::~ClxTest()
{

}

void ClxTest::Output() const
{
	cout << "Output for test" << endl;
	m_iTimes++;
}

int ClxTest::GetOutputTimes() const
{
	return m_iTimes;
}


void OutputTest(const ClxTest& lx)
{
	cout << lx.GetOutputTimes() << endl;
	lx.Output();
	cout << lx.GetOutputTimes() << endl;
}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	ClxTest lx;
	OutputTest(lx);




	return 0;
}





