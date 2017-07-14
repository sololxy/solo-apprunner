set(TARGET_NAME "soapprunner")


set(INCS    "${CMAKE_SOURCE_DIR}/include/SoProgram.h"
            "${CMAKE_SOURCE_DIR}/include/SoProgramGroup.h"
            "${CMAKE_SOURCE_DIR}/include/SoAppManager.h"
)

set(SRCS    "SoProgram.cpp"
            "SoProgramGroup.cpp"
            "SoAppManager.cpp"
)


add_library(${TARGET_NAME} ${INCS} ${SRCS})
