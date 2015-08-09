set(xki_VERSION_MAJOR 0)
set(xki_VERSION_MINOR 1)

set (XKI_SRCS
  about.c
  about.h
  global.h
  indicator.c
  indicator.h
  main.c
  # resource.c
  settings.c
  settings.h
  )

configure_file(
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/src/config.h"
  )

include_directories("${PROJECT_BINARY_DIR}/src/")

add_executable(${PROJECT_NAME} ${XKI_SRCS})

find_package(GTK3 REQUIRED)
include_directories(${GTK3_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})

find_package(GLIB REQUIRED)
include_directories(${GLIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLIB_LIBRARIES})

find_package(APPINDICATOR REQUIRED)
include_directories(${APPINDICATOR_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${APPINDICATOR_LIBRARIES})

find_package(LibXKlavier REQUIRED)
include_directories(${LIBXKLAVIER_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${LIBXKLAVIER_LIBRARIES})
