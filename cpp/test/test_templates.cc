#include <gtest/gtest.h>

#include "../include/templates.hpp"

class TemplateTest : public testing ::Test {
protected:
  Foo<int> fooInt;
  Foo<double> fooDouble;
  Foo<long int> fooLong;

  Bar<int> barInt;
  Bar<char> barChar;
};

TEST_F(TemplateTest, ExplicitInstanceTypeInt) {
  EXPECT_EQ(fooInt.size(), 0);
  EXPECT_EQ(fooInt.add(1, 2), 3);
  EXPECT_EQ(fooInt.add(100, 200), 300);

  // NOTE:
  //    can compile, but Lsp causes Error
  //    clang: Implicit conversion ...
  //    EXPECT_EQ(foo.Add(100.9, 200.9), 300);

  EXPECT_EQ(fooDouble.size(), 0);
  EXPECT_EQ(fooDouble.add(1, 2), 3);
  EXPECT_EQ(fooDouble.add(100.9, 200.9), 301.8);

  // NOTE:
  //    This can't compile!
  //    Foo<char> foo;
}

TEST_F(TemplateTest, HeaderImpletation) {
  EXPECT_EQ(barInt.size(), 100);
  EXPECT_EQ(barInt.add(10, 20), 30);

  EXPECT_EQ(barChar.add('0', '4'), 'd');  // whaaaat
  EXPECT_EQ(barChar.add('9', '9'), 'r');  // int + int = (char)(int)
}
