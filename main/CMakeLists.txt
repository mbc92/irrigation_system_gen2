set(SOURCES main.cpp)
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS "." "../MCAL"
                    REQUIRES MCAL)


target_compile_definitions(${COMPONENT_LIB} PRIVATE BOARD_NAME="${BOARD}")