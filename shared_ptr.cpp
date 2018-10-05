#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <malloc.h>
#include <vector>
#include <list>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <memory>  // shared_ptr

#include <functional> // bind

using namespace std;

class StrBlob{
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> i1);
	size_type szie() const{
		return data->size();
	}
	bool empty() const
	{
		return data->empty();
	}
	void push_back(const string &t){
		data->push_back(t);
	}
	void pop_back();
	string &front();
	string &back();

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};


StrBlob::StrBlob():data(make_shared<vector<string>>())
{

}


StrBlob::StrBlob(initializer_list<string> i1):
		data(make_shared<vector<string>>(i1)) { }


// 检查给定索引是否在合法范围内
void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()
{
	// 若vector为空， check抛出一个异常
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}



int main()
{
	shared_ptr<string> p1;
	shared_ptr<list<int>> p2;

	// 如果p1不为空， 检查它是否指向空string
	if (p1 && p1->empty())
		*p1 = "Him";

	// 指向一个值为42的int的shared_ptr
	shared_ptr<int> p3 = make_shared<int>(42);

	// p4指向一个值为“9999999999”的string
	shared_ptr<string> p4 = make_shared<string>(10, '9');

	// p5指向一个值初始化的int，即值为0
	shared_ptr<int> p5 = make_shared<int>();

	// p6指向一个动态分配的空vector<string>
	auto p6 = make_shared<vector<string>>();

	auto p = make_shared<int>(42); // p指向的对象只有p一个引用者
	auto q(p);   // p和q指向相同的对象， 此对象有2个引用者

	return 0;
}
