#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

	const int numCell = 10; // ���� �� 10�� ����� ����
	int numList[numCell][numCell]; // 10 * 10 ũ���� 2���� �迭 numLIst�� �����Ѵ�.

	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int x = rand() % 1000; // ������ 1000���� ������, 0 ~ 999 ������ ���ڸ� ����ǵ��� �Ѵ�.
			numList[i][j] = x; // ������ �ϳ��� 2���� �迭�� �����Ѵ�.
			cout << i << ", " << j << " : " << x << endl; // ������ ���Ŀ� ���� ����Ѵ�.
		}
	}
	// �ݺ����� 10 * 10�� �ݺ��ϸ�, ���� ũ���� 2���� �迭 numList�� ���� ���� �ϳ��� �����ϴ� ���̴�.
	cout << endl;

	int max = 0; // ū �� ������ ���� ����
	int maxI; // ū ���� �ִ� i�� �����ϱ� ���� ����
	int maxJ; // ū ���� �ִ� j�� �����ϱ� ���� ����

	for (int i = 0; i < numCell; i++) {
		int j = 0; // ���� ��� Ž���� ���� j �ε����� ���� ����
		for (auto elem : numList[i]) {
			int value = numList[i][j]; // ���� ������ �켱 value�� ����
			if (value > max) { // �ִ밪 ���� ������ �����ϴ� �ڵ�
				max = value;
				maxI = i;
				maxJ = j;
			}
			j++; // numList �迭�� �� ���� ��� Ž���� ��, j �ε����� ������Ŵ
		}
	}
	// �ݺ������� i �ε����� �ϳ��� ������Ű��, numLIst �迭�� �� �پ� Ž���ϵ��� �ϴ� �ڵ��̴�.
	// �ι�° �ݺ������� numList[i]�� �ش��ϴ� 10���� ������ �ϳ��� ������ value�� �����ϰ�,
	// value ���� Ŀ�� ������ max�� value�� �����ϰ�, maxI�� maxJ�� ������ �����ϵ��� �Ѵ�.
	
	cout << "���� ū ���� " << max << "�̰�, ";
	cout << "i�� j�� ���� " << maxI << ", " << maxJ << "�Դϴ�." << endl;
	cout << "���� ���: " << numList[maxI][maxJ] << endl;
	// ���Ŀ� ���߾� max ���� ���� ������ ����Ѵ�.

	return 0;
}