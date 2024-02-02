cmake_minimum_required(VERSION 3.26)

file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS src/*.c src/*.cc src/*.cxx src/*.cpp src/*.h src/*.hh src/*.hxx src/*.hpp)

add_executable(game ${GAME_SOURCES})
target_include_directories(game PRIVATE src/)
target_link_libraries(game PRIVATE katengine::katengine)
target_compile_features(katengine PRIVATE cxx_std_23)
