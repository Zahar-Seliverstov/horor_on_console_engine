#include "Library.h"
#include "IPlayer.h"

Player::Player()
{
	hp = 100;
	initialHp = hp;
	r = 0;
	speed = 4;
	initialSpeed = speed;
	sensitivity = 5;
	amountEnergy = 100;
	initialAmountEnergy = amountEnergy;
}
void Player::motion(wstring& map, const int& mapSizeHorizontal, double& ratioNumberFrames)
{
	if (GetAsyncKeyState('D') & 0x8000) r -= (sensitivity * 0.75f) * ratioNumberFrames;
	if (GetAsyncKeyState('A') & 0x8000) r += (sensitivity * 0.75f) * ratioNumberFrames;
	if (GetAsyncKeyState('W') & 0x8000) {
		x += sinf(r) * speed * ratioNumberFrames;
		y += cosf(r) * speed * ratioNumberFrames;
		if (map[(int)y * mapSizeHorizontal + (int)x] == '#') {
			x -= sinf(r) * speed * ratioNumberFrames;
			y -= cosf(r) * speed * ratioNumberFrames;
		}
	}
	if (GetAsyncKeyState('S') & 0x8000) {
		x -= sinf(r) * speed * ratioNumberFrames;
		y -= cosf(r) * speed * ratioNumberFrames;
		if (map[(int)y * mapSizeHorizontal + (int)x] == '#') {
			x += sinf(r) * speed * ratioNumberFrames;
			y += cosf(r) * speed * ratioNumberFrames;
		}
	}
	if (r == 6) { r = 0; };
}