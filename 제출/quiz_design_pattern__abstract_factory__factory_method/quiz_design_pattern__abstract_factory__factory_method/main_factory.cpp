/* To do */
/*
1.���� ���� : �̷�ã��, ����, <�����>
 > �����
2. �۾� ����
  > abstract factory : Block Factory
    - Block : Stone, Feed, + a(Wall(?), Tail(?), head(?))
  > factory method
    - Init, Update, finish
      -> GameManger(play ȭ��), Feed, Stone, Snake, Mainȭ��
        : Ŭ���� �߰� : Lobyȭ�� ������, Playȭ�� ������
          >> ��� �ϳ����� ����(������ �����ε����� ��������)
*/
#include "SnakeGameManager.h"

void main()
{
    SnakeGameManager PlayManager;
    PlayManager.GameRun();
    
}