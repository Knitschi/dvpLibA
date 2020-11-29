# Root CMakeLists file for the ACPFTestProject
include("CPFCMake/cpfInitCIProject.cmake")

cmake_minimum_required(VERSION ${CPF_MINIMUM_CMAKE_VERSION}) 

#-----------------------------------------------------
function( getIncludeFileCompileOptions optionsOut includedFile)
	
	cpfGetCompiler(compiler)
	if((${compiler} STREQUAL Gcc) OR (${compiler} STREQUAL Clang))
		set( options "-include$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/${includedFile}>" )
	elseif( (${compiler} STREQUAL Vc) AND (${CMAKE_GENERATOR} MATCHES "^Visual Studio.*$") )
		set( options "/FI$<BUILD_INTERFACE:\"${CMAKE_SOURCE_DIR}/${includedFile}\">" )
	elseif( (${compiler} STREQUAL Vc) ) # With Ninja the quotes are not dereferenced.
		set( options "/FI$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/${includedFile}>" )
	else()
		message (FATAL_ERROR "Compiler ${compiler} is not supported by function getIncludeFileCompileOptions().")
	endif()
	set(${optionsOut} ${options} PARENT_SCOPE)

endfunction()


function( cpfSetupInCodeVersionMechanism )

	get_property(binaryTargets TARGET ${PROJECT_NAME} PROPERTY INTERFACE_CPF_BINARY_SUBTARGETS)
	foreach(target ${binaryTargets})
		# Setup the force include of the VersionPrefix.h header.
		getIncludeFileCompileOptions(includeOption "VersionPrefix.h")
		target_compile_options(${target} PRIVATE ${includeOption})
	endforeach()

endfunction()


project(dvpLibA)

cpfAddPackages(GLOBAL_FILES "${CPF_ROOT_DIR}/${CPF_CLANG_FORMAT_STYLE_FILE}" "${CMAKE_SOURCE_DIR}/VersionPrefix.h")

