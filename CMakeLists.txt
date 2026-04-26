cmake_minimum_required(VERSION 3.10.0)
project(cpp-mastery VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# Tell CMake to look for headers inside the current folders
include_directories(ch16_vectors)
include_directories(ch17_arrays)

# ---------------------------------------------------------
# Build the Executables (Target Name -> Files needed)
# ---------------------------------------------------------
add_executable(ch16_q3-4  ch16_vectors/quiz_q3-4_minmax.cpp)
add_executable(ch16_q5  ch16_vectors/quiz_q5_hangman.cpp)
add_executable(ch17_6_quiz ch17_arrays/ch17_6_quiz.cpp)
add_executable(ch17_cstyle_arrs ch17_arrays/ch17_cstyle_arrs.cpp)
