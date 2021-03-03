/*
1. 설계
	0) 라이브러리 헤더 구성
		- 그리기:(색),맵 사이즈, 조작키
	1) 1층/2층 공간 구성
		(1) 벽, 계단, 플레이어, 에너미 등장 포인트
	2) 클래스 구성
		- DrawManager : 그리기 함수관리
		- Player : Player 그리기, 움직이기
		- Observer : 알림
		- Enemy : 유한상태 사용해볼 것(sleep, 깨어남: 플레이어 방향 움직임)
		- EnemyAlarm
		- Map : 맵 관리(벽, 버튼 등)
		- GameManager : 전체 관리
	2) 오르고, 내려가기
	3) 에너미 등장 시, 알림 설정(층 구분할 것)
	4) 이동 방법 : p1 : wasd, p2:ijkl

2.할일
	1) 클래스 기능 만들기
		- 캐릭터 움직이기
		- 추가 클래스 초기화, 그리기, 위치Get 등
		- 맵 이동
		- 알림
*/

#include "GameManager.h"

void main()
{
	GameManager Gm;
	Gm.StartGame();
}