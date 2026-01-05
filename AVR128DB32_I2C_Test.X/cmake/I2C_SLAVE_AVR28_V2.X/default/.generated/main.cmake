# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(I2C_SLAVE_AVR28_V2_X_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(I2C_SLAVE_AVR28_V2_X_default_default_XC8_FILE_TYPE_assemble)
add_library(I2C_SLAVE_AVR28_V2_X_default_default_XC8_assemble OBJECT ${I2C_SLAVE_AVR28_V2_X_default_default_XC8_FILE_TYPE_assemble})
    I2C_SLAVE_AVR28_V2_X_default_default_XC8_assemble_rule(I2C_SLAVE_AVR28_V2_X_default_default_XC8_assemble)
    list(APPEND I2C_SLAVE_AVR28_V2_X_default_library_list "$<TARGET_OBJECTS:I2C_SLAVE_AVR28_V2_X_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(I2C_SLAVE_AVR28_V2_X_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(I2C_SLAVE_AVR28_V2_X_default_default_XC8_assemblePreprocess OBJECT ${I2C_SLAVE_AVR28_V2_X_default_default_XC8_FILE_TYPE_assemblePreprocess})
    I2C_SLAVE_AVR28_V2_X_default_default_XC8_assemblePreprocess_rule(I2C_SLAVE_AVR28_V2_X_default_default_XC8_assemblePreprocess)
    list(APPEND I2C_SLAVE_AVR28_V2_X_default_library_list "$<TARGET_OBJECTS:I2C_SLAVE_AVR28_V2_X_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(I2C_SLAVE_AVR28_V2_X_default_default_XC8_FILE_TYPE_compile)
add_library(I2C_SLAVE_AVR28_V2_X_default_default_XC8_compile OBJECT ${I2C_SLAVE_AVR28_V2_X_default_default_XC8_FILE_TYPE_compile})
    I2C_SLAVE_AVR28_V2_X_default_default_XC8_compile_rule(I2C_SLAVE_AVR28_V2_X_default_default_XC8_compile)
    list(APPEND I2C_SLAVE_AVR28_V2_X_default_library_list "$<TARGET_OBJECTS:I2C_SLAVE_AVR28_V2_X_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(I2C_SLAVE_AVR28_V2_X_default_image_jSHh7ocn ${I2C_SLAVE_AVR28_V2_X_default_library_list})

set_target_properties(I2C_SLAVE_AVR28_V2_X_default_image_jSHh7ocn PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${I2C_SLAVE_AVR28_V2_X_default_output_dir})
set_target_properties(I2C_SLAVE_AVR28_V2_X_default_image_jSHh7ocn PROPERTIES OUTPUT_NAME "default")
set_target_properties(I2C_SLAVE_AVR28_V2_X_default_image_jSHh7ocn PROPERTIES SUFFIX ".elf")

target_link_libraries(I2C_SLAVE_AVR28_V2_X_default_image_jSHh7ocn PRIVATE ${I2C_SLAVE_AVR28_V2_X_default_default_XC8_FILE_TYPE_link})


# Add the link options from the rule file.
I2C_SLAVE_AVR28_V2_X_default_link_rule(I2C_SLAVE_AVR28_V2_X_default_image_jSHh7ocn)



