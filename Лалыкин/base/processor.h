#ifndef __PROCESSOR_CLASS_H
#define __PROCESSOR_CLASS_H
#include <string>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "queue.h"
#include "task.h"
const int MaxCostTask=1000;
class Processor
{
private:
	double RiftCreation ; //порог для создания задачи	
	double KeyCreation;//ключ для создания задачи
	double RiftExecution; //порог для завершения задачи
	double KeyExecution;//ключ для завершения задачи

	int SizeQueue; //размер очереди
	int MaxCost;//максимальная стоимость задачи
	int Cost;//генерируемая стоимость задачи

	double Stop;             //количество тактов до времени остановки и вывода статистики	


public:
	double Performed ;       //сколько задач выполенено
	double Inqueue ;         //сколько задач в очереди
	double AverageTime ;     //среднее время выполнения задачи
	double TotalTime ;       //общее число тактов работы сиситемы
	double DownTime ;        //число тактов простоя процессора
	double Refusals ;        //сколько задач получили отказ от обслуживания
	double WorkTime ;        //время полезной обработки задач

	Processor(double RiftCr,double RiftEx,int SizeQ,int MaxC,int stop)//конструктор
	{
		if ((RiftCr <=0)||(RiftCr>=1)) throw(RiftCr);
		RiftCreation=RiftCr; 
		if ((RiftEx <=0)||(RiftEx>=1)) throw(RiftEx);
		RiftExecution=RiftEx;
		if ((SizeQ <=0)||(SizeQ>MaxQueueSize)) throw(SizeQ);
		SizeQueue=SizeQ;
		if ((MaxC <=0)||(MaxC>MaxCostTask)) throw(MaxC);
		MaxCost=MaxC;
		if (stop <=0) throw(stop); 
		Stop=stop;

		Performed=0;
		Inqueue=0;
		AverageTime=0;
		TotalTime=0;
		DownTime=0;
		Refusals=0;
		WorkTime=0;
	}
	void Worker(double RiftCr,double RiftEx,int SizeQ,int MaxC,int stop)
	{
		srand(unsigned int(time(NULL)));
		Queue<int> queue(SizeQueue);//создание очереди
		while ((TotalTime<Stop)&&(!_kbhit()))
		{
			Cost = rand() % MaxCost + 1;//генерация тактовой стоимости (от 0 до заданного максимума) 
			Task task(Cost);//создание задачи
			KeyCreation =  (double)(rand())/RAND_MAX  ; // создаем случайный ключ [0;1]

			if (KeyCreation > RiftCreation)
			{
				if ((queue.IsFull())==true)//если очередь полна
				{
					Refusals++;//то задача получит отказ
				}
				else//если есть место в очереди
				{
					queue.Put(Cost);//положим задачу в очередь
				}
			}
			if (queue.IsEmpty()==false)//если очередь не пуста			
			{
				KeyExecution = (double)(rand())/RAND_MAX ; // создаем случайный ключ [0;1]
				if (KeyExecution>RiftExecution)
				{
					queue.Get();//выход выполненной задачи из очереди (выполнили)
					TotalTime+=Cost;//такты , затраченные на выполение задачи 
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
	}
	void PrintStats()
	{
		using namespace std;
		cout << endl << "   Статистика  " <<endl<<endl;
		cout << "  Сколько задач выполенено:  " << Performed << endl;
		cout << "  Сколько задач в очереди:  " << Inqueue << endl;
		cout << "  Среднее время выполнения задачи:  "  << AverageTime << endl;
		cout << "  Общее число тактов работы сиситемы:  "  << TotalTime << endl;
		cout << "  Число тактов простоя процессора:  "    << DownTime << endl;	
		cout << "  Сколько задач получили отказ от обслуживания:  " << Refusals << endl;
		cout << "  Время полезной обработки задач:  "    << WorkTime  << endl<<endl;
	}
};

#endif
