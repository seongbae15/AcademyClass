/*
1. 설계

2.할일
	2)추가 확인할 것
		- 겹칠 때(위치 동일 이후, 탈출 시, 그리기 복구)
		- 승리조건 : 목적지 도착
			> 목적지 그리기
			> 승리 Text 표시 game end
		- Game over조건 : Player 1, 2 Die 상태(죽음 상태에서 움직임 비활성화 할 것)
			> game over 표시
		- 클래스들 배열로 구성(플레이어, 몬스터, 맵 등) : 코드 단순화 가능
*/

#include "GameManager.h"

void main()
{
	GameManager Gm;
	Gm.StartGame();
}