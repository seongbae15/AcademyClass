#include <iostream>
#include <string>
using namespace std;

template <typename Type>
struct Data
{
	Type Dt;
	Data* Link;
};

template <typename Type>
void Push(Data<Type>** Top, Type data)
{
	Data<Type>* TmpLink = new Data<Type>;
	TmpLink->Link = *Top;
	TmpLink->Dt = data;
	*Top = TmpLink;
	cout << "Push : " << (*Top)->Dt<<endl;
}

template <typename Type>
void Pop(Data<Type>** Top)
{
	if (*Top == NULL)
	{
		cout << "No Data" << endl;
		return;
	}
	Data<Type>* Tmp = *Top;
	*Top = Tmp->Link;
	cout << "Pop : " << Tmp->Dt << endl;
	delete Tmp;

}

void main()
{
	Data<int> *Top = NULL;
	Data<float>* Top2 = NULL;
	Data<char>* Top3 = NULL;
	Data<string>* Top4 = NULL;
	string str1 = "ABC", str2 = "DEF";
	Push(&Top,10);
	Push(&Top, 20);
	Pop(&Top);
	Pop(&Top);
	Pop(&Top);
	Push(&Top2, 10.2f);
	Push(&Top2, 20.2f);
	Pop(&Top2);
	Pop(&Top2);
	Pop(&Top2);
	Push(&Top3, 'a');
	Push(&Top3, 'b');
	Pop(&Top3);
	Pop(&Top3);
	Pop(&Top3);
	Push(&Top4, str1);
	Push(&Top4, str2);
	Pop(&Top4);
	Pop(&Top4);
	Pop(&Top4);
}