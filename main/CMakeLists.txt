set(SOURCES main.cpp)
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS "." "../MCAL" "../components"
                    REQUIRES MCAL wifiService)


target_compile_definitions(${COMPONENT_LIB} PUBLIC BOARD_NAME="${BOARD}")