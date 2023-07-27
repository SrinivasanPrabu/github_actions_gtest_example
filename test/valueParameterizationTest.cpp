int divFun(int numerator, int denominator){
    if(denominator==0 || denominator < 0){return 0;}

    return numerator/denominator;
}

class divFunTestSuite:public testing::TestWithParam<std::tuple<int,int,int>>{
  protected:
  divFunTestSuite(){
  ~divFunTestSuite(){}
  }
}
TEST_P(divFunTestSuite,HandleValidInputs){
    int numerator=std::get<0>(GetParam());
    int denominator=std::get<1>(GetParam());
    int expectedValue=std::get<2>(GetParam());
    int actualValue=divFun(numerator,denominator);
    ASSERT_EQ(actualValue,expectedValue)
}

Instantiate_TEST_Suite_p(DivFunTestSuiteParameterExample,divFunTestSuite,::testing::Values(
    std::make_tuple(10,5,2),
    std::make_tuple(10,0,0),
    std::make_tuple(10,-5,0),

));

//TEST(divFunTestSuite,HandleValidInputs){
//    int numerator=10;
//    int denominator=-5;
//    int expectedValue=-2;
//    int actualValue=divFun(numerator,denominator);
//    ASSERT_EQ(actualValue,expectedValue)
//}