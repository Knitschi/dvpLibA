# Root CMakeLists file for the ACPFTestProject
include("CPFCMake/cpfInitCIProject.cmake")

cmake_minimum_required(VERSION ${CPF_MINIMUM_CMAKE_VERSION}) 

project(dvpLibA)

cpfAddPackages(GLOBAL_FILES "${CPF_ROOT_DIR}/${CPF_CLANG_FORMAT_STYLE_FILE}")

