#include <dvpLibA/libA.h>
#include <iostream>

#define dvpLibB1Ver dvpLibB1_2_0_0
#include CPF_VERSIONED_INCLUDE(dvpLibB1Ver, libB1.h)

#define dvpLibB2Ver dvpLibB2_1_0_0
#include CPF_VERSIONED_INCLUDE(dvpLibB2Ver, libB2.h)

#define dvpLibCVer_from_dvpLibB2 dvpLibC_1_1_0
#define dvpLibCVer_from_dvpLibB1 dvpLibC_2_0_0

namespace dvpLibA
{
	dvpLibCVer_from_dvpLibB2::ValueType to_1_1_0ValueType(dvpLibCVer_from_dvpLibB1::ValueType value)
	{
		dvpLibCVer_from_dvpLibB2::ValueType oldVersion;

		oldVersion.foo = value.foo;
		oldVersion.bar = value.bar;

		return oldVersion;
	}

	dvpLibCVer_from_dvpLibB1::ValueType to_2_0_0ValueType(dvpLibCVer_from_dvpLibB2::ValueType value)
	{
		dvpLibCVer_from_dvpLibB1::ValueType newVersion;

		newVersion.foo = value.foo;
		newVersion.bar = value.bar;

		return newVersion;
	}

	void workWithValueType()
	{
		auto foo1 = dvpLibB1Ver::b1ReturnValueType();
		dvpLibB2Ver::b2UseValueType(to_1_1_0ValueType(foo1));

		auto foo2 = dvpLibB2Ver::b2ReturnValueType();
		dvpLibB1Ver::b1UseValueType(to_2_0_0ValueType(foo2));
	}

	dvpLibCVer_from_dvpLibB2::ComplexType* to_1_1_0ComplexType(dvpLibCVer_from_dvpLibB1::ComplexType* ct)
	{
		return reinterpret_cast<dvpLibCVer_from_dvpLibB2::ComplexType*>(ct);
	}

	dvpLibCVer_from_dvpLibB1::ComplexType* to_2_0_0ComplexType(dvpLibCVer_from_dvpLibB2::ComplexType* ct)
	{
		return reinterpret_cast<dvpLibCVer_from_dvpLibB1::ComplexType*>(ct);
	}

	std::unique_ptr<dvpLibCVer_from_dvpLibB2::ComplexType> to_1_1_0UniqueComplexType(std::unique_ptr<dvpLibCVer_from_dvpLibB1::ComplexType> ct)
	{
		return std::unique_ptr<dvpLibCVer_from_dvpLibB2::ComplexType>(to_1_1_0ComplexType(ct.release()));
	}

	std::unique_ptr<dvpLibCVer_from_dvpLibB1::ComplexType> to_2_0_0UniqueComplexType(std::unique_ptr<dvpLibCVer_from_dvpLibB2::ComplexType> ct)
	{
		return std::unique_ptr<dvpLibCVer_from_dvpLibB1::ComplexType>(to_2_0_0ComplexType(ct.release()));
	}

	void workWithComplexType()
	{
		auto foo1 = dvpLibB1Ver::b1ReturnComplexType();
		dvpLibB2Ver::b2UseComplexType(to_1_1_0ComplexType(foo1));

		auto foo2 = dvpLibB2Ver::b2ReturnComplexType();
		dvpLibB1Ver::b1UseComplexType(to_2_0_0ComplexType(foo2));

		auto foo3 = dvpLibB1Ver::b1CreateComplexType();
		dvpLibB2Ver::b2SetComplexType(to_1_1_0UniqueComplexType(std::move(foo3)));

		auto foo4 = dvpLibB2Ver::b2CreateComplexType();
		dvpLibB1Ver::b1SetComplexType(to_2_0_0UniqueComplexType(std::move(foo4)));

		auto foo5 = std::make_unique<dvpLibCVer_from_dvpLibB2::ComplexType>();
		dvpLibB2Ver::b2UseComplexType(foo5.get());
		dvpLibB1Ver::b1UseComplexType(to_2_0_0ComplexType(foo5.get()));
	}

}
