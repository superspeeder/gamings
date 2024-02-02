cmake_minimum_required(VERSION 3.26)

find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(Vulkan REQUIRED)

file(GLOB_RECURSE KATENGINE_SOURCES CONFIGURE_DEPENDS src/*.c src/*.cc src/*.cxx src/*.cpp src/*.h src/*.hh src/*.hxx src/*.hpp)

add_library(katengine ${KATENGINE_SOURCES})
target_include_directories(katengine PUBLIC src/ ${Stb_INCLUDE_DIR})
target_link_libraries(katengine PUBLIC glm::glm glfw spdlog::spdlog Vulkan::Vulkan)

target_compile_features(katengine PUBLIC cxx_std_23)

add_library(katengine::katengine ALIAS katengine)
