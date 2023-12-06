# CMake toolchain file

# linker flags
#set(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,--strip-debug")

# cflags
set(CMAKE_CXX_FLAGS_INIT "-ansi -Wall")

# cflags for debug build
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -ggdb")

# cflags for release build
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3 -DNDEBUG -s")
