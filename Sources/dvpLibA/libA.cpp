#include <dvpLibA/libA.h>
#include <iostream>

#include <dvpLibB1/libB1.h>
#include <dvpLibB2/libB2.h>

namespace dvpLibA
{
	void workWithValueType()
	{
		auto foo1 = dvpLibB1::b1ReturnValueType();
		dvpLibB2::b2UseValueType(foo1);

		auto foo2 = dvpLibB2::b2ReturnValueType();
		dvpLibB1::b1UseValueType(foo2);
	}

	void workWithComplexType()
	{
		auto foo1 = dvpLibB1::b1ReturnComplexType();
		dvpLibB2::b2UseComplexType(foo1);

		auto foo2 = dvpLibB2::b2ReturnComplexType();
		dvpLibB1::b1UseComplexType(foo2);

		auto foo3 = dvpLibB1::b1CreateComplexType();
		dvpLibB2::b2SetComplexType(std::move(foo3));

		auto foo4 = dvpLibB2::b2CreateComplexType();
		dvpLibB1::b1SetComplexType(std::move(foo4));

		auto foo5 = std::make_unique<dvpLibC::ComplexType>();
		dvpLibB2::b2UseComplexType(foo5.get());
		dvpLibB1::b1UseComplexType(foo5.get());
	}

}
