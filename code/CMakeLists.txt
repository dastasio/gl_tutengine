if (SYSWINDOWS)
	link_directories ("${PROJECT_SOURCE_DIR}/win/SDL2/lib")
endif()

add_executable (${EXEC_NAME} "MainComponent.cpp")
add_library (glad STATIC ${GLAD_SOURCE} ${GLAD_INCLUDE_DIR}/glad/glad.h ${GLAD_INCLUDE_DIR}/KHR/khrplatform.h)
add_library (gl_tutengine STATIC
	Window.cpp Time.cpp Game.cpp Input.cpp
	Window.h   Time.h   Game.h   Input.h
	oglin.h)

target_link_libraries (${EXEC_NAME} gl_tutengine)
target_link_libraries (gl_tutengine glad ${OPENGL_LIBRARIES} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} opengl32)
include_directories (${PROJECT_SOURCE_DIR}/code ${OPENGL_INCLUDE_DIR} ${SDL2_INCLUDE_DIR} ${GLAD_INCLUDE_DIR})


# c++ version
target_compile_features( ${EXEC_NAME} PRIVATE cxx_nullptr)
target_compile_features( gl_tutengine PRIVATE cxx_nullptr)