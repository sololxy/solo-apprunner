set(TARGET_NAME "apprunner")

set(SRCS    "apprunner.cpp"
)


add_executable(${TARGET_NAME} ${SRCS})
target_link_libraries(${TARGET_NAME} "soapprunner")
target_link_libraries(${TARGET_NAME} Qt5::Widgets)
