/*
o 1. ���ӽ��� ȭ�� �����

2. ����̾߱� ��ũ�� �����
	o > Scroll
	o > Skip
	o > Player �̸� �Է�
		o >> �̸� 10���� �����θ� �Է��ϵ���
		o >> Text ��ġ �̵��ǵ���
3. �ܾ� ����Ʈ����
	> �ܾ� �ҷ�����
	> ���� : �ܾ� �ε���, �ܾ� ��ġ(x,y)
	> 
4. �ܾ� ���߱�(��������)
5. Stage��� �����
6. Rank�ý��� �����
7. �����۱�� �߰�
8. �Լ�ȭ

<����>
1. player �̸� 10���� �̳�
2. player �̸� ������ �Էµǵ���(�ѱ� ����x)

<class>
Play class = ��ü ���� �帧 ���� Class
WardManager Class = �ܾ�� ���� Class //�ܾ�� ������������� ������
Ward = �ܾ� Class , �ʿ� �ɹ� ���� x,y,string �ʿ� 
	>�ɹ��Լ� draw drop Live Die
Rank Class = Rank �ý��� ���� Class
Interface Class = �������� ��� �׸� ���� Class

<������>
1.����ӵ� ����
2.����ӵ� ����
3.�����Ͻ�����
4.ȭ��Ŭ����
5.���尡����(1.5��)

<��ŷ�ý���>
���� �������� ����
����,�ҷ�����
*/
#include "Play.h"

void main()
{
	Play mainPlay;
	mainPlay.GameOn();
}