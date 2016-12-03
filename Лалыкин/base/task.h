#ifndef __TASK_CLASS_H
#define __TASK_CLASS_H

class Task
{
		int tact; //кол-во тактов, необходимое для выполнения задачи(её стоимость)
public:
	Task(int _tact)
	{
	if (_tact <=0) throw(_tact);
	tact = _tact;
	}
};

#endif
