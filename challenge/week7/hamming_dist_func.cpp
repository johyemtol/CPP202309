#include <iostream>
#include <string>
using namespace std;

//�Լ� ���� ����
string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string s1, string s2);

int main() {
	string s1, s2;

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	calcHammingDist(s1, s2);
	return 0;
}

//toLowerStr �Լ�
string toLowerStr(string str) {
	string newStr = str;
	for (char& c : newStr) {
		c = tolower(c);
	}
	return newStr;
}

//toUpperrStr �Լ�

string toUpperStr(string str) {
	string newStr = str;
	for (char& c : str) {
		c = toupper(c);
	}
	return newStr;
}
//��ְŸ� ��� �Լ� ¥��
int calcHammingDist(string s1, string s2) {
	s1=toLowerStr(s1);
	s2=toLowerStr(s2);
	int count = 0;
	//�ݺ���
	//while (s1.length() != s2.length()) {
	//	cout << "����: ���̰� �ٸ� �ٽ� �Է��ϼ���" << endl;
	//	cout << "DNA1: ";
	//	cin >> s1;
	//	cout << "DNA2: ";
	//	cin >> s2;
	// }
	if (s1.length() != s2.length())
		cout << "����: ���̰� �ٸ�" << endl;
	//���̰� ���ٸ� �عְŸ� Ʋ���ſ� ���� +1�� �ϱ�
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "�ع� �Ÿ��� " << count << endl;
	}
	return count;
}