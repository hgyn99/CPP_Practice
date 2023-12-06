#include "user.h"

// 클래스 외부 함수 정의
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}
void User::IncreaseHP(int inc_hp) {
	hp += inc_hp;
}
int User::GetHP() {
	return hp;
}