#include <iostream>
#include <string>

using namespace std;

int main() {

	string s1 = "���"; // string Ÿ�� ���� s1�� �����ϰ�, ���ڿ� "���"�� �����Ѵ�.
	string s2; // string Ÿ�� ���� s2�� �����Ѵ�.
	// s2 = s1 + " " + 10 + "��";
	s2 = s1 + " " + to_string(10) + "��"; // s2�� s1 ���ڿ��� ���� 10�� ���ڿ��� ��ȯ�� ���� ������ �ٽ� �簡���Ѵ�.
	cout << s2 << endl; // s2�� ����Ѵ�.

	return 0; // 0�� ��ȯ�Ͽ� ���α׷��� �����Ѵ�.
}