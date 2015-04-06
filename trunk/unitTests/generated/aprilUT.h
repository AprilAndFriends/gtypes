#ifdef __APPLE__

#import <XCTest/XCTest.h>

extern XCTestCase* testInstance;
#define assertTrue(expression, msg) _XCTPrimitiveAssertTrue(testInstance, (expression), @msg)

#else

#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const wchar_t* GetWC(const char* c);
#define assertTrue(expression, msg) Assert::IsTrue((expression), GetWC(msg))

#endif
