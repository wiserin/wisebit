set(WISEBIT_BITARRAY_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/bitarray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/operators.cpp)


target_sources(WiseBit PRIVATE ${WISEBIT_BITARRAY_SRC})

add_subdirectory(methods)
