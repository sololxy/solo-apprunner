set(TARGET_NAME "SoAppRunner.Desktop")

add_definitions("-DBUILDING_APPRUNNER_DESKTOP_API")

set(INCS    "${CMAKE_SOURCE_DIR}/include/${TARGET_NAME}/SoAppManagerWidget.h"
            "${CMAKE_SOURCE_DIR}/include/${TARGET_NAME}/SoProgramGroupWidget.h"
            "${CMAKE_SOURCE_DIR}/include/${TARGET_NAME}/SoProgramWidget.h"
            "${CMAKE_SOURCE_DIR}/include/${TARGET_NAME}/SoAppRunnerDesktopExport.h"
)

set(SRCS    "SoAppManagerWidget.cpp"
            "SoProgramGroupWidget.cpp"
            "SoProgramWidget.cpp"
)


add_library(${TARGET_NAME} SHARED  ${INCS} ${SRCS})
target_link_libraries(${TARGET_NAME} "SoAppRunner")
target_link_libraries(${TARGET_NAME} Qt5::Core)
target_link_libraries(${TARGET_NAME} Qt5::Widgets)
