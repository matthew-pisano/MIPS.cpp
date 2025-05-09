cmake_minimum_required(VERSION 3.30)
project(masm)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(masm src/main.cpp
        src/fileio.cpp
        src/tokenizer.cpp
        src/parser.cpp
        src/register.cpp
        src/utils.cpp
        src/instruction.cpp
        src/memory.cpp
        src/interpreter.cpp
        src/syscalls.cpp
        src/labels.cpp
        src/directive.cpp
)

add_executable(masm-fg test/fixture_gen.cpp
        src/fileio.cpp
        src/tokenizer.cpp
        src/parser.cpp
        src/register.cpp
        src/utils.cpp
        src/instruction.cpp
        src/memory.cpp
        src/labels.cpp
        src/directive.cpp
)

include(FetchContent)
FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG main
)
FetchContent_MakeAvailable(cli11)
target_link_libraries(masm CLI11::CLI11)
target_link_libraries(masm-fg CLI11::CLI11)

find_package(Catch2 3 REQUIRED)
add_executable(masm-tests
        test/test_tokenizer.cpp
        test/test_utils.cpp
        src/tokenizer.cpp
        src/fileio.cpp
        src/parser.cpp
        src/utils.cpp
        src/register.cpp
        src/instruction.cpp
        src/memory.cpp
        test/test_parser.cpp
        src/interpreter.cpp
        src/syscalls.cpp
        test/test_interpreter.cpp
        src/labels.cpp
        src/directive.cpp
)
target_link_libraries(masm-tests PRIVATE Catch2::Catch2WithMain)
include(CTest)
include(Catch)
catch_discover_tests(masm-tests)