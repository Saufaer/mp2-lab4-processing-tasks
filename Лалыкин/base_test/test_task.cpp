#include<gtest.h>
#include "task.h"

TEST(Task, can_create_task_with_positive_length)
{
	ASSERT_NO_THROW(Task T(10));
}

TEST(Task, can_not_create_task_with_negative_length)
{
	ASSERT_ANY_THROW(Task T(-10));
}

