cmake_minimum_required(VERSION 3.13)

project(binop VERSION 1.0 LANGUAGES C)

option(DISABLE_ASAN "Disable address sanitizer")

include(./coconut/coconut.cmake)

# Whenever you add a file, add it here too.
add_executable(binop
    src/main.c src/print/print.c
    src/equations/eq_binop.c  src/equations/eq_leaf.c  src/equations/eq_prog.c
)

target_compile_options(binop PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Wno-unused-function>
)

# Enable address sanitizer
if(NOT DISABLE_ASAN)
    target_compile_options(binop PRIVATE
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:$<$<CONFIG:Debug>:-fsanitize=address>>
    )

    target_link_options(binop PRIVATE
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:$<$<CONFIG:Debug>:-fsanitize=address>>
    )
endif()

coconut_target_generate(binop "${CMAKE_CURRENT_LIST_DIR}/src/main.ccn" dynamic)
target_include_directories(binop
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/src"
)

add_custom_target(dot
    dot -Tpng ccngen/ast.dot > ast.png
    COMMENT "Generate a png of your ast based on the generated dot diagram."
)
