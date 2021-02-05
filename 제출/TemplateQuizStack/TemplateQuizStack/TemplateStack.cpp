#include <iostream>

using namespace std;
template <typename Type>
struct Data
{
	Type dt;
	Data* Link;
};

template <typename Type>
void Push(Data<Type>** Top, Type Data)
{
	Data<Type>* Tmp = new Data<Type>;
}

void Pop()
{

}

void main()
{
	Data<int> *Top = NULL;
	Push(&Top,10);
}