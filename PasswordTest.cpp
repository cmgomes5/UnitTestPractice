/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, good_pass)
{
	Password test_pass;
	bool result = test_pass.has_mixed_case("Hello");
	ASSERT_EQ(true, result);
	
}

TEST(PasswordTest, bad_pass)
{
	Password test_pass;
	bool result = test_pass.has_mixed_case("hello");
	ASSERT_EQ(false, result);
	
}

TEST(PasswordTest, no_pass)
{
	Password test_pass;
	bool result = test_pass.has_mixed_case("");
	ASSERT_EQ(false, result);
	
}

TEST(PasswordTest, single_char_pass)
{
	Password test_pass;
	bool result = test_pass.has_mixed_case("a");
	ASSERT_EQ(false, result);
	
}

TEST(PasswordTest, num_pass)
{
	Password test_pass;
	bool result = test_pass.has_mixed_case("12345");
	ASSERT_EQ(false, result);
	
}

TEST(PasswordTest, mixed_pass)
{
	Password test_pass;
	bool result = test_pass.has_mixed_case("FooBar1700");
	ASSERT_EQ(true, result);
	
}