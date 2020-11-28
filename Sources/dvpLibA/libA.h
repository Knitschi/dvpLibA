#pragma once

#define dvpLibAVer dvpLibA
#include CPF_VERSIONED_INCLUDE(dvpLibAVer, dvpLibA_export.h)

namespace dvpLibA
{
	DVPLIBA_EXPORT void workWithValueType();
	DVPLIBA_EXPORT void workWithComplexType();
}
