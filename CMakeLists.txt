cmake_minimum_required(VERSION 3.10.0)
project(cpp-mastery VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# Tell CMake to look for headers inside the current folders
include_directories(ch16_vectors)
include_directories(ch17_arrays)
include_directories(ch18_iterators_algs)


# ---------------------------------------------------------
# Build the Executables (Target Name -> Files needed)
# ---------------------------------------------------------
add_executable(ch16_q3-4  ch16_vectors/quiz_q3-4_minmax.cpp)
add_executable(ch16_q5  ch16_vectors/quiz_q5_hangman.cpp)

add_executable(ch17_6_quiz ch17_arrays/ch17_6_quiz.cpp)
add_executable(ch17_cstyle_arrs ch17_arrays/ch17_cstyle_arrs.cpp)
add_executable(ch17_string ch17_arrays/ch17_cstyle_string.cpp)
add_executable(ch17_multidimensions ch17_arrays/ch17_multidimensions.cpp)
add_executable(quiz_q2 ch17_arrays/quiz_q2.cpp)
add_executable(quiz_q3 ch17_arrays/quiz_q3.cpp ch17_arrays/deck.cpp)
add_executable(quiz_q4 ch17_arrays/quiz_q4.cpp ch17_arrays/deck.cpp)
add_executable(ch18_1 ch18_iterators_algs/basic_selection_sort.cpp)