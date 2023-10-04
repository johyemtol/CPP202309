#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	//��� ���� numCell�� 10����
	const int numCell = 10;
	//2���� �迭 �����
	int numList[numCell][numCell];
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000;
			numList[i][j] = elem;
			cout << i << "," << j << " : " << elem << endl;
		}
	}
	cout << endl;

	//max�� ã������ ����
	int max=numList[0][0];
	int maxI;
	int maxJ;

	for (int i = 0; i < numCell; i++) {
		int j = 0;							//j����
		for (auto var : numList[i]) {
			//max�� ã��
			if (var > max) {
				max = var;
				maxI = i;
				maxJ = j;
			}
			j++;						//if���� �����ϰ� ++�ؾ� ����� ������ �� �տ��ع����� +1�� �ѹ� �� �Ǿ����
		}
	}


	cout << "���� ū ���� " << max << "�̰�,";
	cout << "i�� j�� ���� " << maxI << "," << maxJ << "�Դϴ�." << endl;
	cout << "���� ���: " << numList[maxI][maxJ] << endl;

	return 0;
}