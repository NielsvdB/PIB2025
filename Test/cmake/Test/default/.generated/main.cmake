# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Test_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Test_default_default_XC8_FILE_TYPE_assemble)
add_library(Test_default_default_XC8_assemble OBJECT ${Test_default_default_XC8_FILE_TYPE_assemble})
    Test_default_default_XC8_assemble_rule(Test_default_default_XC8_assemble)
    list(APPEND Test_default_library_list "$<TARGET_OBJECTS:Test_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(Test_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Test_default_default_XC8_assemblePreprocess OBJECT ${Test_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Test_default_default_XC8_assemblePreprocess_rule(Test_default_default_XC8_assemblePreprocess)
    list(APPEND Test_default_library_list "$<TARGET_OBJECTS:Test_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(Test_default_default_XC8_FILE_TYPE_compile)
add_library(Test_default_default_XC8_compile OBJECT ${Test_default_default_XC8_FILE_TYPE_compile})
    Test_default_default_XC8_compile_rule(Test_default_default_XC8_compile)
    list(APPEND Test_default_library_list "$<TARGET_OBJECTS:Test_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(Test_default_image_hY7rwMBo ${Test_default_library_list})

set_target_properties(Test_default_image_hY7rwMBo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${Test_default_output_dir})
set_target_properties(Test_default_image_hY7rwMBo PROPERTIES OUTPUT_NAME "default")
set_target_properties(Test_default_image_hY7rwMBo PROPERTIES SUFFIX ".elf")

target_link_libraries(Test_default_image_hY7rwMBo PRIVATE ${Test_default_default_XC8_FILE_TYPE_link})


# Add the link options from the rule file.
Test_default_link_rule(Test_default_image_hY7rwMBo)



