#include "Number.h"

void main()
{
	Number N1(10, 20), N2(5, 40),N3;
	N1.ShowNum();
	N2.ShowNum();
	cout << "��ü/��ü" << endl;
	N3 = N1 / N2;
	N3.ShowNum();

}