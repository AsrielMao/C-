#include<iostream>
#include <string>
using namespace std;

//判断所输入字符是否为元音
bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
			||c=='A' || c=='E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	else
		return false;
}

//将所输入字符串转换
string pigLatin(char *word) {
	int size = 0;

	//记录word指针起始位置
	char *t_word = word;

	string result = "";

	//获取输入字符串长度
	while (*word) {
		size++;
		//如果所输入字符串中含有一个非字母字符，直接返回空字符
		if (!isalpha(*word))
			return "";
		word++;
	}

	//使word回到初始位置
	word = t_word;

	//开始，当第一个字母为元音
	if (isVowel(word[0])) {
		//当第二个字母也为元音，直接在末尾加ay
		if (isVowel(word[1])) {
			for (int i = 0; i < size; i++)
				result += word[i];
			result += "ay";
		}
		//当第二个字母为辅音，将从开头到第二个元音字母前的所有字母后置，然后加ay
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
				//如果第二位起往后没有元音，直接加ay
				if (i = size - 1) {
					for (int j = 0; j < size; j++) {
						result += word[j];
					}
					result += "ay";
				}
			}
		}
	}
	//当第一个字母为辅音
	else {
		for (int i = 1; i < size; i++) {
			//同上，第二个元音以前所有字母后置，然后加ay
			if (isVowel(word[i])) {
				for (int j = i; j < size; j++)
					result += word[j];
				for (int j = 0; j < i; j++)
					result += word[j];
				result += "ay";
				break;
			}
			//一个元音也没有，直接加ay
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

	//重复执行直到用户输入的是全字母组成的字符串
	do {
		cout << "Please input an English word correctly:" << endl;
		cin >> word;
		result = pigLatin(word);
	} while (result == "");
	
	cout << "The result is: " << result << endl;


	system("pause");
	return 0;
}