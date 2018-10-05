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

#include <functional> // bind

using namespace std;


bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}


int main()
{
//	int num;
	vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v2 = {0,1,2,3,4,5,6,7,8,10};

	vector<char> s1 = {'a','b'};
	vector<char> s2 = {'a','b'};
	cout << "length = " << v2.capacity() << endl;

	// 通过插入迭代器修改容器的值
	auto it = back_inserter(v2);
	*it = 10;  // 将容器的第一个值改为42

	// 创建一个插入迭代器，向v2添加10个值为1的元素，实际调用的是push_back
	fill_n(back_inserter(v2), 10, 1);

	replace (v2.begin(), v2.end(), 10, 11);

	cout << "length = " << v2.capacity() << endl;
	int sum = accumulate(v2.cbegin(), v2.cend(), 0);
	cout << "sum = " << sum << endl;

	// judge vi = v2
	cout << "vi equals to v2 is " << equal(s1.cbegin(), s1.cend(), s2.cbegin()) << endl;

	cout << vi.capacity() << endl;


	// 消除重复单词
	vector<string> word = {"fox", "jumps","over", "quick", "red", "show", "the", "slow", "red", "turtle"};
	// 按照字典序排序word，以便查找重复单词
	sort(word.begin(), word.end());
	// unique重新排列输入范围, 使得每个单词只出现一次排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
	auto end_unique = unique(word.begin(), word.end());
	// 使用向量操作erase删除重复单词
	word.erase(end_unique, word.end());

	for (auto i : word)
		cout << i << " " ;
	cout << endl;

	// 按照长度排序，长度相同的单词维持字典序, 调用lambda表达式
	stable_sort(word.begin(), word.end(), [](const string &a, const string &b){ return a.size() < b.size(); });

	for (auto i : word)
		cout << i << " " ;
	cout << endl;

	// 获取一个迭代器，指向第一个满足size() >= sz 的元素
 	unsigned int sz = 5;
	auto wc = find_if(word.begin(), word.end(), [sz](const string &a){ return a.size() >= sz;});

//	auto wc = find_if(word.begin(), word.end(), bind(check_size, _2, sz));


	// 打印指定长度范围内的单词， 每个单词后面接一个空格
	for_each(wc, word.end(), [](const string &s){ cout << s << " "; });
	cout << endl;

	auto f = [] { return 42; };
	cout << "f() = " << f() << endl;

	cout << endl;
	auto iter = vi.begin();
	while(iter != vi.end())
	{
		if (*iter % 2){
			iter = vi.insert(iter, *iter);
	//		iter += 2;
		++iter;
		++iter;
		}else
		{
			iter = vi.erase(iter);
		}
	}

    for (auto i = vi.begin(); i != vi.end(); ++i)
        cout << *i << " ";
    cout << endl;


    cout << endl;
	string str = "we,are,Chinese";

	// 在一个逗号分隔的列表中查找第一个元素
	auto coma  = find(str.cbegin(), str.cend(),',');
	cout << string(str.cbegin(), coma) << endl;

	// 在一个逗号分隔的列表中查找最后一个元素
	auto rcomma = find(str.crbegin(), str.crend(), ',');
	// 得到一个正向迭代器， 从逗号开始读取字符直到str末尾
	cout << string(rcomma.base(), str.cend()) << endl;


	return 0;
}
