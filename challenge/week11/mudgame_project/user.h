#pragma once
#include <iostream>
#include <string>

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
	// 생성자
	User(int first_hp = 20) {
		hp = first_hp;
	}

};