#include "gtest/gtest.h"

class C{};
class B{
    C*ptr;
    public;
    B(C* addressofObject): ptr(addressofObject){

    }
};

class A{
    C*ptr;
    public;
    A(B* addressofObject): ptr(addressofObject){

    }
    bool operation(){
         return true;
    }
   
};

//Fixtures class
class TestFixtureTestSuite:public testing::Test{
protected;
TestFixtureTestSuite(){
  //initialization
}
~TestFixtureTestSuite(){
  //releasing the resource
}

void SetUp(){
  //Arrange
  this->cPtr=new C();
  this->bPtr+new B(cPtr);
  this->aPtr=new A(bPtr);
}

void TearDown(){
  //delete resources
  delete cPtr;
  delete bPtr;
  delete aPtr;
}
};

TEST_F("TestFixtureTestSuite","OperationTrueTest"){
  //Act and Assert
  ASSERT_TRUE(aPtr->operation());
}

TEST_F("TestFixtureTestSuite","OperationFalseTest"){
  //Act and Assert
  ASSERT_TRUE(aPtr->operation());
}

//TEST("TestFixtureTestSuite","OperationTest"){
//  C obj;
//  B bObj(&cObj);
//  A obj(&bObj);
//  //Act and Assert
//  ASSERT_FALSE(obj.operation());
//}
