cmake_minimum_required(VERSION 3.20)

project(TRTInferCore
    VERSION 0.1.0
    LANGUAGES CXX
)

# ============================================================
# C++ Standard
# ============================================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# ============================================================
# TensorRT
# ============================================================

set(TENSORRT_ROOT
    "D:/code/3rdparty/TensorRT8"
    CACHE PATH "TensorRT installation directory"
)

set(TENSORRT_INCLUDE_DIR
    "${TENSORRT_ROOT}/include"
)

set(TENSORRT_LIBRARY_DIR
    "${TENSORRT_ROOT}/lib"
)
# ============================================================
# CUDA
# ============================================================

set(CUDA_ROOT
    "$ENV{CUDA_PATH}"
    CACHE PATH "CUDA installation directory"
)

set(CUDA_INCLUDE_DIR
    "${CUDA_ROOT}/include"
)

set(CUDA_LIBRARY_DIR
    "${CUDA_ROOT}/lib/x64"
)

# ============================================================
# TRTInferCore
# ============================================================

add_library(TRTInferCore SHARED

    src/TRTLogger.cpp
)


# ============================================================
# Include directories
# ============================================================

target_include_directories(TRTInferCore
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
    PRIVATE
        "${CUDA_INCLUDE_DIR}"
        "${TENSORRT_INCLUDE_DIR}"
)


# ============================================================
# TensorRT libraries
# ============================================================

target_link_directories(TRTInferCore
    PRIVATE
        "${TENSORRT_LIBRARY_DIR}"
)

target_link_libraries(TRTInferCore
    PRIVATE
        nvinfer
)


# ============================================================
# Compiler Warning
# ============================================================

if(MSVC)

    target_compile_options(TRTInferCore
        PRIVATE
            /W4
            /permissive-
    )

else()

    target_compile_options(TRTInferCore
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )

endif()








