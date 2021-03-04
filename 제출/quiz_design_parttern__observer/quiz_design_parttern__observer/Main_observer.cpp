/*
2.할일
	2)추가 확인할 것
		o - 겹칠 때(위치 동일 이후, 탈출 시, 그리기 복구)
		o - 승리조건 : 목적지 도착
			o > 목적지 그리기
			o > 승리 Text 표시 game end
		o - 클래스들 배열로 구성 : 코드 단순화 가능
			o > 플레이어
			o > 몬스터
				// 특정 상속 없앨 것.
			o > 맵 등
				// 특정 상속 없앨 것.
		o - 메모리 해제
		- 코드 다듬기
		- Game over조건 : Player 1, 2 Die 상태(죽음 상태에서 움직임 비활성화 할 것)
			> game over 표시
*/

#include "GameManager.h"

void main()
{
	GameManager Gm;
	Gm.StartGame();
}