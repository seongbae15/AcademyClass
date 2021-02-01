/*
<작업 할 것>
	1. 클래스 구성
		o Draw
			- Draw Map
			- Disp Text
			- Erase Text or Map
		> Character(부모)
			- 멤버변수
				: 이름
				: 레벨
				: 공격력
				: 생명력
				: 경험치
				: GetExp
				: Gold
		  >> Player(자식)
			- 멤버변수
				: 무기 공격력
				: Total 공격력
		  >> Monster(자식)
			- 멤버변수
		> Weapon(부모 클래스)
			>> 무기타입 (자식 클래스)
			- 멤버변수
				: 무기 이름
				: 공격력
				: 가격
		> 상점
		> 던전
		> 게임 관리자
			- 멤버함수
				: Save
				: Load
				: Play
				: Win GameOver
			- 그외 관리
				: 크리티컬 판정(확률), 명칭
				: 레벨 업
	2. 작업 내용
		o 메인로비메뉴 구성
		o 뉴 게임 메뉴 구성
		> 구조체 -> 멤버변수로 적용
		> 로드 게임 메뉴 구성
		o Exit 구성
		o 레벨업 증가량 설정
			o >> 경험치 증가
			o >> 체력 +1~10
			o >> 공격력 +1~5
		o 던전 메뉴
		o> 게임 기능
			o >> Play 화면 구성
			o >> 가위,바위,보 33.33% 난수생성(몬스터 내는 것)
			o >> Player 체력, 감소
			o >> 몬스터 체력, 감소
			o >> Player 경험치 획득 및 Level Up(Level Up 시 공격력 증가, 체력 증가, 체력 전체 회복)
			o >> Player 공격력 = 기본 공격력 + 무기 공격력
			o >> Win or Game Over(상태 적용 : 체력 0이 될때)
			o >> 골드 증가
		> 무기 상점
			>> 화면 구성
			>> 불러오기
			>> 무기 구매 시, 골드 차감
			>> 페이지 이동(이전, 다음)
		> Save 기능
		> Load 기능
*/
#include "GameManager.h"
#include <iostream>

void main()
{
	GameManager GM;
	GM.RunGame();
}