/*
o 1. 게임시작 화면 만들기

o 2. 배경이야기 스크롤 만들기
	o > Scroll
	o > Skip
	o > Player 이름 입력
		o >> 이름 10글자 밑으로만 입력하도록
		o >> Text 위치 이동되도록
3. 단어 떨어트리기
	o > 단어 불러오기
	o > 랜덤 : 단어 인덱스, 단어 위치(x,y)
	o > 맨 아래에서 단어 사라지기
	o > Box & Map 유지
	★> 함수화
		o >> Box & Map 유지 조건부 함수화
		★>> 스토리 텍스트 스크롤 & 단어 Drop 동일 함수로 구현 :DrawManager 상속??
			//Template 사용?? : StoryText Class추가???
4. 단어 맞추기(점수증가)
	o > keyboard 입력
		o >> keyboard 입력 기능 함수화(이름 입력, 단어 입력)
	o > 점수 증가
		o >> 점수 증가
		o >> 단어 지우기 + 정보 삭제
	o > 단어 틀렸을 때, 문장 표시
	> 게임 오버
	> player 정보 업데이트
5. Stage기능 만들기
6. Rank시스템 만들기
7. 아이템기능 추가
8. 함수화
	> 맵 관리 기능 클래스 분리하기.

<조건>
1. player 이름 10글자 이내
2. player 이름 영문만 입력되도록(한글 숫자x)

<class>
Play class = 전체 게임 흐름 제어 Class
WardManager Class = 단어들 관리 Class //단어는 파일입출력으로 가져옴
Ward = 단어 Class , 필요 맴버 변수 x,y,string 필요 
	>맴버함수 draw drop Live Die
Rank Class = Rank 시스템 관리 Class
Interface Class = 전반적인 배경 그림 관리 Class

<아이템>
1.워드속도 증가
2.워드속도 감소
3.워드일시정지
4.화면클리어
5.워드가리기(1.5초)

<랭킹시스템>
점수 내림차순 정렬
저장,불러오기
*/
#include "Play.h"

void main()
{
	Play mainPlay;
	mainPlay.GameOn();
}