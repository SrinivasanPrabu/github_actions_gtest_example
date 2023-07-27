#include "gtest/gtest.h"
using testing::Types;

class ITempSensor{
  public:
  virtual int getOutSideTemp()=0;
};
class ModelATempSensor:public ITempSensor{
  public:
  virtual int getOutSideTemp(){return 23;}
};
class ModelBTempSesnor:public ITempSensor{
  public:
  virtual int getOutSideTemp(){return 23;}
};
class ModelCTempSensor: public ITempSensor{
  public:
  virtual int getOutsidetemp(){return 23;}
}:
class AutoTempRegulator{
  ITempSensor*tempSensorPtr;
  public:
  AutoTempRegulator(ITempSensor*address):tempSensorPtr{address} {}
    void regulateTemp(){
         return this->tempSesnorPtr->getOutsideTemp();
    }
};

template <typename T>
ITempSensor*createObject();
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSesnor>() { return new ModelBTempSesnor(); }
template <>
ITempSensor* createObject<ModelCTempSensor>() { return new ModelCTempSensor(); }

template <typename T>
class ModelATempSensorFixture:public testing::Test{
  protected:
  ModelATempSensorFixture():objUnder
  //arrange
  ITempSensor* objUndertest;

}
//TEST_F(ModelATempSensorFixture,GetTempTest){
//  ASSERT_EQ(objUnderTest.getOutsideTemp(),23);
//}

typedef Types.<ModelATempSensor,ModelBTempSesnor> Implementation;

TYPED_TEST_SUITE(TempSensorFixture,Implementations);

TYPED_TEST(TempSensorFixture,getTempTest){
ASSERT_EQ(objUnderTest->getOutsideTemp(),23);
};
