set(TARGET_NAME "apprunner")

set(SRCS    "apprunner.cpp"
            "MainWindow.h"
            "MainWindow.cpp"
            "BannerWidget.cpp"
            "BannerWidget.h"
)


add_executable(${TARGET_NAME} ${SRCS})
target_link_libraries(${TARGET_NAME} "SoAppRunner")
target_link_libraries(${TARGET_NAME} "SoAppRunner.Desktop")
target_link_libraries(${TARGET_NAME} Qt5::Widgets)
