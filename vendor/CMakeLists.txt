cmake_minimum_required(VERSION 3.16)

macro(AddExternalProject MACRO_PROJECT_NAME VERSION GIT_REPOSITORY GIT_TAG)

find_package(${MACRO_PROJECT_NAME} ${VERSION} QUIET)

if (NOT ${MACRO_PROJECT_NAME}_FOUND)
    FetchContent_Declare(
            ${MACRO_PROJECT_NAME}
            GIT_REPOSITORY ${GIT_REPOSITORY}
            GIT_TAG        ${GIT_TAG}
    )

    FetchContent_MakeAvailable(${MACRO_PROJECT_NAME})
endif()

endmacro()

include(FetchContent)
# AddExternalProject(spdlog 1.11.0 https://github.com/gabime/spdlog v1.11.0)
AddExternalProject(fmt 9.1.0 https://github.com/fmtlib/fmt 9.1.0)
