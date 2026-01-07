# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(AVR128DB32_I2C_Test_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemble)
add_library(AVR128DB32_I2C_Test_default_default_XC8_assemble OBJECT ${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemble})
    AVR128DB32_I2C_Test_default_default_XC8_assemble_rule(AVR128DB32_I2C_Test_default_default_XC8_assemble)
    list(APPEND AVR128DB32_I2C_Test_default_library_list "$<TARGET_OBJECTS:AVR128DB32_I2C_Test_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(AVR128DB32_I2C_Test_default_default_XC8_assemblePreprocess OBJECT ${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemblePreprocess})
    AVR128DB32_I2C_Test_default_default_XC8_assemblePreprocess_rule(AVR128DB32_I2C_Test_default_default_XC8_assemblePreprocess)
    list(APPEND AVR128DB32_I2C_Test_default_library_list "$<TARGET_OBJECTS:AVR128DB32_I2C_Test_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_compile)
add_library(AVR128DB32_I2C_Test_default_default_XC8_compile OBJECT ${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_compile})
    AVR128DB32_I2C_Test_default_default_XC8_compile_rule(AVR128DB32_I2C_Test_default_default_XC8_compile)
    list(APPEND AVR128DB32_I2C_Test_default_library_list "$<TARGET_OBJECTS:AVR128DB32_I2C_Test_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(AVR128DB32_I2C_Test_default_image_U_SYEx1A ${AVR128DB32_I2C_Test_default_library_list})

set_target_properties(AVR128DB32_I2C_Test_default_image_U_SYEx1A PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${AVR128DB32_I2C_Test_default_output_dir})
set_target_properties(AVR128DB32_I2C_Test_default_image_U_SYEx1A PROPERTIES OUTPUT_NAME "default")
set_target_properties(AVR128DB32_I2C_Test_default_image_U_SYEx1A PROPERTIES SUFFIX ".elf")

target_link_libraries(AVR128DB32_I2C_Test_default_image_U_SYEx1A PRIVATE ${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_link})


# Add the link options from the rule file.
AVR128DB32_I2C_Test_default_link_rule(AVR128DB32_I2C_Test_default_image_U_SYEx1A)



