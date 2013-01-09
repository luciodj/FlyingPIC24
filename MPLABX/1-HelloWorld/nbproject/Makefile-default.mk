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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/1-HelloWorld.${IMAGE_TYPE}.elf
else
IMAGE_TYPE=production
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/1-HelloWorld.${IMAGE_TYPE}.elf
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files
OBJECTFILES=${OBJECTDIR}/Hello1.o


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
MP_CC=C:\\Program\ Files\ \(x86\)\\Microchip\\mplabc30\\v3.30b\\bin\\pic30-gcc.exe
# MP_BC is not defined
MP_AS=C:\\Program\ Files\ \(x86\)\\Microchip\\mplabc30\\v3.30b\\bin\\pic30-as.exe
MP_LD=C:\\Program\ Files\ \(x86\)\\Microchip\\mplabc30\\v3.30b\\bin\\pic30-ld.exe
MP_AR=C:\\Program\ Files\ \(x86\)\\Microchip\\mplabc30\\v3.30b\\bin\\pic30-ar.exe
# MP_BC is not defined
MP_CC_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\mplabc30\\v3.30b\\bin
# MP_BC_DIR is not defined
MP_AS_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\mplabc30\\v3.30b\\bin
MP_LD_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\mplabc30\\v3.30b\\bin
MP_AR_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\mplabc30\\v3.30b\\bin
# MP_BC_DIR is not defined

.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/1-HelloWorld.${IMAGE_TYPE}.elf

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
${OBJECTDIR}/Hello1.o: Hello1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Hello1.o.d 
	@${RM} ${OBJECTDIR}/Hello1.o.ok ${OBJECTDIR}/Hello1.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -MMD -MF ${OBJECTDIR}/Hello1.o.d -o ${OBJECTDIR}/Hello1.o Hello1.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -MMD -MF ${OBJECTDIR}/Hello1.o.d -o ${OBJECTDIR}/Hello1.o Hello1.c    2>&1  > ${OBJECTDIR}/Hello1.o.err ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/Hello1.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/Hello1.o.d > ${OBJECTDIR}/Hello1.o.tmp
	@${RM} ${OBJECTDIR}/Hello1.o.d 
	@${CP} ${OBJECTDIR}/Hello1.o.tmp ${OBJECTDIR}/Hello1.o.d 
	@${RM} ${OBJECTDIR}/Hello1.o.tmp 
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/Hello1.o.d > ${OBJECTDIR}/Hello1.o.tmp
	@${RM} ${OBJECTDIR}/Hello1.o.d 
	@${CP} ${OBJECTDIR}/Hello1.o.tmp ${OBJECTDIR}/Hello1.o.d 
	@${RM} ${OBJECTDIR}/Hello1.o.tmp
endif
	@touch ${OBJECTDIR}/Hello1.o.err 
	@cat ${OBJECTDIR}/Hello1.o.err 
	@if [ -f ${OBJECTDIR}/Hello1.o.ok ] ; then rm -f ${OBJECTDIR}/Hello1.o.ok; else exit 1; fi
	
else
${OBJECTDIR}/Hello1.o: Hello1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Hello1.o.d 
	@${RM} ${OBJECTDIR}/Hello1.o.ok ${OBJECTDIR}/Hello1.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -MMD -MF ${OBJECTDIR}/Hello1.o.d -o ${OBJECTDIR}/Hello1.o Hello1.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -fno-short-double -I"../../include" -MMD -MF ${OBJECTDIR}/Hello1.o.d -o ${OBJECTDIR}/Hello1.o Hello1.c    2>&1  > ${OBJECTDIR}/Hello1.o.err ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/Hello1.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/Hello1.o.d > ${OBJECTDIR}/Hello1.o.tmp
	@${RM} ${OBJECTDIR}/Hello1.o.d 
	@${CP} ${OBJECTDIR}/Hello1.o.tmp ${OBJECTDIR}/Hello1.o.d 
	@${RM} ${OBJECTDIR}/Hello1.o.tmp 
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/Hello1.o.d > ${OBJECTDIR}/Hello1.o.tmp
	@${RM} ${OBJECTDIR}/Hello1.o.d 
	@${CP} ${OBJECTDIR}/Hello1.o.tmp ${OBJECTDIR}/Hello1.o.d 
	@${RM} ${OBJECTDIR}/Hello1.o.tmp
endif
	@touch ${OBJECTDIR}/Hello1.o.err 
	@cat ${OBJECTDIR}/Hello1.o.err 
	@if [ -f ${OBJECTDIR}/Hello1.o.ok ] ; then rm -f ${OBJECTDIR}/Hello1.o.ok; else exit 1; fi
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/1-HelloWorld.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf  -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG  -o dist/${CND_CONF}/${IMAGE_TYPE}/1-HelloWorld.${IMAGE_TYPE}.elf ${OBJECTFILES}        -Wl,--defsym=__MPLAB_BUILD=1,--no-check-sections,-L"../../../../Program Files/Microchip/mplabc300/lib",-Map="$(BINDIR_)$(TARGETBASE).map",--report-mem,--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/1-HelloWorld.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf  -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/1-HelloWorld.${IMAGE_TYPE}.elf ${OBJECTFILES}        -Wl,--defsym=__MPLAB_BUILD=1,--no-check-sections,-L"../../../../Program Files/Microchip/mplabc300/lib",-Map="$(BINDIR_)$(TARGETBASE).map",--report-mem,--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/1-HelloWorld.${IMAGE_TYPE}.elf -omf=elf
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
