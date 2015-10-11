#include "stdafx.h"
#include "CppUnitTest.h"
#include "../render/../../../render/src/vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
            vector3<int> v1(3, 3, 3);
            vector3<int> v2(4, 4, 4);
            v1 += v2;
            Assert::IsTrue(v1 == vector3<int>(7, 7, 7));
            v1 -= v2;
            Assert::IsTrue(v1 == vector3<int>(4, 4, 4));
            v1 *= v2;
            Assert::IsTrue(v1 == vector3<int>(12, 12, 12));
            v1 *= 5;
            Assert::IsTrue(v1 == vector3<int>(60, 60, 60));
            vector3<int> v4(3, 3, 3);
            vector3<int> v5(4, 4, 4);
            vector3<int> v6;
            v6 = v4 + v5;
            Assert::IsTrue(v6 == vector3<int>(7, 7, 7));
            v6 = v4 - v5;
            Assert::IsTrue(v6 == vector3<int>(-1, -1, -1));
            v6 = v4 * v5;
            Assert::IsTrue(v6 == vector3<int>(12, 12, 12));
            v6 = v4 * 5;
            Assert::IsTrue(v6 == vector3<int>(15, 15, 15));
            v6 = 5 * v4;
            Assert::IsTrue(v6 == vector3<int>(15, 15, 15));
		}

	};
}