if (SYSWINDOWS)
	link_directories ("${PROJECT_SOURCE_DIR}/win/SDL2/lib")
endif()

add_executable (${EXEC_NAME} "MainComponent.cpp")
add_library (glad STATIC ${GLAD_SOURCE} ${GLAD_INCLUDE_DIR}/glad/glad.h ${GLAD_INCLUDE_DIR}/KHR/khrplatform.h)
add_library (gl_tutengine STATIC
	Vertex.cpp Mesh.cpp Window.cpp Time.cpp Game.cpp Input.cpp Shader.cpp Transform.cpp ResourceLoader.cpp RenderUtils.cpp CommonUtils.cpp
	Vertex.h   Mesh.h   Window.h   Time.h   Game.h   Input.h   Shader.h   Transform.h   ResourceLoader.h   RenderUtils.h   CommonUtils.h)
add_library (gl_math STATIC
	vec2.cpp vec3.cpp vec4.cpp mat4.cpp
	vec2.h   vec3.h   vec4.h   mat4.h
	oglin.h  vectors.h)

target_link_libraries (${EXEC_NAME} gl_tutengine gl_math)
target_link_libraries (gl_tutengine glad ${OPENGL_LIBRARIES} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} opengl32)
target_link_libraries (gl_math glad ${OPENGL_LIBRARIES} opengl32)
include_directories (${PROJECT_SOURCE_DIR}/code ${OPENGL_INCLUDE_DIR} ${SDL2_INCLUDE_DIR} ${GLAD_INCLUDE_DIR})


# c++ version
target_compile_features( ${EXEC_NAME} PRIVATE cxx_nullptr)
target_compile_features( gl_tutengine PRIVATE cxx_nullptr)
target_compile_features( gl_math PRIVATE cxx_nullptr)