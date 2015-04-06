#ifdef __APPLE__

#import <XCTest/XCTest.h>

XCTestCase* testInstance = nil;

#else

#include <stdio.h>
#include <string.h>
static wchar_t wc[2048];

const wchar_t* GetWC(const char* c)
{
    const size_t cSize = strlen(c) + 1;
   
	for (unsigned int i = 0; i <= cSize; i++)
	{
		wc[i] = c[i];
	}
    return wc;
}

#endif
