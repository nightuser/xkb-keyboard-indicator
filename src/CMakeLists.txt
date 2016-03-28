set(xki_VERSION_MAJOR 0)
set(xki_VERSION_MINOR 1)

set(XKI_SRCS
  about.c
  about.h
  global.h
  indicator.c
  indicator.h
  main.c
  settings.c
  settings.h
  "${PROJECT_BINARY_DIR}/src/resources.c"
  )

configure_file(
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/src/config.h"
  )

include_directories("${PROJECT_BINARY_DIR}/src/")

find_package(GTK3 REQUIRED)
include_directories(${GTK3_INCLUDE_DIRS})

find_package(GLIB REQUIRED)
include_directories(${GLIB_INCLUDE_DIRS})

find_package(APPINDICATOR REQUIRED)
include_directories(${APPINDICATOR_INCLUDE_DIRS})

find_package(LibXKlavier REQUIRED)
include_directories(${LIBXKLAVIER_INCLUDE_DIRS})

add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/src/resources.c"
  COMMAND glib-compile-resources --target="${PROJECT_BINARY_DIR}/src/resources.c" --sourcedir="${PROJECT_SOURCE_DIR}/data" --generate-source --c-name ${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/data/xki.gresource.xml"
  COMMENT "Compiling resources"
  MAIN_DEPENDENCY "${CMAKE_SOURCE_DIR}/data/xki.gresource.xml"
  )
set_source_files_properties("${PROJECT_BINARY_DIR}/src/resources.c" PROPERTIES
  GENERATED TRUE
  )

add_executable(${PROJECT_NAME} ${XKI_SRCS} )
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${GLIB_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${APPINDICATOR_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${LIBXKLAVIER_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  )
install(FILES "${CMAKE_SOURCE_DIR}/data/xki.gschema.xml"
  DESTINATION share/glib-2.0/schemas
  )
install(
  CODE
  "
  execute_process(
    COMMAND glib-compile-schemas \"${CMAKE_INSTALL_PREFIX}/share/glib-2.0/schemas\"
  )
  "
  )
