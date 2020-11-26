# Root CMakeLists file for the ACPFTestProject
include("CPFCMake/cpfInitCIProject.cmake")

cmake_minimum_required(VERSION ${CPF_MINIMUM_CMAKE_VERSION}) 

function( cpfGetInCodeVersion inCodeVersionOut version )

    string(REPLACE "." "_" inCodeVersion ${version})
    set(${inCodeVersionOut} ${inCodeVersion} PARENT_SCOPE)

endfunction()

project(dvpLibA)

cpfAddPackages(GLOBAL_FILES "${CPF_ROOT_DIR}/${CPF_CLANG_FORMAT_STYLE_FILE}")

