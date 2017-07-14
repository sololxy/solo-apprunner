set(TARGET_NAME "soapprunner")


add_definitions("-DBUILDING_APPRUNNER_API")

set(INCS    "${CMAKE_SOURCE_DIR}/include/SoProgram.h"
            "${CMAKE_SOURCE_DIR}/include/SoProgramGroup.h"
            "${CMAKE_SOURCE_DIR}/include/SoAppManager.h"
            "${CMAKE_SOURCE_DIR}/include/SoAppRunnerExport.h"
)

set(SRCS    "SoProgram.cpp"
            "SoProgramGroup.cpp"
            "SoAppManager.cpp"
)


add_library(${TARGET_NAME} SHARED  ${INCS} ${SRCS})
target_link_libraries(${TARGET_NAME} Qt5::Core)
target_link_libraries(${TARGET_NAME} Qt5::Widgets)
