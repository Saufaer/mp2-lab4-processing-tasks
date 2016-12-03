#include<gtest.h>
#include "processor.h"


TEST(Processor, can_create_processor_with_normal_parameters)
{
	ASSERT_NO_THROW(Processor P(0.6,0.7,10,16,50000));
}

TEST(Processor, can_not_create_processor_with_one_negative_parameter)
{
	ASSERT_ANY_THROW(Processor P(-0.6,0.7,10,16,50000));
}

TEST(Processor, can_not_create_processor_with_second_negative_parameter)
{
	ASSERT_ANY_THROW(Processor P(0.6,-0.7,10,16,50000));
}

TEST(Processor, can_not_create_processor_with_third_negative_parameter)
{
	ASSERT_ANY_THROW(Processor P(0.6,0.7,-10,16,50000));
}

TEST(Processor, can_not_create_processor_with_fourth_negative_parameter)
{
	ASSERT_ANY_THROW(Processor P(0.6,0.7,10,-16,50000));
}

TEST(Processor, can_not_create_processor_with_fifth_negative_parameter)
{
	ASSERT_ANY_THROW(Processor P(0.6,0.7,10,16,-50000));
}

TEST(Processor, can_not_create_processor_with_one_too_large_parameter)
{
	ASSERT_ANY_THROW(Processor P(12,0.7,10,16,50000));
}

TEST(Processor, can_not_create_processor_with_second_too_large_parameter)
{
	ASSERT_ANY_THROW(Processor P(0.6,11,10,16,50000));
}

TEST(Processor, can_not_create_processor_with_third_too_large_parameter)
{
	ASSERT_ANY_THROW(Processor P(0.6,0.7,MaxQueueSize+2,16,50000));
}

TEST(Processor, can_not_create_processor_with_fourthe_too_large_parameter)
{
	ASSERT_ANY_THROW(Processor P(0.6,0.7,10,MaxCostTask+3,50000));
}

TEST(Processor, can_not_create_processor_with_fifth_zero__parameter)
{
	ASSERT_ANY_THROW(Processor P(0.6,0.7,10,16,0));
}

