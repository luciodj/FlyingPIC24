#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile

# Environment
SHELL=cmd.exe
# Adding MPLAB X bin directory to path
PATH:=C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/:$(PATH)
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/14-FileIO.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/14-FileIO.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1445267685/CONU2.o ${OBJECTDIR}/_ext/1445267685/EX16.o ${OBJECTDIR}/ReadTest.o ${OBJECTDIR}/_ext/1445267685/SDMMC.o ${OBJECTDIR}/_ext/1445267685/fileio.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1445267685/CONU2.o.d ${OBJECTDIR}/_ext/1445267685/EX16.o.d ${OBJECTDIR}/ReadTest.o.d ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d ${OBJECTDIR}/_ext/1445267685/fileio.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1445267685/CONU2.o ${OBJECTDIR}/_ext/1445267685/EX16.o ${OBJECTDIR}/ReadTest.o ${OBJECTDIR}/_ext/1445267685/SDMMC.o ${OBJECTDIR}/_ext/1445267685/fileio.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

# Path to java used to run MPLAB X when this makefile was created
MP_JAVA_PATH="C:\Program Files (x86)\Java\jre6/bin/"
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC="C:\Program Files (x86)\Microchip\MPLAB C30\bin\pic30-gcc.exe"
# MP_BC is not defined
MP_AS="C:\Program Files (x86)\Microchip\MPLAB C30\bin\pic30-as.exe"
MP_LD="C:\Program Files (x86)\Microchip\MPLAB C30\bin\pic30-ld.exe"
MP_AR="C:\Program Files (x86)\Microchip\MPLAB C30\bin\pic30-ar.exe"
DEP_GEN=${MP_JAVA_PATH}java -jar "C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/extractobjectdependencies.jar" 
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps
MP_CC_DIR="C:\Program Files (x86)\Microchip\MPLAB C30\bin"
# MP_BC_DIR is not defined
MP_AS_DIR="C:\Program Files (x86)\Microchip\MPLAB C30\bin"
MP_LD_DIR="C:\Program Files (x86)\Microchip\MPLAB C30\bin"
MP_AR_DIR="C:\Program Files (x86)\Microchip\MPLAB C30\bin"
# MP_BC_DIR is not defined

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/14-FileIO.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA010
MP_LINKER_FILE_OPTION=,-Tp24FJ128GA010.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1445267685/CONU2.o: ../../lib/CONU2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/CONU2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/CONU2.o.ok ${OBJECTDIR}/_ext/1445267685/CONU2.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/CONU2.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445267685/CONU2.o.d" -o ${OBJECTDIR}/_ext/1445267685/CONU2.o ../../lib/CONU2.c  
	
${OBJECTDIR}/_ext/1445267685/EX16.o: ../../lib/EX16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.ok ${OBJECTDIR}/_ext/1445267685/EX16.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/EX16.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445267685/EX16.o.d" -o ${OBJECTDIR}/_ext/1445267685/EX16.o ../../lib/EX16.c  
	
${OBJECTDIR}/ReadTest.o: ReadTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ReadTest.o.d 
	@${RM} ${OBJECTDIR}/ReadTest.o.ok ${OBJECTDIR}/ReadTest.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ReadTest.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/ReadTest.o.d" -o ${OBJECTDIR}/ReadTest.o ReadTest.c  
	
${OBJECTDIR}/_ext/1445267685/SDMMC.o: ../../lib/SDMMC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.ok ${OBJECTDIR}/_ext/1445267685/SDMMC.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/SDMMC.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445267685/SDMMC.o.d" -o ${OBJECTDIR}/_ext/1445267685/SDMMC.o ../../lib/SDMMC.c  
	
${OBJECTDIR}/_ext/1445267685/fileio.o: ../../lib/fileio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.ok ${OBJECTDIR}/_ext/1445267685/fileio.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/fileio.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445267685/fileio.o.d" -o ${OBJECTDIR}/_ext/1445267685/fileio.o ../../lib/fileio.c  
	
else
${OBJECTDIR}/_ext/1445267685/CONU2.o: ../../lib/CONU2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/CONU2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/CONU2.o.ok ${OBJECTDIR}/_ext/1445267685/CONU2.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/CONU2.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445267685/CONU2.o.d" -o ${OBJECTDIR}/_ext/1445267685/CONU2.o ../../lib/CONU2.c  
	
${OBJECTDIR}/_ext/1445267685/EX16.o: ../../lib/EX16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.ok ${OBJECTDIR}/_ext/1445267685/EX16.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/EX16.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445267685/EX16.o.d" -o ${OBJECTDIR}/_ext/1445267685/EX16.o ../../lib/EX16.c  
	
${OBJECTDIR}/ReadTest.o: ReadTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ReadTest.o.d 
	@${RM} ${OBJECTDIR}/ReadTest.o.ok ${OBJECTDIR}/ReadTest.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ReadTest.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/ReadTest.o.d" -o ${OBJECTDIR}/ReadTest.o ReadTest.c  
	
${OBJECTDIR}/_ext/1445267685/SDMMC.o: ../../lib/SDMMC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.ok ${OBJECTDIR}/_ext/1445267685/SDMMC.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/SDMMC.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445267685/SDMMC.o.d" -o ${OBJECTDIR}/_ext/1445267685/SDMMC.o ../../lib/SDMMC.c  
	
${OBJECTDIR}/_ext/1445267685/fileio.o: ../../lib/fileio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.ok ${OBJECTDIR}/_ext/1445267685/fileio.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1445267685/fileio.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../../include" -MMD -MF "${OBJECTDIR}/_ext/1445267685/fileio.o.d" -o ${OBJECTDIR}/_ext/1445267685/fileio.o ../../lib/fileio.c  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/14-FileIO.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/14-FileIO.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -Wl,--defsym=__MPLAB_BUILD=1,--heap=1024,--no-check-sections,-L"../../../../Program Files/Microchip/MPLAB C30/lib",-Map="$(TARGETBASE).map",--report-mem,--defsym=__ICD2RAM=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/14-FileIO.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/14-FileIO.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -Wl,--defsym=__MPLAB_BUILD=1,--heap=1024,--no-check-sections,-L"../../../../Program Files/Microchip/MPLAB C30/lib",-Map="$(TARGETBASE).map",--report-mem,--defsym=__ICD2RAM=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/14-FileIO.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
