#include <iostream>
#include <string>

using namespace std;

int main() {

    const int maxPeople = 3;
    cout << "�� ���� ���� �Է��϶�: 3" << endl;
    string names[maxPeople];
    int ages[maxPeople];
    // ������ �̸��� ������ names �迭��, ���̸� ������ ages �迭�� �����Ѵ�.

    for (int i = 0; i < maxPeople; i++) {
        cout << "��� " << i + 1 << "�� �̸�: ";
        cin >> names[i];
        cout << "��� " << i + 1 << "�� ����: ";
        cin >> ages[i];
    }
    // ���Ŀ� ���� �̸��� ���̸� �Է��� ���� �ȳ��ϴ� ���ڿ��� ����Ͽ� ������� �̸��� ���̸� �Է¹޴´�.

    int ageThreshold;
    cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���:";
    cin >> ageThreshold;
    // Ư�� ���̸� ������ ageThreshold ������ �����Ͽ� Ư�� ���̸� �Է� �޴´�.
    
    cout << ageThreshold << "�� �̻��� ����:\n";
    // Ư�� ���� �̻��� ������ ����Ѵ�.

    int cnt = 0; // Ư�� ���� �̻��� ������ ����� üũ�ϱ� ���� ���� cnt ����

    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << " (" << ages[i] << "��)" << endl;
            cnt++; // Ư�� ���� �̻��� ���� �־��ٸ� cnt�� ������Ų��.
        }
    }
    // i=0���� i<3�� �� ������ i�� 1�� �����ϸ� �ݺ����� �ݺ��Ͽ�,
    // i�� ���� Ȱ���� �迭�� Ư�� ��ġ�� �����ϸ� Ư�� ���̿� ���ϰ�,
    // Ư�� ���� �̻��� ���� �̸��� ���̸� ����Ѵ�.

    if (cnt == 0) {
        cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�." << endl;
    }
    // ���� Ư�� ���� �̻��� ���̸� ���� ���� ���ٸ�, ���� ������ �˸���.

    return 0;
}