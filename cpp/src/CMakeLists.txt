cmake_minimum_required(VERSION 3.12)

add_library(Lib
  STATIC
  ./array.cc
  ./base64encoding.cc
  ./class_test.cc
  ./deq.cc
  ./doubly_linked_list_node.cc
  ./graph.cc
  ./heap.cc
  ./linked_list.cc
  ./queue.cc
  ./queue_ring_buffer.cc
  ./run_length_encoding.cc
  ./searching.cc
  ./sorting.cc
  ./stack.cc
  ./templates.cc
  ./tree.cc
  )

target_include_directories(Lib
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  )
