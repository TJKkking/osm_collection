set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 17)

# Clang target triple.
SET(triple bpf)

# Set clang as a compiler.
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_TARGET ${triple})

# Flags used in src folder. For samples folder, the flags are hardcoded.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -target bpf -Qunused-arguments")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_ISYSTEM_DIRS} ${SANITIZE_OPTIONS} -ggdb -fno-omit-frame-pointer -fPIC -Qunused-arguments" )

set(CMAKE_OBJCOPY llvm-objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_SIZE_UTIL llvm-size CACHE INTERNAL "size tool")