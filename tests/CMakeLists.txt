cmake_minimum_required(VERSION 3.17)
project(bcg_library_test)

link_directories(${CMAKE_BINARY_DIR})

set(TEST_SOURCES
        bcg_template_test.cpp
        bcg_test_dynamic_bitset.cpp
        bcg_test_file.cpp
        bcg_test_file_watcher.cpp
        bcg_test_stl_utils.cpp
        bcg_test_string_utils.cpp
        bcg_glm_vector_test.cpp
        bcg_test_property.cpp
        bcg_test_point_cloud.cpp
        bcg_test_point_cloudio.cpp
        bcg_test_graph.cpp
        bcg_test_mesh.cpp
        bcg_test_meshio.cpp
        bcg_test_triangle.cpp
        bcg_test_sphere.cpp
        bcg_test_polynomial.cpp
        bcg_test_monomial_basis.cpp
        bcg_test_bernstein_basis.cpp
        )

add_executable(bcg_library_test ${TEST_SOURCES})
set_target_properties(bcg_library_test PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)
target_link_libraries(bcg_library_test gtest gtest_main bcg_graphics bcg_opengl)