#include <iostream>
#include <string>

using namespace std;

int main() {

	const int STUDENT = 5; // �л����� ��� 5�� ����
	const int SUBJECT = 3; // ���� ���� ��� 3���� ����

	int scores[STUDENT][SUBJECT]; // �л����� ���� ������ ���� 2���� �迭 scores ����
	string studentNames[STUDENT]
		= { "����", "����", "ö��", "�̹�", "����" };
	// �л����� �̸��� �迭 studentNames�� ����
	string subjectNames[SUBJECT]
		= { "����", "����", "CPP" };
	// ���� �̸����� �迭 subjectNames�� ����

	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ������ �ϳ��� �Է��ϼ���." << endl;
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}		
	}
	// �ݺ����� �л� ����ŭ �ݺ��ϸ�, �л��� �ش� ���� �������� ���ʴ�� �Է� �޾� ���� �迭�� �����Ѵ�.
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ��� ������ ";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "�Դϴ�" << endl;
	}
	// �л����� �� ���� �������� ���� ���� ���� ������ ����� ���ϰ�, �� �л��� ��� ������ ���ʴ�� ����Ѵ�.
	return 0;
}