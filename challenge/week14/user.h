#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// User Ŭ����
class User
{
private:
	// ��� ����
	int hp;
public:
	// ��� �Լ�
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
	virtual void doAttack() {
		cout << "�����մϴ�" << endl;
	}
	// ������
	User(int first_hp = 20) {
		hp = first_hp;
	}

};
class Magician : public User {
public:
	void doAttack() override {
		cout << "���� ���" << endl;
	}
};

class Warrior : public User {
public:
	void doAttack() override {
		cout << "���� ���" << endl;
	}
};