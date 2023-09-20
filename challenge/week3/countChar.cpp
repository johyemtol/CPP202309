#include <iostream>
using namespace std;

int main() {
    int vowel = 0;                  //모음 자음 변수 0으로 지정
    int consonant = 0;
    cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

    char ch; // 사용자가 입력 저장하기 위한 변수

    while (cin >> ch) {
        switch (ch)
        {                               //case가 모음일때
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowel++;
            break;
        default:                        //모음 대신 자음일때
            if (ch >= 'a' && ch <= 'z'){
                consonant++;
            }
            break;
        }
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;

    return 0;
}
