#include "SimpleCalculator.h"
#include "cppunit/TestCase.h"
#include "cppunit/TestResult.h"
#include "cppunit/TextOutputter.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestCaller.h"
#include "cppunit/extensions/HelperMacros.h"

class SimpleCalcTest : public CPPUNIT_NS::TestFixture{

    CPPUNIT_TEST_SUITE( SimpleCalcTest );
        CPPUNIT_TEST( testAdd );
        CPPUNIT_TEST( testSub );
        CPPUNIT_TEST( testMul);
        CPPUNIT_TEST( testDiv );
        CPPUNIT_TEST( testThrow );
    CPPUNIT_TEST_SUITE_END();

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

  void testThrow(){       
         CPPUNIT_ASSERT_THROW( sc->div(12,0), std::overflow_error );
     }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SimpleCalcTest );

int main()
{
    CPPUNIT_NS::TestResult r;
    CPPUNIT_NS::TestResultCollector result;
    r.addListener( &result );

    CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest()->run( &r );
    CPPUNIT_NS::TextOutputter out( &result, std::cout );
    out.write();
    return 0;
}

