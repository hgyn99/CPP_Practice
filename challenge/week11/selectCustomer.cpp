#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // ������ �̸��� ������ names ���Ϳ�, ���̸� ������ ages ���͸� �����Ѵ�.
    vector<string> names;
    vector<int> ages;

    // �� ���� ���� �Է¹޴´�.
    int n;
    cout << "�� ���� ���� �Է��϶�: ";
    cin >> n;

    // ���Ŀ� ���� �̸��� ���̸� �Է��� ���� �ȳ��ϴ� ���ڿ��� ����Ͽ� ������� �̸��� ���̸� �Է¹޴´�.
    for (int i = 0; i < n; i++) {
        cout << "��� " << i + 1 << "�� �̸�: ";
        string name;
        cin >> name;
        names.push_back(name);
        cout << "��� " << i + 1 << "�� ����: ";
        int age;
        cin >> age;
        ages.push_back(age);
    }

    int ageThreshold;
    cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���:";
    cin >> ageThreshold;
    // Ư�� ���̸� ������ ageThreshold ������ �����Ͽ� Ư�� ���̸� �Է� �޴´�.
    
    cout << ageThreshold << "�� �̻��� ����:\n";
    // Ư�� ���� �̻��� ������ ����Ѵ�.

    int cnt = 0; // Ư�� ���� �̻��� ������ ����� üũ�ϱ� ���� ���� cnt ����

    for (int i = 0; i < n; i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << " (" << ages[i] << "��)" << endl;
            cnt++; // Ư�� ���� �̻��� ���� �־��ٸ� cnt�� ������Ų��.
        }
    }
    // i = 0���� i < 3�� �� ������ i�� 1�� �����ϸ� �ݺ����� �ݺ��Ͽ�
    // i�� ���� Ȱ���� �迭�� Ư�� ��ġ�� �����ϸ� Ư�� ���̿� ���ϰ�,
    // Ư�� ���� �̻��� ���� �̸��� ���̸� ����Ѵ�.

    if (cnt == 0) {
        cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�." << endl;
    }
    // ���� Ư�� ���� �̻��� ���̸� ���� ���� ���ٸ�, ���� ������ �˸���.

    return 0;
}