#include <iostream>
using namespace std;

int main() {
    int vowel = 0;                  //���� ���� ���� 0���� ����
    int consonant = 0;
    cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����" << endl;

    char ch; // ����ڰ� �Է� �����ϱ� ���� ����

    while (cin >> ch) {
        switch (ch)
        {                               //case�� �����϶�
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowel++;
            break;
        default:                        //���� ��� �����϶�
            if (ch >= 'a' && ch <= 'z'){
                consonant++;
            }
            break;
        }
    }

    cout << "����: " << vowel << endl;
    cout << "����: " << consonant << endl;

    return 0;
}
