set(EXTERNAL_SOURCES "")
set(EXTERNAL_HEADERS "")

set(root "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
set(IMGUI_SOURCES
"${root}/imgui.cpp"
"${root}/imgui_demo.cpp"
"${root}/imgui_widgets.cpp"
"${root}/imgui_draw.cpp")

list(APPEND EXTERNAL_SOURCES ${IMGUI_SOURCES})
list(APPEND EXTERNAL_HEADERS ${CMAKE_CURRENT_SOURCE_DIR})