# The following variables contains the files used by the different stages of the build process.
set(AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemblePreprocess "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/system/src/protected_io.S")
set_source_files_properties(${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libraries/src/I2C.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/adc/src/adc0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/evsys/src/evsys.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/i2c_client/src/twi0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/i2c_host/src/twi1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/nvm/src/nvm.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/power/src/power.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/reset/src/rstctrl.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/system/src/clock.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/system/src/config_bits.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/system/src/interrupt.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/system/src/pins.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/system/src/system.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/timer/src/rtc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/timer/src/tca0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/vref/src/vref.c")
set_source_files_properties(${AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(AVR128DB32_I2C_Test_default_default_XC8_FILE_TYPE_link)
set(AVR128DB32_I2C_Test_default_image_name "default.elf")
set(AVR128DB32_I2C_Test_default_image_base_name "default")

# The output directory of the final image.
set(AVR128DB32_I2C_Test_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/AVR128DB32_I2C_Test")

# The full path to the final image.
set(AVR128DB32_I2C_Test_default_full_path_to_image ${AVR128DB32_I2C_Test_default_output_dir}/${AVR128DB32_I2C_Test_default_image_name})
