#include<iostream>
#include <string>
using namespace std;

//�ж��������ַ��Ƿ�ΪԪ��
bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
			||c=='A' || c=='E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	else
		return false;
}

//���������ַ���ת��
string pigLatin(char *word) {
	int size = 0;

	//��¼wordָ����ʼλ��
	char *t_word = word;

	string result = "";

	//��ȡ�����ַ�������
	while (*word) {
		size++;
		//����������ַ����к���һ������ĸ�ַ���ֱ�ӷ��ؿ��ַ�
		if (!isalpha(*word))
			return "";
		word++;
	}

	//ʹword�ص���ʼλ��
	word = t_word;

	//��ʼ������һ����ĸΪԪ��
	if (isVowel(word[0])) {
		//���ڶ�����ĸҲΪԪ����ֱ����ĩβ��ay
		if (isVowel(word[1])) {
			for (int i = 0; i < size; i++)
				result += word[i];
			result += "ay";
		}
		//���ڶ�����ĸΪ���������ӿ�ͷ���ڶ���Ԫ����ĸǰ��������ĸ���ã�Ȼ���ay
		else {
			for (int i = 2; i < size; i++) {
				if (isVowel(word[i])) {
					for (int j = i; j < size; j++)
						result += word[j];
					for (int j = 0; j < i; j++)
						result += word[j];
					result += "ay";
					break;
				}
				//����ڶ�λ������û��Ԫ����ֱ�Ӽ�ay
				if (i = size - 1) {
					for (int j = 0; j < size; j++) {
						result += word[j];
					}
					result += "ay";
				}
			}
		}
	}
	//����һ����ĸΪ����
	else {
		for (int i = 1; i < size; i++) {
			//ͬ�ϣ��ڶ���Ԫ����ǰ������ĸ���ã�Ȼ���ay
			if (isVowel(word[i])) {
				for (int j = i; j < size; j++)
					result += word[j];
				for (int j = 0; j < i; j++)
					result += word[j];
				result += "ay";
				break;
			}
			//һ��Ԫ��Ҳû�У�ֱ�Ӽ�ay
			if (i = size - 1) {
				for (int j = 0; j < size; j++) {
					result += word[j];
				}
				result += "ay";
			}
		}
	}

	return result;
}


int main() {
	char *word = new char;
	string result="";

	//�ظ�ִ��ֱ���û��������ȫ��ĸ��ɵ��ַ���
	do {
		cout << "Please input an English word correctly:" << endl;
		cin >> word;
		result = pigLatin(word);
	} while (result == "");
	
	cout << "The result is: " << result << endl;


	system("pause");
	return 0;
}