#include <dvpLibA/libA.h>
#include <iostream>

#include <dvpLibB1_2_0_0/libB1.h>
#include <dvpLibB2_1_0_0/libB2.h>

namespace dvpLibA
{
	dvpLibC_1_1_0::ValueType to_1_1_0ValueType(dvpLibC_2_0_0::ValueType value)
	{
		dvpLibC_1_1_0::ValueType oldVersion;

		oldVersion.foo = value.foo;
		oldVersion.bar = value.bar;

		return oldVersion;
	}

	dvpLibC_2_0_0::ValueType to_2_0_0ValueType(dvpLibC_1_1_0::ValueType value)
	{
		dvpLibC_2_0_0::ValueType newVersion;

		newVersion.foo = value.foo;
		newVersion.bar = value.bar;

		return newVersion;
	}

	void workWithValueType()
	{
		auto foo1 = dvpLibB1_2_0_0::b1ReturnValueType();
		dvpLibB2_1_0_0::b2UseValueType(to_1_1_0ValueType(foo1));

		auto foo2 = dvpLibB2_1_0_0::b2ReturnValueType();
		dvpLibB1_2_0_0::b1UseValueType(to_2_0_0ValueType(foo2));
	}

	dvpLibC_1_1_0::ComplexType* to_1_1_0ComplexType(dvpLibC_2_0_0::ComplexType* ct)
	{
		return reinterpret_cast<dvpLibC_1_1_0::ComplexType*>(ct);
	}

	dvpLibC_2_0_0::ComplexType* to_2_0_0ComplexType(dvpLibC_1_1_0::ComplexType* ct)
	{
		return reinterpret_cast<dvpLibC_2_0_0::ComplexType*>(ct);
	}

	std::unique_ptr<dvpLibC_1_1_0::ComplexType> to_1_1_0UniqueComplexType(std::unique_ptr<dvpLibC_2_0_0::ComplexType> ct)
	{
		return std::unique_ptr<dvpLibC_1_1_0::ComplexType>(to_1_1_0ComplexType(ct.release()));
	}

	std::unique_ptr<dvpLibC_2_0_0::ComplexType> to_2_0_0UniqueComplexType(std::unique_ptr<dvpLibC_1_1_0::ComplexType> ct)
	{
		return std::unique_ptr<dvpLibC_2_0_0::ComplexType>(to_2_0_0ComplexType(ct.release()));
	}

	void workWithComplexType()
	{
		auto foo1 = dvpLibB1_2_0_0::b1ReturnComplexType();
		dvpLibB2_1_0_0::b2UseComplexType(to_1_1_0ComplexType(foo1));

		auto foo2 = dvpLibB2_1_0_0::b2ReturnComplexType();
		dvpLibB1_2_0_0::b1UseComplexType(to_2_0_0ComplexType(foo2));

		auto foo3 = dvpLibB1_2_0_0::b1CreateComplexType();
		dvpLibB2_1_0_0::b2SetComplexType(to_1_1_0UniqueComplexType(std::move(foo3)));

		auto foo4 = dvpLibB2_1_0_0::b2CreateComplexType();
		dvpLibB1_2_0_0::b1SetComplexType(to_2_0_0UniqueComplexType(std::move(foo4)));

		auto foo5 = std::make_unique<dvpLibC_1_1_0::ComplexType>();
		dvpLibB2_1_0_0::b2UseComplexType(foo5.get());
		dvpLibB1_2_0_0::b1UseComplexType(to_2_0_0ComplexType(foo5.get()));
	}

}
