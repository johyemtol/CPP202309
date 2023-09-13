#include <iostream>
using namespace std;

//add라는 이름으로 함수 만들기 add(x,y)를 하면 x와 y더한값이 나옴
auto add(int x, int y)
{
	return x + y;
}

int main() {
	auto sum = add(5, 6);  //add 함수를 통해 5와 6을 더한값을 sum에 넣음
	cout << sum;		  //sum 값을 출력함
	return 0;
}