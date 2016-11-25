#ifndef __QUEUE_CLASS_H
#define __QUEUE_CLASS_H

const int MaxQueueSize = 1000; 

template < class Type >
class Queue
{
private:
	Type *pMem;		// ������ ��������� �������	 
	int  begin;     // ������ �������
	int  end;       // ����� �������
	int  count_elem;// ���������� ���������					
	int  size;		// ���������� ������ �������

public:
	Queue  ( int _size ); //�����������
	~Queue ( void ); //����������

	void Put(const Type &);	// �������� ����� ������� � �������
	Type Get(void);	// ������� �������, ������, ��� ��� ������ ��� � �������
	Type Show(void); //����� �������, ������, ��� �� ������� � ������� 

	bool IsEmpty (void) const //�������� �������
	{ 
		return (count_elem == 0);
	}		    

	bool IsFull  (void) const // �������� �������
	{ 
		return (count_elem == size); 
	}			

};	

template<class Type>Queue<Type>::Queue( int _size) 											 
{		
	begin=0;
	end=0;
	count_elem=0;
	if ((_size < 1) || (_size > MaxQueueSize)) // �������� �� ������������ �������
	{
		throw (_size);    
	}
	size=_size ;
	pMem = new Type[size + 1];  // ��������� ������ ��� ������ � ������� ��� ��������� � ������ �������
}

template<class Type>Queue<Type>::~Queue()		
{ 
	delete [] pMem;  
	pMem = 0;  
}

template<class Type>void Queue<Type>::Put ( const Type &newElem )
{

	if (IsFull()==true) //�������� �� �������������
	{
		throw("No space");
	}
	pMem[end++] = newElem;  //��������� ����� ������� � ����� ������� 
	count_elem++; //����������� ������� ���������� ���������	
	if (end > size)   //���� ����� �� ����� ������� (end ����� � ��������� ������)
		end -= size + 1; //����������: ���������� end �� ������ ������� 
}


template<class Type>Type Queue<Type>::Get(void)
{
	/* ���������: ���� �� � ������� �������� */
	if ( IsEmpty()==true )
	{
		throw("No elements");
	}
	Type val = pMem[begin++]; //����������� ������������� �������� �������� �� �������
	count_elem--; //��������� ������� ���������� ���������	
	if (begin > size) //���� ����� �� ����� ������� (begin ����� � ��������� ������)
		begin -= size + 1;//����������: ���������� begin �� ������ ������� 
	return val;//���������� ���������� �������
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