#include"Queue.h"
#include<gtest.h>

TEST(Queue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> Q(10));
}

TEST(Queue, can_not_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> Q(-10));
}

TEST(Queue, can_not_create_is_too_long_queue)
{
	ASSERT_ANY_THROW(Queue<int> Q(MaxQueueSize+100));
}

TEST(Queue, operator_Put__can_push_value)
{
	Queue<int> Q(4);

	Q.Put(23);

	EXPECT_EQ(23, Q.Get());
}

TEST(Queue, operator_Get_retrieves_and_removes_element_around)
{
	Queue<int> Q(4);

	Q.Put(1);
	Q.Put(2);
	Q.Put(3);	
	Q.Put(4);	

	Q.Get();
	Q.Get();
	Q.Get();

	Q.Put(5);

	EXPECT_EQ(4, Q.Get());	
}

TEST(Queue, operator_IsEmpty_indicates_that_queue_is_empty)
{
	Queue<int> Q(10);

	Q.Put(1);
	Q.Put(11);
	Q.Put(111);

	Q.Get();
	Q.Get();
	Q.Get();

	EXPECT_EQ(true, Q. IsEmpty());
}

TEST(Queue, operator_IsEmpty_indicates_that_queue_is_not_empty)
{
	Queue<int> Q(10);

	Q.Put(1);
	Q.Put(11);
	Q.Put(111);

	Q.Get();
	Q.Get();
	Q.Get();

	Q.Put(1111);

	EXPECT_EQ(false, Q. IsEmpty());
}

TEST(Queue, operator_IsFull_indicates_that_queue_is_full)
{
	Queue<int> Q(6);

	Q.Put(1);
	Q.Put(11);
	Q.Put(111);
	Q.Put(1);
	Q.Put(11);
	Q.Put(111);

	EXPECT_EQ(true, Q.IsFull());
}

TEST(Queue, operator_IsFull_indicates_that_stack_is_not_full)
{
	Queue<int> Q(6);

	Q.Put(1);
	Q.Put(11);
	Q.Put(111);
	Q.Put(1);
	Q.Put(11);

	EXPECT_EQ(false, Q.IsFull());
}

TEST(Queue, operator_Show_retrieves_but_not_removes_element)
{
	Queue<int> q(4);

	q.Put(23);
	q.Show();

	EXPECT_EQ(23, q.Show());
}

