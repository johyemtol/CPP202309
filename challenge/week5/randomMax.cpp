#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	//상수 설정 numCell을 10으로
	const int numCell = 10;
	//2차원 배열 만들기
	int numList[numCell][numCell];
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000;
			numList[i][j] = elem;
			cout << i << "," << j << " : " << elem << endl;
		}
	}
	cout << endl;

	//max값 찾기위한 선언
	int max=numList[0][0];
	int maxI;
	int maxJ;

	for (int i = 0; i < numCell; i++) {
		int j = 0;							//j선언
		for (auto var : numList[i]) {
			//max값 찾기
			if (var > max) {
				max = var;
				maxI = i;
				maxJ = j;
			}
			j++;						//if절을 실행하고 ++해야 제대로 실행이 됨 앞에해버리면 +1이 한번 더 되어버림
		}
	}


	cout << "가장 큰 값은 " << max << "이고,";
	cout << "i와 j는 각각 " << maxI << "," << maxJ << "입니다." << endl;
	cout << "검증 결과: " << numList[maxI][maxJ] << endl;

	return 0;
}