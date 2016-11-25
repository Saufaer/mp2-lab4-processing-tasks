#ifndef __QUEUE_CLASS_H
#define __QUEUE_CLASS_H

const int MaxQueueSize = 1000; 

template < class Type >
class Queue
{
private:
	Type *pMem;		// массив элементов очереди	 
	int  begin;     // начало очереди
	int  end;       // конец очереди
	int  count_elem;// количество элементов					
	int  size;		// задаваемый размер очереди

public:
	Queue  ( int _size ); //конструктор
	~Queue ( void ); //деструктор

	void Put(const Type &);	// добавить новый элемент в очередь
	Type Get(void);	// извлечь элемент, считая, что его больше нет в очереди
	Type Show(void); //взять элемент, считая, что он остался в очереди 

	bool IsEmpty (void) const //проверка пустоты
	{ 
		return (count_elem == 0);
	}		    

	bool IsFull  (void) const // проверка полноты
	{ 
		return (count_elem == size); 
	}			

};	

template<class Type>Queue<Type>::Queue( int _size) 											 
{		
	begin=0;
	end=0;
	count_elem=0;
	if ((_size < 1) || (_size > MaxQueueSize)) // проверка на допустимость размера
	{
		throw (_size);    
	}
	size=_size ;
	pMem = new Type[size + 1];  // выделение памяти под массив с запасом для переходов в начало очереди
}

template<class Type>Queue<Type>::~Queue()		
{ 
	delete [] pMem;  
	pMem = 0;  
}

template<class Type>void Queue<Type>::Put ( const Type &newElem )
{

	if (IsFull()==true) //проверка на заполненность
	{
		throw("No space");
	}
	pMem[end++] = newElem;  //добавляем новый элемент в конец очереди 
	count_elem++; //увеличиваем счётчик количества элементов	
	if (end > size)   //если дошли до конца массива (end попал в резервную ячейку)
		end -= size + 1; //закругляем: возвращаем end на начало очереди 
}


template<class Type>Type Queue<Type>::Get(void)
{
	/* проверяем: есть ли в очереди элементы */
	if ( IsEmpty()==true )
	{
		throw("No elements");
	}
	Type val = pMem[begin++]; //присваиваем возвращаемому элементу значение из очереди
	count_elem--; //уменьшаем счётчик количества элементов	
	if (begin > size) //если дошли до конца массива (begin попал в резервную ячейку)
		begin -= size + 1;//закругляем: возвращаем begin на начало очереди 
	return val;//возвращаем полученный элемент
}

template<class Type>Type Queue<Type>::Show(void)
{
	if (IsEmpty()==true) 
	{
		throw("no elements");
	}
	return pMem[begin];
}

#endif