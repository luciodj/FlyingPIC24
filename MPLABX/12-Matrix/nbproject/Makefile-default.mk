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
MKDIR=mkdir -p
RM=rm -f 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/12-Matrix.${IMAGE_TYPE}.elf
else
IMAGE_TYPE=production
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/12-Matrix.${IMAGE_TYPE}.elf
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files
OBJECTFILES=${OBJECTDIR}/Matrix2.o ${OBJECTDIR}/_ext/1445267685/EX16.o ${OBJECTDIR}/_ext/1445267685/text.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

# Path to java used to run MPLAB X when this makefile was created
MP_JAVA_PATH=C:\\Program\ Files\ \(x86\)\\Java\\jre6/bin/
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin\\pic30-gcc.exe
# MP_BC is not defined
MP_AS=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin\\pic30-as.exe
MP_LD=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin\\pic30-ld.exe
MP_AR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin\\pic30-ar.exe
# MP_BC is not defined
MP_CC_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin
# MP_BC_DIR is not defined
MP_AS_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin
MP_LD_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin
MP_AR_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin
# MP_BC_DIR is not defined

.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/12-Matrix.${IMAGE_TYPE}.elf

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
${OBJECTDIR}/_ext/1445267685/EX16.o: ../../lib/EX16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.ok ${OBJECTDIR}/_ext/1445267685/EX16.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/EX16.o.d -o ${OBJECTDIR}/_ext/1445267685/EX16.o ../../lib/EX16.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/EX16.o.d -o ${OBJECTDIR}/_ext/1445267685/EX16.o ../../lib/EX16.c    2>&1  > ${OBJECTDIR}/_ext/1445267685/EX16.o.err ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1445267685/EX16.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/EX16.o.d > ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${CP} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp 
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/EX16.o.d > ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${CP} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
endif
	@touch ${OBJECTDIR}/_ext/1445267685/EX16.o.err 
	@cat ${OBJECTDIR}/_ext/1445267685/EX16.o.err 
	@if [ -f ${OBJECTDIR}/_ext/1445267685/EX16.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1445267685/EX16.o.ok; else exit 1; fi
	
${OBJECTDIR}/Matrix2.o: Matrix2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Matrix2.o.d 
	@${RM} ${OBJECTDIR}/Matrix2.o.ok ${OBJECTDIR}/Matrix2.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/Matrix2.o.d -o ${OBJECTDIR}/Matrix2.o Matrix2.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/Matrix2.o.d -o ${OBJECTDIR}/Matrix2.o Matrix2.c    2>&1  > ${OBJECTDIR}/Matrix2.o.err ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/Matrix2.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/Matrix2.o.d > ${OBJECTDIR}/Matrix2.o.tmp
	@${RM} ${OBJECTDIR}/Matrix2.o.d 
	@${CP} ${OBJECTDIR}/Matrix2.o.tmp ${OBJECTDIR}/Matrix2.o.d 
	@${RM} ${OBJECTDIR}/Matrix2.o.tmp 
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/Matrix2.o.d > ${OBJECTDIR}/Matrix2.o.tmp
	@${RM} ${OBJECTDIR}/Matrix2.o.d 
	@${CP} ${OBJECTDIR}/Matrix2.o.tmp ${OBJECTDIR}/Matrix2.o.d 
	@${RM} ${OBJECTDIR}/Matrix2.o.tmp
endif
	@touch ${OBJECTDIR}/Matrix2.o.err 
	@cat ${OBJECTDIR}/Matrix2.o.err 
	@if [ -f ${OBJECTDIR}/Matrix2.o.ok ] ; then rm -f ${OBJECTDIR}/Matrix2.o.ok; else exit 1; fi
	
${OBJECTDIR}/_ext/1445267685/text.o: ../../lib/text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.ok ${OBJECTDIR}/_ext/1445267685/text.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/text.o.d -o ${OBJECTDIR}/_ext/1445267685/text.o ../../lib/text.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/text.o.d -o ${OBJECTDIR}/_ext/1445267685/text.o ../../lib/text.c    2>&1  > ${OBJECTDIR}/_ext/1445267685/text.o.err ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1445267685/text.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/text.o.d > ${OBJECTDIR}/_ext/1445267685/text.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${CP} ${OBJECTDIR}/_ext/1445267685/text.o.tmp ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.tmp 
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/text.o.d > ${OBJECTDIR}/_ext/1445267685/text.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${CP} ${OBJECTDIR}/_ext/1445267685/text.o.tmp ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.tmp
endif
	@touch ${OBJECTDIR}/_ext/1445267685/text.o.err 
	@cat ${OBJECTDIR}/_ext/1445267685/text.o.err 
	@if [ -f ${OBJECTDIR}/_ext/1445267685/text.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1445267685/text.o.ok; else exit 1; fi
	
else
${OBJECTDIR}/_ext/1445267685/EX16.o: ../../lib/EX16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.ok ${OBJECTDIR}/_ext/1445267685/EX16.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/EX16.o.d -o ${OBJECTDIR}/_ext/1445267685/EX16.o ../../lib/EX16.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/EX16.o.d -o ${OBJECTDIR}/_ext/1445267685/EX16.o ../../lib/EX16.c    2>&1  > ${OBJECTDIR}/_ext/1445267685/EX16.o.err ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1445267685/EX16.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/EX16.o.d > ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${CP} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp 
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/EX16.o.d > ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${CP} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
endif
	@touch ${OBJECTDIR}/_ext/1445267685/EX16.o.err 
	@cat ${OBJECTDIR}/_ext/1445267685/EX16.o.err 
	@if [ -f ${OBJECTDIR}/_ext/1445267685/EX16.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1445267685/EX16.o.ok; else exit 1; fi
	
${OBJECTDIR}/Matrix2.o: Matrix2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Matrix2.o.d 
	@${RM} ${OBJECTDIR}/Matrix2.o.ok ${OBJECTDIR}/Matrix2.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/Matrix2.o.d -o ${OBJECTDIR}/Matrix2.o Matrix2.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/Matrix2.o.d -o ${OBJECTDIR}/Matrix2.o Matrix2.c    2>&1  > ${OBJECTDIR}/Matrix2.o.err ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/Matrix2.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/Matrix2.o.d > ${OBJECTDIR}/Matrix2.o.tmp
	@${RM} ${OBJECTDIR}/Matrix2.o.d 
	@${CP} ${OBJECTDIR}/Matrix2.o.tmp ${OBJECTDIR}/Matrix2.o.d 
	@${RM} ${OBJECTDIR}/Matrix2.o.tmp 
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/Matrix2.o.d > ${OBJECTDIR}/Matrix2.o.tmp
	@${RM} ${OBJECTDIR}/Matrix2.o.d 
	@${CP} ${OBJECTDIR}/Matrix2.o.tmp ${OBJECTDIR}/Matrix2.o.d 
	@${RM} ${OBJECTDIR}/Matrix2.o.tmp
endif
	@touch ${OBJECTDIR}/Matrix2.o.err 
	@cat ${OBJECTDIR}/Matrix2.o.err 
	@if [ -f ${OBJECTDIR}/Matrix2.o.ok ] ; then rm -f ${OBJECTDIR}/Matrix2.o.ok; else exit 1; fi
	
${OBJECTDIR}/_ext/1445267685/text.o: ../../lib/text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.ok ${OBJECTDIR}/_ext/1445267685/text.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/text.o.d -o ${OBJECTDIR}/_ext/1445267685/text.o ../../lib/text.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/text.o.d -o ${OBJECTDIR}/_ext/1445267685/text.o ../../lib/text.c    2>&1  > ${OBJECTDIR}/_ext/1445267685/text.o.err ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1445267685/text.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/text.o.d > ${OBJECTDIR}/_ext/1445267685/text.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${CP} ${OBJECTDIR}/_ext/1445267685/text.o.tmp ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.tmp 
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/text.o.d > ${OBJECTDIR}/_ext/1445267685/text.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${CP} ${OBJECTDIR}/_ext/1445267685/text.o.tmp ${OBJECTDIR}/_ext/1445267685/text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445267685/text.o.tmp
endif
	@touch ${OBJECTDIR}/_ext/1445267685/text.o.err 
	@cat ${OBJECTDIR}/_ext/1445267685/text.o.err 
	@if [ -f ${OBJECTDIR}/_ext/1445267685/text.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1445267685/text.o.ok; else exit 1; fi
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/12-Matrix.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf  -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/12-Matrix.${IMAGE_TYPE}.elf ${OBJECTFILES}        -Wl,--defsym=__MPLAB_BUILD=1,--no-check-sections,-L"../../../../Program Files/Microchip/MPLAB C30/lib",-Map="$(TARGETBASE).map",--defsym=__ICD2RAM=1,--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/12-Matrix.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf  -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/12-Matrix.${IMAGE_TYPE}.elf ${OBJECTFILES}        -Wl,--defsym=__MPLAB_BUILD=1,--no-check-sections,-L"../../../../Program Files/Microchip/MPLAB C30/lib",-Map="$(TARGETBASE).map",--defsym=__ICD2RAM=1,--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/12-Matrix.${IMAGE_TYPE}.elf -omf=elf
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
