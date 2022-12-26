#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix A("1+2/3"));
}
TEST(TPostfix, can_convert_to_postfix)
{
	TPostfix A("1+2/3-12+(3*5)-(15+2)");
	ASSERT_NO_THROW(A.GetPostfix());
}
TEST(TPostfix, works_currently)
{
	TPostfix A("1+(3*5)/(15^1)");
	ASSERT_EQ(A.calculate(), 2);
}
TEST(TPostfix, check_pow)
{
	TPostfix A("2^10");
	ASSERT_EQ(A.calculate(), 1024);
}
TEST(TPostfix, can_get_infix_form)
{

	TPostfix A("1+(3*5)/(15*1)");
	ASSERT_EQ("1+(3*5)/(15*1)", A.GetInfix());
}
TEST(TPostfix, can_get_postfix_form)
{
	TPostfix A("1+2/3-12+(3*5)/(15*1)");
	ASSERT_EQ("1 2 3 /+12 -3 5 *15 1 */+", A.GetPostfix());

}
TEST(TPostfix, can_parse_digits)
{

	TPostfix A("1241     ");
	ASSERT_EQ(A.calculate(), 1241);
}
TEST(TPostfix, can_parse_with_brackets)
{
	TPostfix A("12+(1+4)/5");
	ASSERT_EQ(A.GetInfix(), "12+(1+4)/5");

}
TEST(TPostfix, can_add)
{
	TPostfix A("2+8");
	ASSERT_EQ(10.0, A.calculate());

}
TEST(TPostfix, can_div)
{
	TPostfix A("20/2");
	ASSERT_EQ(10.0, A.calculate());

}
TEST(TPostfix, can_mult)
{
	TPostfix A("5*2");
	ASSERT_EQ(10.0, A.calculate());

}
TEST(TPostfix, can_sub)
{
	TPostfix A("12-2");
	ASSERT_EQ(10.0, A.calculate());

}
TEST(TPostfix, can_make_number_from_str)
{
	string s("ahb 123jf");
	TPostfix A(s);
	ASSERT_EQ(A.calculate(), 123);

}
TEST(TPostfix, can_get_postfix_different_priority)
{
	TPostfix A("10-(3*5)/(20-5)+(3-22/11)");
	ASSERT_EQ(10.0, A.calculate());

}
TEST(TPostfix, throws_with_troubles_with_brackets)
{
	ASSERT_ANY_THROW(TPostfix A("((1+34"));

}

TEST(TPostfix, checking_of_constructor)
{
	ASSERT_NO_THROW(TPostfix A("12+1238-(228-135)/12"));

}