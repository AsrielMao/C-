#include<iostream>

using namespace std;

bool isLowerVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

bool isUpperVowel(char c) {
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	return false;
}

bool isVowel(char c) {
	if (isUpperVowel(c) || isLowerVowel(c))
		return true;
	return false;
}

int countVowel(char* c) {
	char* word = c;
	int count = 0;

	while (*word) {
		if (isVowel(*word))
			count++;

		word++;
	}
	 
	return count;
}

void countEveryVowel(char* c, int *arr) {
	char* word = c;
	for (int i = 0; i < 10; i++)
		arr[i] = 0;

	while (*word) {
		if (isVowel(*word)) {
			switch (*word) {
				case 'a': {
					arr[0]++;
					break;
				}
				case 'e': {
					arr[1]++;
					break;
				}
				case 'i': {
					arr[2]++;
					break;
				}
				case 'o': {
					arr[3]++;
					break;
				}
				case 'u': {
					arr[4]++;
					break;
				}
				case 'A': {
					arr[5]++;
					break;
				}
				case 'E': {
					arr[6]++;
					break;
				}
				case 'I': {
					arr[7]++;
					break;
				}
				case 'O': {
					arr[8]++;
					break;
				}
				case 'U': {
					arr[9]++;
					break;
				}
			}//end switch
		}//end if

		word++;
	}//end while
}

int main() {
	char* word = new char;
	int* arr = new int[10];
	int totalVowel;

	cout << "Please input an English word:" << endl;
	cin >> word;

	totalVowel = countVowel(word);
	countEveryVowel(word, arr);

	//output the result
	cout << "\nThe number of vowels is: " << totalVowel << endl;
	cout << "The numbers of character 'a,e,i,o,u,A,E,I,O,U' are: ";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	delete word;
	delete[] arr;
	word = nullptr;
	arr = nullptr;

	system("pause");
	return 0;
}