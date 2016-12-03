#include <string>
#include <iostream>
#include "processor.h"

int main()
{	
	setlocale(LC_ALL, "Russian");

	using namespace std;
	double RiftCreation = 0; //порог для создания задачи	
	double KeyCreation=0;//ключ для создания задачи
	double RiftExecution=0; //порог для завершения задачи
	double KeyExecution=0;//ключ для завершения задачи

	int SizeQueue=0; //размер очереди
	int MaxCost=0;//максимальная стоимость задачи
	int Cost=0;//генерируемая стоимость задачи

	int Stop=1; //количество тактов до времени остановки и вывода статистики

	int count; // переменная для выбора в switch

	cout << "Выберете способ задания параметров : "<<endl<<" 1) по умолчанию "<<endl<<" 2) вручную  "<<endl;
	cin >> count;

	switch (count) // начало оператора switch
	{
	case 1: 
		{   
			system("cls");
			RiftCreation=0.6;   cout<<"  Порог для появления задачи:  "<<RiftCreation<<endl;
			RiftExecution=0.7;  cout<<"  Порог для завершения задачи:  "<<RiftExecution<<endl;
			SizeQueue=10;        cout<<"  Размер очереди:  "<<SizeQueue<<endl;
			MaxCost=16;         cout<<"  Максимально возможная стоимость задачи:  "<<MaxCost<<endl;
			Stop=5000000;       cout<<"  Количество тактов до автоматической остановки и вывода статистики - "<<Stop<<endl;
			break;
		}
	case 2: 
		{    system("cls");

		cout<<"Введите порог для появления задачи: ";
		cin >> RiftCreation;
		cout<<"Введите порог для завершения задачи: ";
		cin >> RiftExecution;	
		cout<<"Введите размер очереди: ";
		cin >> SizeQueue;
		cout<< "Максимальное количество тактов для выполнения задачи: ";
		cin >> MaxCost;
		cout<< "Количество тактов до автоматической остановки и вывода статистики: ";
		cin >> Stop;
		break;
		}
	}
	cout << endl << "Press any key to open the Stats " << endl;

	Processor pro(RiftCreation,RiftExecution,SizeQueue,MaxCost,Stop);
	pro.Worker(RiftCreation,RiftExecution,SizeQueue,MaxCost,Stop);
	pro.PrintStats();
	return 0;
}
