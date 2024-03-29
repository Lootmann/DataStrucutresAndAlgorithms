cmake_minimum_required(VERSION 3.12)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test_out
  ./test_array.cc
  ./test_base64encoding.cc
  ./test_binary_search_tree.cc
  ./test_class_test.cc
  ./test_deq.cc
  ./test_linked_list.cc
  ./test_minstack.cc
  ./test_doubly_linked_list.cc
  ./test_graph.cc
  ./test_grid_graph.cc
  ./test_heap.cc
  ./test_queue.cc
  ./test_ring_buffer_queue.cc
  ./test_run_length_encoding.cc
  ./test_searching.cc
  ./test_sorting.cc
  ./test_stack.cc
  ./test_templates.cc
  ./test_tree.cc
  )

target_link_libraries(
  test_out
  Lib
  GTest::GTest
  GTest::Main
  )

include_directories(Lib
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
  ${GTEST_INCLUDE_DIRS}
  )

gtest_discover_tests(test_out)
