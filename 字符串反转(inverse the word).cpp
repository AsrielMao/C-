#include<iostream>
#include <string>
using namespace std;

int main() {
	//用char指针接收输入的字符串
	char *word = new char;
	cin >> word;

	//从第0位开始，将当前位的值（字符）存入str，当前位为空时，说明字符串已结束
	int count = 0;
	string str = "";
	while (*word) {
		cout << ++count << ": " << *word << endl;
		str = *word + str;
		word++;
	}

	cout << "\n反转后字符为： " << str << endl;

	system("pause");
	return 0;
}
