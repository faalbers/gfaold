#include <iostream>
#include <boost/format.hpp>
#include "GFA/Types.h"
#include "GFA/Tuple.h"
#include "GFA/Matrix.h"
#include "GFA/Vector.h"
#include "GFA/Point.h"
#include "GFA/Color.h"
#include "GFA/Space.h"
#include "GFA/FrameBuffer.h"
#include "GFA/Utils.h"

void TestLog(const char *text)
{
    std::cout << "\nTEST: " << text << std::endl;
}

void tupleTest(GFA::Tuple) {}
void tupleTestRef(GFA::Tuple &) {}
void tupleTestArray(GFA::Tuple []) {}
void pointTest(GFA::Point) {}
void pointTestRef(GFA::Point &) {}

int main(int , char **)
{
    GFA::Index index;
    TestLog("Exception");
    try {
        throw GFA::Error("Main", "Throwing an exception");
    } catch (GFA::Error &e) {
        e.what("Testing exceptions !");
        e.what("Cool huh ?");
    }

    TestLog("Testing Tuple creation , copy and destructor");
    GFA::Tuple t,tt(4);
    tupleTest(t);
    tupleTest(tt);
    tupleTestRef(t);
    tupleTestRef(tt);

    TestLog("Testing Tuple array creation");
    GFA::Tuple *tPtr = new GFA::Tuple[2];
    for ( index = 0; index < 2; index ++ ) tPtr[index].Resize(2);
    
    TestLog("Testing Tuple passing to function");
    // does not create copies, it's a pointer that get passed
    tupleTestArray(tPtr);
    
    TestLog("Testing Tuple array deletion");
    delete[] tPtr;
    
    TestLog("Testing Tuple subscripting");
    GFA::Tuple t1 = GFA::Tuple(4);
    t1(2) = 6.0;
    t1(3) = 3.0;
    GFA::Scalar test = t1(2);
    t1.Print();
    
    TestLog("Testing Tuple assignement operation");
    GFA::Tuple t3 = GFA::Tuple(2);
    t3(0) = 1.0;
    t3(1) = 2.0;
    GFA::Tuple t4 = GFA::Tuple(2);
    t4(0) = 2.0;
    t4(1) = 1.0;
    GFA::Tuple t5 = GFA::Tuple(1);
    t3.Print();
    t4.Print();
    t5.Print();
    t5 = t3;
    t3 = t4;
    t4 = t5;
    t3.Print();
    t4.Print();
    t5.Print();

    TestLog("Testing Matrix creation and subscripting");
    GFA::Matrix m1 = GFA::Matrix(4 , 5);
    m1(1,2) = 1.0;
    m1(2,1) = 2.0;
    m1(2,3) = 3.0;
    m1(3,3) = 3.0;
    test = m1(3, 3);
    m1.Print();
    std::cout << test << std::endl;

    TestLog("Testing Matrix assignement operation");
    GFA::Matrix m4 = GFA::Matrix(2,2);
    m4(0,0) = 1.0;
    m4(1,1) = 2.0;
    GFA::Matrix m5 = GFA::Matrix(2,2);
    m5(0,0) = 2.0;
    m5(1,1) = 1.0;
    GFA::Matrix m6 = GFA::Matrix(3,3);
    m4.Print();
    m5.Print();
    m6.Print();
    m6 = m4;
    m4 = m5;
    m5 = m6;
    m4.Print();
    m5.Print();
    m6.Print();

    TestLog("Testing Tuple * Matrix (Cross Product)");
    t1.Print();
    m1.Print();
    GFA::Tuple t2 = t1 * m1;
    t2.Print();

    TestLog("Testing Tuple * Scalar (Product)");
    t2.Print();
    (t2 * 2.0).Print();
    (t2 * 2.0).Print();
    
    TestLog("Testing Matrix * Matrix (Cross Product)");
    GFA::Matrix m2 = GFA::Matrix(5 , 2);
    GFA::Matrix m3;
    m2(3,1) = 7.0;
    m2(0,0) = 2.0;
    m2(4,1) = 3.0;
    m2(2,0) = 2.0;
    m1.Print();
    m2.Print();
    m3 = m1 * m2;
    m3.Print();

    TestLog("Testing some Cross Product exceptions");
    m1 = GFA::Matrix(5 , 5);
    t1 = GFA::Tuple(4);
    try {
        t1 * m1;
    } catch (GFA::Error &e) {
        e.what("This is a test exception !");
    }
    m1 = GFA::Matrix(4 , 5);
    t1 = GFA::Tuple(5);
    try {
        t1 * m1;
    } catch (GFA::Error &e) {
        e.what("This is a test exception !");
    }
    try {
        m2 * m1;
    } catch (GFA::Error &e) {
        e.what("This is a test exception !");
    }

    TestLog("Testing 3 dimentional Vector creation and subscripting");
    GFA::Vector v1 = GFA::Vector(3);
    v1(2) = 6.0;
    v1(1) = 3.0;
    v1.Print();

    TestLog("Testing Point creation , copy and destructor");
    GFA::Point p;
    tupleTest(p);
    tupleTestRef(p);
    pointTest(p);
    pointTestRef(p);
    
    std::cout << "\n\nSCOPE CLOSURE: ... \n" << std::endl;
    return 0;
    
    TestLog("Testing 3 dimentional Point creation and subscripting");
    GFA::Point p1 = GFA::Point(3);
    p1(0) = 5.0;
    p1(1) = 7.0;
    p1.Print();
    
    TestLog("Testing 3 dimentional Point creation from another Point");
    p1.Print();
    GFA::Point p2 = GFA::Point(p1);
    p2.Print();
    
    TestLog("Create Space");
    GFA::Space s1 = GFA::Space(3);
    s1.Print();
    
    TestLog("Create Identity Matrix and testing it");
    GFA::Matrix m7 = GFA::Matrix(4,4);
    m7.Print();
    m7.MakeIdentity();
    m7.Print();
    m7 = GFA::Matrix(3,4);
    try {
        m7.MakeIdentity();
    } catch (GFA::Error &e) {
        e.what("This is a test exception !");
    }

    TestLog("Create Translate Matrix");
    m7 = GFA::Matrix(4,4);
    m7.MakeTranslate();
    m7.Print();
    m7.MakeTranslate(1);
    m7.Print();
    m7.MakeTranslate(1,2);
    m7.Print();
    m7.MakeTranslate(1,2,3);
    m7.Print();

    TestLog("Cross Prod Matrices");
    GFA::Matrix m8 = m7 * m7;
    m8.Print();
    
    TestLog("Cross Prod Point and Vector with Matrix");
    p1.Print();
    v1.Print();
    m8.Print();
    (p1 * m8).Print();
    (v1 * m8).Print();

    TestLog("Testing Color creation and subscripting");
    GFA::Color pi1;
    pi1(0) = 0.60;
    pi1(1) = 0.3;
    pi1.Print();
    
    TestLog("Testing Color assignement operation");
    GFA::Color pi3 = GFA::Color();
    pi3(0) = 1.0;
    pi3(1) = 2.0;
    GFA::Color pi4 = GFA::Color();
    pi4(0) = 2.0;
    pi4(1) = 1.0;
    GFA::Color pi5 = GFA::Color();
    pi3.Print();
    pi4.Print();
    pi5.Print();
    pi5 = pi3;
    pi3 = pi4;
    pi4 = pi5;
    pi3.Print();
    pi4.Print();
    pi5.Print();

    TestLog("Testing Color Array creation");
    GFA::Size count = 4;
    GFA::Color *pixBufferPtr;
    pixBufferPtr = new GFA::Color[count];
    for (index = 0; index < count; index++)
        pixBufferPtr[index].Print();
    if (pixBufferPtr != 0) {
        delete[] pixBufferPtr;
        pixBufferPtr = 0;
    }

    TestLog("Testing Color Array creation second time");
    pixBufferPtr = new GFA::Color[count];
    for (index = 0; index < count; index++)
        pixBufferPtr[index].Print();
    if (pixBufferPtr != 0) {
        delete[] pixBufferPtr;
        pixBufferPtr = 0;
    }
    
    TestLog("Creating a 10 by 10 FrameBuffer");
    GFA::FrameBuffer fb = GFA::FrameBuffer(10,10);
    
    return 0;
}

