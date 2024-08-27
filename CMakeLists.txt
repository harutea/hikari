cmake_minimum_required(VERSION 3.14)

project(hikari)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/hikari/*.cpp
)

file(GLOB_RECURSE SHADER_FILES CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/hikari/*.vert
     ${CMAKE_SOURCE_DIR}/hikari/*.frag
)

file(GLOB_RECURSE RESOURCE_FILES CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/hikari/*.png
     ${CMAKE_SOURCE_DIR}/hikari/*.jpg
)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${SHADER_FILES} ${RESOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

# glfw 
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# glad
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

# glm
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)


# copy shader files
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Release/shaders)
foreach(SHADER ${SHADER_FILES})
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${SHADER}
                     $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders/)
endforeach()

# copy resource files
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Release/resources)
foreach(RESOURCE ${RESOURCE_FILES})
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${RESOURCE}
                     $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/)
endforeach()