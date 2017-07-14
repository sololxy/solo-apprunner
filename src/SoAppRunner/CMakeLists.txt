set(TARGET_NAME "SoAppRunner")

add_definitions("-DBUILDING_APPRUNNER_API")

set(INCS    "${CMAKE_SOURCE_DIR}/include/${TARGET_NAME}/SoProgram.h"
            "${CMAKE_SOURCE_DIR}/include/${TARGET_NAME}/SoProgramGroup.h"
            "${CMAKE_SOURCE_DIR}/include/${TARGET_NAME}/SoAppManager.h"
            "${CMAKE_SOURCE_DIR}/include/${TARGET_NAME}/SoAppRunnerExport.h"
)

set(SRCS    "SoProgram.cpp"
            "SoProgramGroup.cpp"
            "SoAppManager.cpp"
)


add_library(${TARGET_NAME} SHARED  ${INCS} ${SRCS})
target_link_libraries(${TARGET_NAME} Qt5::Core)
target_link_libraries(${TARGET_NAME} Qt5::Xml)
