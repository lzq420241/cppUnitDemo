#include "SimpleCalculator.h"
#include "cppunit/TestCase.h"
#include "cppunit/TestResult.h"
#include "cppunit/TextOutputter.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestCaller.h"
#include "cppunit/extensions/HelperMacros.h"

class SimpleCalcTest : public CPPUNIT_NS::TestFixture{
private :
 SimpleCalculator * sc;

public:
 virtual void setUp(){
         sc = new SimpleCalculator();
     }
     virtual void tearDown(){
         delete sc;  
     }
 
 void testAdd(){       
         CPPUNIT_ASSERT_EQUAL( sc->add(5,6), 11);
     }

 void testSub(){       
         CPPUNIT_ASSERT_EQUAL( sc->sub(5,6), -1 );
     }

     void testMul(){       
         CPPUNIT_ASSERT_EQUAL( sc->mul(5,6), 30 );
     }

 void testDiv(){       
         CPPUNIT_ASSERT_EQUAL( sc->div(12,6), 2 );
     }
};

int main()
{
    CPPUNIT_NS::TestResult r;
    CPPUNIT_NS::TestResultCollector result;
    r.addListener( &result );

    CPPUNIT_NS::TestCaller<SimpleCalcTest> testCase1( "testAdd", &SimpleCalcTest::testAdd );
    CPPUNIT_NS::TestCaller<SimpleCalcTest> testCase2( "testSub", &SimpleCalcTest::testSub );
    CPPUNIT_NS::TestCaller<SimpleCalcTest> testCase3( "testMul", &SimpleCalcTest::testMul );
    CPPUNIT_NS::TestCaller<SimpleCalcTest> testCase4( "testDiv", &SimpleCalcTest::testDiv );
   
    testCase1.run( &r );
    testCase2.run( &r );
    testCase3.run( &r );
    testCase4.run( &r );
   
    CPPUNIT_NS::TextOutputter out( &result, std::cout );
    out.write();
    return 0;
}

