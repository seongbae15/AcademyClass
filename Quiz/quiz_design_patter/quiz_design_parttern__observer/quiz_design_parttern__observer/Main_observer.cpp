/*
<���� ���>
1. Player1 ���� : w a s d
2. Player2 ���� : i j k l
3. ��ǥ
	> 2���� ��ǥ���� ����.
4. ���ӿ��� ����
	> �÷��̾� 1, 2 ��� ���� ����
		>> �÷��̾� ���� ���� ����
			1) ������ ������ ��(��ư ���� �÷��̾ ����)
			2) ���� Awake ���¿��� ���� ������ �̵����� ��,
5. ����
	1) ��ư 3�� ����
		> Pass : �ƹ��� ����x
		> Wake : ���� ���� ����
			>> sleep -> awake
			>> awake -> attack
		>> sleep or wake
			>> sleep -> awake
			>> awake -> sleep
			>> attack -> awake
		- �޸� ����
*/

#include "GameManager.h"

void main()
{
	GameManager Gm;
	Gm.StartGame();
}