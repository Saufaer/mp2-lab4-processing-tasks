#include <string>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "queue.h"

void Process()
{
	using namespace std;

	struct Task // структура-задача
	{
		int tact; //кол-во тактов, необходимое для выполнения задачи(её стоимость)
	};

	double RiftCreation = 0; //порог для создания задачи	
	double KeyCreation=0;//ключ для создания задачи
	double RiftExecution=0; //порог для завершения задачи
	double KeyExecution=0;//ключ для завершения задачи

	int SizeQueue; //размер очереди
	int MaxCost;//стоимость задачи

	double Performed = 0;       //сколько задач выполенено
	double Inqueue = 0;         //сколько задач в очереди
	double AverageTime = 0;     //среднее время выполнения задачи
	double TotalTime = 0;       //общее число тактов работы сиситемы
	double DownTime = 0;        //число тактов простоя процессора
	double Refusals = 0;        //сколько задач получили отказ от обслуживания
	double WorkTime = 0;        //время полезной обработки задач

	double Stop=0; //количество тактов до времени остановки и вывода статистики

	int count; // переменная для выбора в switch
	cout << "Выберете способ задания параметров : "<<endl<<" 1) по умолчанию "<<endl<<" 2) вручную  "<<endl;
	cin >> count;

	switch (count) // начало оператора switch
	{
	case 1: 
		{
			RiftCreation=0.6;   cout<<"  Порог для появления задачи:  "<<RiftCreation<<endl;
			RiftExecution=0.8;  cout<<"  Порог для завершения задачи:  "<<RiftExecution<<endl;
			SizeQueue=8;        cout<<"  Размер очереди:  "<<SizeQueue<<endl;
			MaxCost=15;         cout<<"  Максимально возможная стоимость задачи:  "<<MaxCost<<endl;
			Stop=10000000;      cout<<"  Количество тактов до автоматической остановки и вывода статистики - "<<Stop<<endl;

			break;
		}
	case 2: 
		{    
			cout<<"Введите порог для появления задачи: ";
			cin >> RiftCreation;
			cout<<"Введите порог для завершения задачи:  ";
			cin >> RiftExecution;	
			cout<<"Введите размер очереди: ";
			cin >> SizeQueue;
			cout<< "Максимальное количество тактов для выполнения задачи: ";
			cin >> MaxCost;
			cout<< "Количество тактов до автоматической остановки и вывода статистики: ";
			cin >> Stop;
			if ((RiftCreation<=0)||(RiftCreation>=1)||
				(RiftExecution<=0)||(RiftExecution>=1)||
				(SizeQueue<=0)||(SizeQueue>=MaxQueueSize)||
				(MaxCost<=0)||(Stop<0) )
				throw("wrong data");
			break;
		}
	}
	Queue<int> queue(SizeQueue);//создание очереди
	cout << endl << "Press any key to open the Stats " << endl;
	while ((TotalTime<Stop)&&(!_kbhit()))
	{

		Task task;//создание задачи
		task.tact = rand() % MaxCost + 1;//генерация тактовой стоимости (от 0 до заданного максимума) 
		KeyCreation =  (double)(rand())/RAND_MAX  ; // создаем случайный ключ [0;1]


		if (KeyCreation > RiftCreation)
		{
			if ((queue.IsFull()))//если очередь полна
			{
				Refusals++;//то задача получит отказ
			}
			else//если есть место в очереди
			{
				queue.Put(task.tact);//положим задачу в очередь
			}
		}
		if (queue.IsEmpty())//если очередь пуста			
		{
			DownTime++;//добавим такт простоя
			TotalTime++;//добавим такт в общее время
		}
		else 
		{
			KeyExecution = (double)(rand())/RAND_MAX ; // создаем случайный ключ [0;1]
			if (KeyExecution>RiftExecution)
			{
				queue.Get();//выход выполненной задачи из очереди (выполнили)
				TotalTime+=task.tact;//такты , затраченные на выполение задачи 
				Performed++;//количество выполенных задач
			}

			else//если задача не завершилась 
			{
				DownTime++;//добавим такт простоя
				TotalTime++;//добавим такт в общее время
			}
		}

		Inqueue = queue.GetCount();//текущее количество элементов в очереди
	}	

	WorkTime=TotalTime-DownTime;//время полезной обработки задач
	AverageTime = WorkTime / Performed;//среднее время выполнения задачи

	cout << endl << "   Статистика  " <<endl<<endl;
	cout << "  Сколько задач выполенено:  " << Performed << endl;
	cout << "  Сколько задач в очереди:  " << Inqueue << endl;
	cout << "  Среднее время выполнения задачи:  "  << AverageTime << endl;
	cout << "  Общее число тактов работы сиситемы:  "  << TotalTime << endl;
	cout << "  Число тактов простоя процессора:  "    << DownTime << endl;	
	cout << "  Сколько задач получили отказ от обслуживания:  " << Refusals << endl;
	cout << "  Время полезной обработки задач:  "    << WorkTime  << endl<<endl;	       
}

int main()
{

	setlocale(LC_ALL, "Russian");
	srand(unsigned int(time(NULL)));
	Process();
	return 0;
}
