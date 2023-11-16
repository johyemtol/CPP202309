#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int maxPeople;
    cout << "�� ���� ���� �Է��϶�: ";
    cin >> maxPeople;

    vector<string> names(maxPeople);  
    vector<int> ages(maxPeople);     

    // �̸��ϰ� ���� �Է¹ޱ�
    for (int i = 0; i < maxPeople; i++) {
        cout << "��� " << i + 1 << "�� �̸�: ";
        cin >> names[i];
        cout << "��� " << i + 1 << "�� ����: ";
        cin >> ages[i];
    }

    // Ư�� ���� �̻� ã�� �ڵ�
    int ageThreshold;
    cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
    cin >> ageThreshold;

    cout << ageThreshold << "�� �̻��� ����:\n";

    int correctAgePeople = 0;
    //���� ���� ��� ����ϱ�
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ageThreshold) { 
            cout << names[i] << " (" << ages[i] << "��)\n";
            correctAgePeople++;
        }
    }

    //���� ���̿� �´� ����� ���ٸ�
    if (correctAgePeople == 0) 
        cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";

    return 0;
}
