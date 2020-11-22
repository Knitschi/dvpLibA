#include <dvpLibA/libA.h>
#include <iostream>

#include <dvpLibB1_2_0_0/libB1.h>
#include <dvpLibB2_1_0_0/libB2.h>

namespace dvpLibA
{
	void workWithValueType()
	{
		auto foo1 = dvpLibB1_2_0_0::b1ReturnValueType();
		dvpLibB2_1_0_0::b2UseValueType(foo1);

		auto foo2 = dvpLibB2_1_0_0::b2ReturnValueType();
		dvpLibB1_2_0_0::b1UseValueType(foo2);
	}

	void workWithComplexType()
	{
		auto foo1 = dvpLibB1_2_0_0::b1ReturnComplexType();
		dvpLibB2_1_0_0::b2UseComplexType(foo1);

		auto foo2 = dvpLibB2_1_0_0::b2ReturnComplexType();
		dvpLibB1_2_0_0::b1UseComplexType(foo2);

		auto foo3 = dvpLibB1_2_0_0::b1CreateComplexType();
		dvpLibB2_1_0_0::b2SetComplexType(std::move(foo3));

		auto foo4 = dvpLibB2_1_0_0::b2CreateComplexType();
		dvpLibB1_2_0_0::b1SetComplexType(std::move(foo4));

		auto foo5 = std::make_unique<dvpLibC_1_0_0::ComplexType>();
		dvpLibB2_1_0_0::b2UseComplexType(foo5.get());
		dvpLibB1_2_0_0::b1UseComplexType(foo5.get());
	}

}
