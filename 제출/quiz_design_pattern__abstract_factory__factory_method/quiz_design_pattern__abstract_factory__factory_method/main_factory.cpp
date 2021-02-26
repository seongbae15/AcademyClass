/* To do */
/*
1.과제 선정 : 미로찾기, 오목, <뱀게임>
 > 뱀게임
2. 작업 설계
  > abstract factory : Block Factory
    - Block : Stone, Feed, + a(Wall(?), Tail(?), head(?))
  > factory method
    - Init, Update, finish
      -> GameManger(play 화면), Feed, Stone, Snake, Main화면
        : 클래스 추가 : Loby화면 관리자, Play화면 관리자
          >> 뷰어 하나에서 관리(생성자 오버로딩으로 나눠보기)
*/
#include "SnakeGameManager.h"

void main()
{
    SnakeGameManager PlayManager;
    PlayManager.GameRun();
    
}