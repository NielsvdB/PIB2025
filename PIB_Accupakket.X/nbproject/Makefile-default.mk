#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=null
FINAL_IMAGE=${DISTDIR}/PIB_Accupakket.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=null
FINAL_IMAGE=${DISTDIR}/PIB_Accupakket.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/i2c_client/src/twi0.c mcc_generated_files/i2c_host/src/twi1.c mcc_generated_files/system/src/pins.c mcc_generated_files/system/src/system.c mcc_generated_files/system/src/protected_io.S mcc_generated_files/system/src/clock.c mcc_generated_files/system/src/config_bits.c mcc_generated_files/system/src/interrupt.c mcc_generated_files/timer/src/tca0.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.${OUTPUT_EXTENSION_S} ${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/main.${OUTPUT_EXTENSION_C}
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C}.d ${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C}.d ${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C}.d ${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C}.d ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.${OUTPUT_EXTENSION_S}.d ${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C}.d ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C}.d ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C}.d ${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C}.d ${OBJECTDIR}/main.${OUTPUT_EXTENSION_C}.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.${OUTPUT_EXTENSION_S} ${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C} ${OBJECTDIR}/main.${OUTPUT_EXTENSION_C}

# Source Files
SOURCEFILES=mcc_generated_files/i2c_client/src/twi0.c mcc_generated_files/i2c_host/src/twi1.c mcc_generated_files/system/src/pins.c mcc_generated_files/system/src/system.c mcc_generated_files/system/src/protected_io.S mcc_generated_files/system/src/clock.c mcc_generated_files/system/src/config_bits.c mcc_generated_files/system/src/interrupt.c mcc_generated_files/timer/src/tca0.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIB_Accupakket.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C}: mcc_generated_files/i2c_client/src/twi0.c  .generated_files/flags/default/d4c5264dc03e2dbd83bb24e473be8364547c4551 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/i2c_client/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/i2c_client/src/twi0.c 
	
${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C}: mcc_generated_files/i2c_host/src/twi1.c  .generated_files/flags/default/9359f069690894adbc9d53fee6bb0d3376a547ef .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/i2c_host/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/i2c_host/src/twi1.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/pins.c  .generated_files/flags/default/d335b4c5f11d9bbb44698acecd2accb27c07e861 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/pins.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/system.c  .generated_files/flags/default/17324ca12d6fa8c151d85ff580adb994a59b9cb9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/system.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/clock.c  .generated_files/flags/default/4257c0eda94ca4138f4b70a65c9c1d88a7d5a4f9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/clock.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/config_bits.c  .generated_files/flags/default/7c90c04211ec81310cf040f5170b9d5bbf530eda .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/config_bits.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/interrupt.c  .generated_files/flags/default/56d86085e66aa08d468879289b9b0c3430447e93 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/interrupt.c 
	
${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C}: mcc_generated_files/timer/src/tca0.c  .generated_files/flags/default/92676b79f550cc1e408eca46bdbb10a93c1cb2a4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/timer/src/tca0.c 
	
${OBJECTDIR}/main.${OUTPUT_EXTENSION_C}: main.c  .generated_files/flags/default/ac54fbe95a6f8d7251dec68948c9bd3a72dba55e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/main.${OUTPUT_EXTENSION_C} 
	 -D__DEBUG=1    -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    main.c 
	
else
${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C}: mcc_generated_files/i2c_client/src/twi0.c  .generated_files/flags/default/9b7e3fb924a2ba46d5d967f8a77ef6cefac70957 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/i2c_client/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c_client/src/twi0.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/i2c_client/src/twi0.c 
	
${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C}: mcc_generated_files/i2c_host/src/twi1.c  .generated_files/flags/default/e07debde7e68113f3a0260b225138970a7c77bb0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/i2c_host/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c_host/src/twi1.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/i2c_host/src/twi1.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/pins.c  .generated_files/flags/default/33b84ea8506049f2e7255be535adc5f96cd352ab .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/pins.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/system.c  .generated_files/flags/default/dfa886fd28073f22c8604cf9fe26b0371de970fd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/system.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/clock.c  .generated_files/flags/default/33f967226a83e609403027f776712c7bb467f4cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/clock.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/config_bits.c  .generated_files/flags/default/87a56bfffc284e813eed2eb761ede00fcd5d4baf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/config_bits.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C}: mcc_generated_files/system/src/interrupt.c  .generated_files/flags/default/f01ecdff2161cf5deed1e46bf31fd969569be1f7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/system/src/interrupt.c 
	
${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C}: mcc_generated_files/timer/src/tca0.c  .generated_files/flags/default/f7aeb9ec969d275ed726640e19b83b50db53826 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tca0.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    mcc_generated_files/timer/src/tca0.c 
	
${OBJECTDIR}/main.${OUTPUT_EXTENSION_C}: main.c  .generated_files/flags/default/79b64c637688b647d0b12263ae6e1c499c1335c1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.${OUTPUT_EXTENSION_C}.d 
	@${RM} ${OBJECTDIR}/main.${OUTPUT_EXTENSION_C} 
	   -fshort-double -fshort-float ${code-model-external.prefix}wordwrite ${optimization-options.prefix}+asm${optimization-options.separator}${optimization-assembler-files.false}${optimization-options.separator}-speed,+space${optimization-options.separator}${optimization-debug.false}${optimization-options.separator}${local-generation.false} ${what-to-do.prefix}ignore ${preprocess-assembler.trueemission} -N255 ${warn-level.prefix}-3 ${asmlist.true} -D=$(CND_CONF)  ${linker-report-options.prefix}-psect${linker-report-options.separator}-class${linker-report-options.separator}+mem${linker-report-options.separator}-hex${linker-report-options.separator}-file ${ld-extra.prefix}${ld-extra.false} ${linker-runtime-options.prefix}+clear${linker-runtime-options.separator}${initialize-data.true}${linker-runtime-options.separator}${keep-generated-startup.as.false}${linker-runtime-options.separator}${opt-xc8-linker-link_startup.false}${linker-runtime-options.separator}${calibrate-oscillator.false}${linker-runtime-options.separator}${backup-reset-condition-flags.false}${linker-runtime-options.separator}${format-hex-file-for-download.false}${linker-runtime-options.separator}${managed-stack.false}${linker-runtime-options.separator}${program-the-device-with-default-config-words.false}${linker-runtime-options.separator}-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs ${stack-options.prefix}compiled    main.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}
