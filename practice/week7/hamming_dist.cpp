#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int count = 0;

	//���ڿ� �Է��ϱ�
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	//���̿� ���� if else�� �ϱ�
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
	return 0;
}