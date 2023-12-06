#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// User 클래스
class User
{
private:
	// 멤버 변수
	int hp;
public:
	// 멤버 함수
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
	virtual void doAttack() {
		cout << "공격합니다" << endl;
	}
	// 생성자
	User(int first_hp = 20) {
		hp = first_hp;
	}

};
class Magician : public User {
public:
	void doAttack() override {
		cout << "마법 사용" << endl;
	}
};

class Warrior : public User {
public:
	void doAttack() override {
		cout << "베기 사용" << endl;
	}
};