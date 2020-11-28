
include(cpfInitPackageProject)
include(cpfAddCppPackage)

set(versionRequirements
	TARGET dvpLibC 1.0.0
	TARGET dvpLibB1 1.0.0
	TARGET dvpLibB2 1.0.0
)

#checkVersionRequirements("${versionRequirements}")

cpfInitPackageProject()

set( briefDescription "A helper package that I use for experiments related to the dependency versioning problem." )
set( longDescription "" )


set( PACKAGE_PUBLIC_HEADER
	libA.h
) 

set( PACKAGE_PRODUCTION_FILES
	libA.cpp
	VersionUtilities.cmake
)

set(dvpLibC_from_dvpLibB1 dvpLibC_2_0_0)
set(dvpLibC_from_dvpLibB2 dvpLibC_1_1_0)
set(dvpLibB1_direct dvpLibB1_2_0_0)
set(dvpLibB2_direct dvpLibB2_1_0_0)

############################################## Add Package #################################
cpfAddCppPackage( 
	TYPE					LIB
	OWNER 					Knitschi
	BRIEF_DESCRIPTION		${briefDescription}
	LONG_DESCRIPTION		${longDescription}
	PACKAGE_NAMESPACE		${PROJECT_NAME}
	PUBLIC_HEADER			${PACKAGE_PUBLIC_HEADER}
	PRODUCTION_FILES		${PACKAGE_PRODUCTION_FILES}
	LINKED_LIBRARIES		${dvpLibC_from_dvpLibB1} ${dvpLibC_from_dvpLibB2} ${dvpLibB1_direct} ${dvpLibB2_direct}
)

cpfSetupInCodeVersionMechanism()
