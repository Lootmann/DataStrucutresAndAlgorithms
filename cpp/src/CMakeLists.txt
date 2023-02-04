cmake_minimum_required(VERSION 3.12)

add_library(Lib
  STATIC
  ./base64encoding.cc
  ./deq.cc
  ./doubly_linked_list_node.cc
  ./linked_list.cc
  ./queue.cc
  ./stack.cc
  )

target_include_directories(Lib
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  )
