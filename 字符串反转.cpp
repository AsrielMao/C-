#include<iostream>
#include <string>
using namespace std;

int main() {
	//��charָ�����������ַ���
	char *word = new char;
	cin >> word;

	//�ӵ�0λ��ʼ������ǰλ��ֵ���ַ�������str����ǰλΪ��ʱ��˵���ַ����ѽ���
	int count = 0;
	string str = "";
	while (*word) {
		cout << ++count << ": " << *word << endl;
		str = *word + str;
		word++;
	}

	cout << "\n��ת���ַ�Ϊ�� " << str << endl;

	system("pause");
	return 0;
}