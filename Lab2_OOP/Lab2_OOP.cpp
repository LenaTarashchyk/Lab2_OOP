// Lab2_OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Stack.h"
#include "StaticArray.h"
#include "LinkedDeque.h"
#include "LinkedList.h"
#include "Queue.h"
#include <vector>
int _tmain(int argc, _TCHAR* argv[])
{
	vector<ContainerInterface*> Vect;
	Vect.push_back(new Stack());
	Vect.push_back(new Queue());
	Vect.push_back(new StaticArray(10));
	Vect.push_back(new LinkedList());
	Vect.push_back(new LinkedDeque());
	for(int i = 0;i<Vect.size();i++)
		for(int j = 0;j<10;j++){
			auto tmp = dynamic_cast<PushPopContainerInterface*>(Vect[i]);
			if(tmp)
				tmp->push(j);
			auto tmp2 = dynamic_cast<Deque*>(Vect[i]);
			if(tmp2)
			{
				tmp2->pushFront(j);
				tmp2->pushBack(j);
			}
			auto tmp3 = dynamic_cast<IndexedContainer*>(Vect[i]);
			if(tmp3)
				tmp3->set(j,j);
		
		}
		for(int i = 0;i<Vect.size();i++)
		cout << Vect[i]->toString() << endl;
		cout << endl;
	for(int i = 0;i<Vect.size();i++)
	{	//cout << Vect[i]->toString() << endl;
			auto tmp = dynamic_cast<PushPopContainerInterface*>(Vect[i]);
			if(tmp) {
				//tmp->pop();
				while(!tmp->isEmpty())
				{
					cout<<tmp->pop()<<endl;

				}
			}
			auto tmp2 = dynamic_cast<Deque*>(Vect[i]);
			if(tmp2)
			{
				/*tmp2->popFront();
				tmp2->popBack();*/
				while(!tmp2->isEmpty())
				{
					cout<<tmp2->popBack()<<endl;
				}
			}
	}
	for(int i = 0;i<Vect.size();i++)
		cout << Vect[i]->toString() << endl;
	cout << endl;
	//cout << dynamic_cast<Deque*>(Vect[4])->peekFront() << " " << dynamic_cast<Deque*>(Vect[4])->peekBack();
	cout << endl;
	//cout << dynamic_cast<PushPopContainerInterface*>(Vect[1])->peek();
	cout << endl;
	cout<<endl;

	auto arr = dynamic_cast<InsertableContainer*>(Vect[3]);
	arr->insertAt(3,-1);
	cout << arr->toString() << endl;
	arr->removeAt(3);
	cout << arr->toString() << endl;
	system("pause");
	return 0;
}

