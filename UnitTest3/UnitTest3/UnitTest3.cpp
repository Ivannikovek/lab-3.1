#include "pch.h"
#include "CppUnitTest.h"

#include "../../Lab 3/Lab 3/DepthIterator.h"
#include "../../Lab 3/Lab 3/DepthIterator.cpp"

#include "../../Lab 3/Lab 3/BreadthIterator.h"
#include "../../Lab 3/Lab 3/BreadthIterator.cpp"

#include "../../Lab 3/Lab 3/node.h"
#include "../../Lab 3/Lab 3/node.cpp"

#include "../../Lab 3/Lab 3/BinarySearchTree.h"
#include "../../Lab 3/Lab 3/BinarySearchTree.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
Formed tree for test:
					16
		12						40
	5		14				23		66
				15


*/

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		TEST_METHOD(BinarySearchTree_DefaultConstructor)
		{
			BinarySearchTree t;

			//checking that three doesn't contain elements:
			for (size_t i = 0; i < 100; i++)
				Assert::IsFalse(t.contains(i));
		}

		TEST_METHOD(BinarySearchTree_Contains_and_Insert)
		{
			BinarySearchTree t;

			//checking that three doesn't contain values from 1 to 99:
			for (size_t i = 0; i < 100; i++)
				Assert::IsFalse(t.contains(i));

			//checking that three doesn't contain values of array's elements:

			int arr[] = { 16,40,66,23,12,14,15,5 };

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				Assert::IsFalse(t.contains(arr[i]));

			//inserting elements of array:
			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				t.insert(arr[i]);

			//checking that three contains all elements:
			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				Assert::IsTrue(t.contains(arr[i]));

			//checking that three contains random inserted element:
			srand(time(0));

			int N = rand();

			t.insert(N);
			Assert::IsTrue(t.contains(N));
		}

		TEST_METHOD(BinarySearchTree_Remove)
		{
			BinarySearchTree t;

			size_t counter_of_exceptions = 0;

			//checking removing from empty tree values from 1 to 99:
			for (size_t i = 0; i < 100; i++) {
				try {
					t.remove(i);
				}
				catch (...) {
					counter_of_exceptions++;
				}
			}

			Assert::AreEqual(counter_of_exceptions, 0u);

			//checking removing from empty tree values of array's elements:

			int arr[] = { 16,40,66,23,12,14,15,5 };

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++) {
				try {
					t.remove(arr[i]);
				}
				catch (...) {
					counter_of_exceptions++;
				}
			}

			Assert::AreEqual(counter_of_exceptions, 0u);

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				Assert::IsFalse(t.contains(arr[i]));

			//checking that three will remove all even elements:
			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				t.insert(arr[i]);

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
			if (i % 2 == 0)
				t.remove(arr[i]);

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				if (i % 2 == 0)
					Assert::IsFalse(t.contains(arr[i]));
				else
					Assert::IsTrue(t.contains(arr[i]));

		}

		TEST_METHOD(BinarySearchTree_DepthIterator)
		{
			BinarySearchTree t1;

			int arr[] = { 16,40,66,23,12,14,15,5 };
			int arr_sorted_by_increasing[] = { 5,12,14,15,16,23,40,66 };

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				t1.insert(arr[i]);

			DepthIterator di = t1.create_dft_iterator();
			int i = 0;

			//checking that every element is similar waiting sorted by increasing value:
			for (di; di.has_next(); di.next()) {
				Assert::AreEqual(di.get_value(), arr_sorted_by_increasing[i]);
				i++;
			}
		}

		TEST_METHOD(BinarySearchTree_BreadthIterator)
		{
			BinarySearchTree t1;

			int arr[] = { 16,40,66,23,12,14,15,5 };
			int arr_sorted_by_levels[] = { 16, 12,40,5,14,23,66,15 };

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				t1.insert(arr[i]);

			BreadthIterator bi = t1.create_bft_iterator();
			int i = 0;

			//checking that every element is similar waiting sorted by levels value:
			for (bi; bi.has_next(); bi.next()) {
				Assert::AreEqual(bi.get_value(), arr_sorted_by_levels[i]);
				i++;
			}
		}
		TEST_METHOD(BinarySearchTree_CopyConstructor_for_similar_elements)
		{
			BinarySearchTree t1;

			int arr[] = { 16,40,66,23,12,14,15,5 };

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				t1.insert(arr[i]);

			BinarySearchTree t2(t1);

			//checking that both trees contain inserted elements:
			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++) {
				Assert::IsTrue(t1.contains(arr[i]));
				Assert::IsTrue(t2.contains(arr[i]));
			}
		}
		TEST_METHOD(BinarySearchTree_CopyConstructor_for_similar_structure)
		{
			BinarySearchTree t1;

			int arr[] = { 16,40,66,23,12,14,15,5 };

			for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
				t1.insert(arr[i]);

			DepthIterator di1 = t1.create_dft_iterator();
			BreadthIterator bi1 = t1.create_bft_iterator();

			BinarySearchTree t2(t1);

			DepthIterator di2 = t2.create_dft_iterator();
			BreadthIterator bi2 = t2.create_bft_iterator();

			//checking element for equivalence while depth iterating:
			for (; di1.has_next() && di2.has_next(); di1.next(), di2.next())
				Assert::AreEqual(di1.get_value(), di2.get_value());

			//checking that elements over in both trees:
			Assert::IsFalse(di1.has_next());
			Assert::IsFalse(di2.has_next());

			//checking element for equivalence while breadth iterating:
			for (; bi1.has_next() && bi2.has_next(); bi1.next(), bi2.next())
				Assert::AreEqual(bi1.get_value(), bi2.get_value());

			//checking that elements over in both trees:
			Assert::IsFalse(bi1.has_next());
			Assert::IsFalse(bi2.has_next());
		}
	};
}
