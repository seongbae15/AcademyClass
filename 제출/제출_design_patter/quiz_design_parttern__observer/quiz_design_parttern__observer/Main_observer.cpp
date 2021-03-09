/*
<게임 방법>
1. Player1 조작 : w a s d
2. Player2 조작 : i j k l
3. 목표
	> 2층의 목표까지 도착.
4. 게임오버 조건
	> 플레이어 1, 2 모두 죽음 상태
		>> 플레이어 죽음 상태 조건
			1) 몬스터의 공격을 때(버튼 누른 플레이어만 공격)
			2) 몬스터 Awake 상태에서 몬스터 옆으로 이동했을 때,
5. 참고
	1) 버튼 3개 상태
		> Pass : 아무른 동작x
		> Wake : 몬스터 동작 변경
			>> sleep -> awake
			>> awake -> attack
		>> sleep or wake
			>> sleep -> awake
			>> awake -> sleep
			>> attack -> awake
		- 메모리 해제
*/

#include "GameManager.h"

void main()
{
	GameManager Gm;
	Gm.StartGame();
}