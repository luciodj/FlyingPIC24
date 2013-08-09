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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../lib/AudioPWM.c ../../lib/EX16.c ../../lib/SDMMC.c Wave.c WaveTest.c ../../lib/fileio.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1445267685/AudioPWM.o ${OBJECTDIR}/_ext/1445267685/EX16.o ${OBJECTDIR}/_ext/1445267685/SDMMC.o ${OBJECTDIR}/Wave.o ${OBJECTDIR}/WaveTest.o ${OBJECTDIR}/_ext/1445267685/fileio.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d ${OBJECTDIR}/_ext/1445267685/EX16.o.d ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d ${OBJECTDIR}/Wave.o.d ${OBJECTDIR}/WaveTest.o.d ${OBJECTDIR}/_ext/1445267685/fileio.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1445267685/AudioPWM.o ${OBJECTDIR}/_ext/1445267685/EX16.o ${OBJECTDIR}/_ext/1445267685/SDMMC.o ${OBJECTDIR}/Wave.o ${OBJECTDIR}/WaveTest.o ${OBJECTDIR}/_ext/1445267685/fileio.o

# Source Files
SOURCEFILES=../../lib/AudioPWM.c ../../lib/EX16.c ../../lib/SDMMC.c Wave.c WaveTest.c ../../lib/fileio.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA010
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA010.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1445267685/AudioPWM.o: ../../lib/AudioPWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/AudioPWM.c  -o ${OBJECTDIR}/_ext/1445267685/AudioPWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445267685/EX16.o: ../../lib/EX16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/EX16.c  -o ${OBJECTDIR}/_ext/1445267685/EX16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445267685/EX16.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/EX16.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445267685/SDMMC.o: ../../lib/SDMMC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/SDMMC.c  -o ${OBJECTDIR}/_ext/1445267685/SDMMC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445267685/SDMMC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/SDMMC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Wave.o: Wave.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Wave.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Wave.c  -o ${OBJECTDIR}/Wave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Wave.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Wave.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/WaveTest.o: WaveTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/WaveTest.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WaveTest.c  -o ${OBJECTDIR}/WaveTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/WaveTest.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/WaveTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445267685/fileio.o: ../../lib/fileio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/fileio.c  -o ${OBJECTDIR}/_ext/1445267685/fileio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445267685/fileio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/fileio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1445267685/AudioPWM.o: ../../lib/AudioPWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/AudioPWM.c  -o ${OBJECTDIR}/_ext/1445267685/AudioPWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d"      -g -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445267685/EX16.o: ../../lib/EX16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/EX16.c  -o ${OBJECTDIR}/_ext/1445267685/EX16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445267685/EX16.o.d"      -g -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/EX16.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445267685/SDMMC.o: ../../lib/SDMMC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/SDMMC.c  -o ${OBJECTDIR}/_ext/1445267685/SDMMC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445267685/SDMMC.o.d"      -g -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/SDMMC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Wave.o: Wave.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Wave.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Wave.c  -o ${OBJECTDIR}/Wave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Wave.o.d"      -g -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Wave.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/WaveTest.o: WaveTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/WaveTest.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WaveTest.c  -o ${OBJECTDIR}/WaveTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/WaveTest.o.d"      -g -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/WaveTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1445267685/fileio.o: ../../lib/fileio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/fileio.c  -o ${OBJECTDIR}/_ext/1445267685/fileio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1445267685/fileio.o.d"      -g -omf=elf -fno-short-double -O1 -I"../../include" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/fileio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--heap=2000,--no-check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--defsym,__ICD2RAM=1,--library-path="../../../../Program Files/Microchip/MPLAB C30/lib",--no-force-link,--smart-io,-Map="$(TARGETBASE).map"$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=2000,--no-check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--defsym,__ICD2RAM=1,--library-path="../../../../Program Files/Microchip/MPLAB C30/lib",--no-force-link,--smart-io,-Map="$(TARGETBASE).map"$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
