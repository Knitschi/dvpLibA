# Root CMakeLists file for the ACPFTestProject
include("CPFCMake/cpfInitCIProject.cmake")

cmake_minimum_required(VERSION ${CPF_MINIMUM_CMAKE_VERSION}) 

#-----------------------------------------------------
function( getIncludeFileCompileOptions optionsOut )
	
	cpfGetCompiler(compiler)
	if((${compiler} STREQUAL Gcc) OR (${compiler} STREQUAL Clang))
		set( options "-include$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/${versionPrefixHeader}>" )
	elseif( (${compiler} STREQUAL Vc) AND (${CMAKE_GENERATOR} MATCHES "^Visual Studio.*$") )
		set( options "/FI$<BUILD_INTERFACE:\"${CMAKE_SOURCE_DIR}/${versionPrefixHeader}\">" )
	elseif( (${compiler} STREQUAL Vc) ) # With Ninja the quotes are not dereferenced.
		set( options "/FI$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/${versionPrefixHeader}>" )
	else()
		message (FATAL_ERROR "Compiler ${compiler} is not supported by function getIncludeFileCompileOptions().")
	endif()
	set(${optionsOut} ${options} PARENT_SCOPE)

endfunction()


function( cpfSetupInCodeVersionMechanism )

	# Setup the library name macro for the internal includes.
	cpfSplitVersion( major minor patch commitId ${PROJECT_VERSION})
    set(versionPostfix "_${major}_${minor}_${patch}" )
	string(REPLACE "${versionPostfix}" "" unversionedPackageName ${PROJECT_NAME})

	target_compile_definitions(${PROJECT_NAME} PRIVATE ${unversionedPackageName}_self=${PROJECT_NAME})

	# Setup the force include of the VersionPrefix.h header.
	getIncludeFileCompileOptions(includeOption)
	target_compile_options(${PROJECT_NAME} PRIVATE ${includeOption})

endfunction()

set(versionPrefixHeader "VersionPrefix.h")



project(dvpLibA)

cpfAddPackages(GLOBAL_FILES "${CPF_ROOT_DIR}/${CPF_CLANG_FORMAT_STYLE_FILE}" "${CMAKE_SOURCE_DIR}/${versionPrefixHeader}")

