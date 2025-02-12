#include "gtest/gtest.h"




using testing::Types;




 




class ITempSensor{




    public:




    virtual int getOutSideTemp()=0;




};




class ModelATempSensor:public ITempSensor{




    public:




    int getOutSideTemp(){




        return 23;




    }




};




class ModelBTempSensor:public ITempSensor{




    public:




    int getOutSideTemp(){




        return 23;




    }




};




class ModelCTempSensor:public ITempSensor{




    public:




    int getOutSideTemp(){




        return 23;




    }




};




class AutoTempRegulator{




    //DIP: Abstraction




    ITempSensor* tempSensorPtr;




    public:




    AutoTempRegulator(ITempSensor* address):tempSensorPtr(address){}




    int regulateTemp(){




        return this->tempSensorPtr->getOutSideTemp();




    }




};




 




template <typename T>




ITempSensor* createObject();




template <>




ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }




template <>




ITempSensor* createObject<ModelBTempSensor>() { return new ModelBTempSensor(); }




template <>




ITempSensor* createObject<ModelCTempSensor>() { return new ModelCTempSensor(); }




 




template <typename T>




class TempSensorFixture:public testing::Test{




    protected:




    //Arrange




    ITempSensor* objUnderTest;




    TempSensorFixture() :objUnderTest{ createObject<T>() } {}




};




 




typedef Types<ModelATempSensor,ModelBTempSensor,ModelCTempSensor> Implementations;




 




TYPED_TEST_SUITE(TempSensorFixture, Implementations);




 




TYPED_TEST(TempSensorFixture, GetTempTest) {




    ASSERT_EQ(this->objUnderTest->getOutSideTemp(),23);




}




 class FakeTempSensor:public ITempSensor{

    public:

    int getOutsideTempCallCount=0;

    int getOutSideTemp(){ getOutsideTempCallCount+=1;return  0;}

};







TEST(AutoTempRegulatorTestSuite,RegulateTempTest){

    FakeTempSensor mockObj;

    AutoTempRegulator codeUnderTest(&mockObj);

    codeUnderTest.regulateTemp(); //Interaction

    ASSERT_EQ(mockObj.getOutsideTempCallCount, 1); //Expectation

}