cmake_minimum_required(VERSION 3.10)

# Set the project name and C++ standard
project(glut_demo)

# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable with all source files
add_executable(glut_demo 
    #src/GridMain.cpp 
    src/ParticleMain.cpp
    src/DeltaTime/DeltaTimeManager.cpp 
    src/GlutInit/GlutInit.cpp
    src/SceneComponent/Particle.cpp
    src/SceneComponent/ThreeComponentVector.cpp
    src/SceneBuilder/ParticleSceneBuilder.cpp
    src/SceneBuilder/GridSceneBuilder.cpp
)

# Link the GL libraries to your executable
target_link_libraries(glut_demo 
    PRIVATE 
    GL
    GLU
    glut
)
