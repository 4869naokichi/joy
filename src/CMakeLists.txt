add_library(joy SHARED)
target_sources(joy PRIVATE joy.cpp)
target_include_directories(joy PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(joy speak xinput)

add_library(speak SHARED IMPORTED GLOBAL)
set_target_properties(speak
    PROPERTIES
        IMPORTED_LOCATION ${PROJECT_BINARY_DIR}/out/libspeak.dll
        IMPORTED_IMPLIB ${PROJECT_BINARY_DIR}/out/libspeak.dll.a
        INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/include)