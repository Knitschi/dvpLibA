
include(cpfInitPackageProject)
include(cpfAddCppPackage)

#[[
set(versionRequirements
	TARGET dvpLibC 1.0.0
	TARGET dvpLibB1 1.0.0
	TARGET dvpLibB2 1.0.0
)
]]

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
	main.cpp
)

cpfGetUnversionedPackageName(isVersionedName unversionedName versionPostfix ${PROJECT_NAME})

############################################## Add Package #################################
cpfAddCppPackage( 
	TYPE					CONSOLE_APP
	OWNER 					Knitschi
	BRIEF_DESCRIPTION		${briefDescription}
	LONG_DESCRIPTION		${longDescription}
	PACKAGE_NAMESPACE		${unversionedName}
	PUBLIC_HEADER			${PACKAGE_PUBLIC_HEADER}
	PRODUCTION_FILES		${PACKAGE_PRODUCTION_FILES}
	LINKED_LIBRARIES		
		PUBLIC				dvpLibB1_2_0_0 dvpLibB2_1_0_0
		PRIVATE				dvpLibD_1_0_0
)

cpfSetupInCodeVersionMechanism()
