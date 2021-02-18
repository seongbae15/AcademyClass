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
	o > 함수화
		o >> Box & Map 유지 조건부 함수화
		o >> 스토리 텍스트 스크롤 & 단어 Drop 동일 함수로 구현 :DrawManager 상속??
			o- Template 사용?? : StoryText Class추가???
o 4. 단어 맞추기(점수증가)
	o > keyboard 입력
		o >> keyboard 입력 기능 함수화(이름 입력, 단어 입력)
		o >> 상자뒤에서 맞출 시, 상자 사라짐...
	o > 점수 증가
		o >> 점수 증가
		o >> 단어 지우기 + 정보 삭제
	o > 단어 틀렸을 때, 문장 표시
	o > 게임 오버dfdf
		o >> 게임 초기화(플레이어 이름, 점수)
	o > player 정보 업데이트

o 5. Stage기능 만들기
	o > 점수 기준
		o >> stage 별 통과 점수 상승
			o -> 1000 x stage 점 이상 (1000->2000 ->3000)
	o > Reset
		o >> 점수
		o >> 단어 정보 리셋
		o >> 점수 초기화 시, 뒷 자리수 제거
	o > 속도 빨라짐
	o > 단어 갯수 증가
o 6. Rank시스템 만들기
	o > 종료 시 정보 저장(이름, Stage, Stage 순)
	o > Ranking 화면 표시
		o>> 화면 구성
		o >> 파일 불러오기
		o >> 내림차순 정렬(상위 10명만 표시)
		o >> 파일 없을 때, 표시
o <>. 코드 정리
	o > 스크롤 함수화 해볼것(스토리 텍스트, 단어 Drop 동일 함수로 구현해볼 것)
		o >> 클래스 추가<Story>
		o >> vector<Story> vector로 Push_back()
		o >> vector 주소값 참조하여, Scroll 적용
		o >> Story Draw -> DrawMidText , Word Draw ->DrawText
		o>> template 사용하여 vector<Story> vector<Word> 모두 적용
o 7. 아이템기능 추가
	o > 0. 아이템 적용 단어 색상 변경
	o > Enter 입력 시, 판정
	o > 1.워드속도 증가
		> 속도 증가 후, 원상 복귀
	o > 2.워드속도 감소
		> 속도 감소 후, 원상 복귀
	o > 3.워드일시정지
		o >> 생성x, 움직임x
	o > 4.화면클리어
	o > 5.워드가리기(1.5초)
		o >> 단어 그리기에서 매개변수 추가(아이템 적용여부)
	o > 아이템 적용 여부 랜덤 결정(5%)
8. 추가 할 일
	> 맵 관리 기능 클래스 분리하기(배경 관리).
		>> 인터페이스 클래스 만들기(정지된 배경관리)
			-> 배경 그리기 :(로비화면), (스토리 스킵화면),(이름 입력 화면), (게임 화면), (스테이지 업), 게임오버 화면, 랭킹 화면 등등....
	> 단어 맞추기 관련 함수 세분화(역할별로 나눌 것)
	o > 단어별 점수 기준 재정립.(단어 길이별? 점수)
	> define 정리
	o > Stage up 속도 증가 제한, 단어 갯수 증가 제한 둘 것.
	o > 게임 오버 시, 워드 리스트 지우기.

	o > Check word-box position 통일화
	> stage up 시 아이템 사용 초기화
	> 필요없는 반복문 점검(아이템 사용 시, 타임 증가)

	> Text 클래스를 부모로 Word, Story 클래스 상속해볼 것.
		> 스토리, 단어 셋팅 하나로 합치기(초기 단어 셋팅 시, 위치 임시 부여 0, 단어 추후, 덮어쓰기, 디폴트 사용)
	o > 대문자 상하 이동 해보기(switch -> if문으로 변경?)
	> 단어 지우기 함수화
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

*/
#include "Play.h"

void main()
{
	Play mainPlay;
	mainPlay.GameOn();
}