#include <iostream>
#include <string>

using namespace std;

int main() {

	string s1 = "Good"; // string Ÿ�� ���� s1�� �����ϰ�, ���ڿ� "Good"�� �����Ѵ�.
	string s2 = "Bad"; // string Ÿ�� ���� s2�� �����ϰ�, ���ڿ� "Bad"�� �����Ѵ�.
	bool b = (s1 == s2); // bool Ÿ�� ���� b�� �����ϰ�, �����δ� s1�� s2�� ���� �����Ƿ� false�� ����ȴ�.
	cout << b << endl; // b�� ����Ѵ�.

	s2 = "Good"; // s2�� ���ڿ� "Good"�� �����Ѵ�.
	b = (s1 == s2); // s1�� s2�� ���������Ƿ� b�� true ���� ����ȴ�.
	cout << b << endl; // b�� ����Ѵ�.

	return 0; // 0�� ��ȯ�Ͽ� ���α׷��� �����Ѵ�.
}