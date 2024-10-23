cmake_minimum_required(VERSION 3.10)

# Set the project name and C++ standard
project(glut_particles)

# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable with all source files
add_executable(glut_particles 
    src/main2.cpp 
    src/DeltaTime/DeltaTimeManager.cpp 
    src/GlutInit/GlutInit.cpp
    src/Particle/Particle.cpp
    src/Particle/ThreeComponentVector.cpp
    src/SceneBuilder/SceneBuilder.cpp
)

# Link the GL libraries to your executable
target_link_libraries(glut_particles 
    PRIVATE 
    GL
    GLU
    glut
)
