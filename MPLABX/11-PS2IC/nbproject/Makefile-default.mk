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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/11-PS2IC.${IMAGE_TYPE}.elf
else
IMAGE_TYPE=production
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/11-PS2IC.${IMAGE_TYPE}.elf
endif
# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}
# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files
OBJECTFILES=${OBJECTDIR}/PS2Test.o ${OBJECTDIR}/PS2IC.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

OS_ORIGINAL="MINGW32_NT-6.1"
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin\\pic30-gcc.exe
MP_AS=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin\\pic30-as.exe
MP_LD=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin\\pic30-ld.exe
MP_AR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin\\pic30-ar.exe
MP_CC_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin
MP_AS_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin
MP_LD_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin
MP_AR_DIR=C:\\Program\ Files\ \(x86\)\\Microchip\\MPLAB\ C30\\bin
.build-conf: ${BUILD_SUBPROJECTS}
ifneq ($(OS_CURRENT),$(OS_ORIGINAL))
	@echo "***** WARNING: This make file contains OS dependent code. The OS this makefile is being run is different from the OS it was created in."
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/11-PS2IC.${IMAGE_TYPE}.elf

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/PS2Test.o: PS2Test.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR} 
	${RM} ${OBJECTDIR}/PS2Test.o.d 
	${MP_CC} -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=24FJ128GA010 -I"../../include" -MMD -MF ${OBJECTDIR}/PS2Test.o.d -o ${OBJECTDIR}/PS2Test.o PS2Test.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/PS2Test.o.d > ${OBJECTDIR}/PS2Test.o.tmp
	${RM} ${OBJECTDIR}/PS2Test.o.d 
	${CP} ${OBJECTDIR}/PS2Test.o.tmp ${OBJECTDIR}/PS2Test.o.d 
	${RM} ${OBJECTDIR}/PS2Test.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/PS2Test.o.d > ${OBJECTDIR}/PS2Test.o.tmp
	${RM} ${OBJECTDIR}/PS2Test.o.d 
	${CP} ${OBJECTDIR}/PS2Test.o.tmp ${OBJECTDIR}/PS2Test.o.d 
	${RM} ${OBJECTDIR}/PS2Test.o.tmp}
endif
${OBJECTDIR}/PS2IC.o: PS2IC.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR} 
	${RM} ${OBJECTDIR}/PS2IC.o.d 
	${MP_CC} -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=24FJ128GA010 -I"../../include" -MMD -MF ${OBJECTDIR}/PS2IC.o.d -o ${OBJECTDIR}/PS2IC.o PS2IC.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/PS2IC.o.d > ${OBJECTDIR}/PS2IC.o.tmp
	${RM} ${OBJECTDIR}/PS2IC.o.d 
	${CP} ${OBJECTDIR}/PS2IC.o.tmp ${OBJECTDIR}/PS2IC.o.d 
	${RM} ${OBJECTDIR}/PS2IC.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/PS2IC.o.d > ${OBJECTDIR}/PS2IC.o.tmp
	${RM} ${OBJECTDIR}/PS2IC.o.d 
	${CP} ${OBJECTDIR}/PS2IC.o.tmp ${OBJECTDIR}/PS2IC.o.d 
	${RM} ${OBJECTDIR}/PS2IC.o.tmp}
endif
else
${OBJECTDIR}/PS2Test.o: PS2Test.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR} 
	${RM} ${OBJECTDIR}/PS2Test.o.d 
	${MP_CC}  -omf=elf -x c -c -mcpu=24FJ128GA010 -I"../../include" -MMD -MF ${OBJECTDIR}/PS2Test.o.d -o ${OBJECTDIR}/PS2Test.o PS2Test.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/PS2Test.o.d > ${OBJECTDIR}/PS2Test.o.tmp
	${RM} ${OBJECTDIR}/PS2Test.o.d 
	${CP} ${OBJECTDIR}/PS2Test.o.tmp ${OBJECTDIR}/PS2Test.o.d 
	${RM} ${OBJECTDIR}/PS2Test.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/PS2Test.o.d > ${OBJECTDIR}/PS2Test.o.tmp
	${RM} ${OBJECTDIR}/PS2Test.o.d 
	${CP} ${OBJECTDIR}/PS2Test.o.tmp ${OBJECTDIR}/PS2Test.o.d 
	${RM} ${OBJECTDIR}/PS2Test.o.tmp}
endif
${OBJECTDIR}/PS2IC.o: PS2IC.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR} 
	${RM} ${OBJECTDIR}/PS2IC.o.d 
	${MP_CC}  -omf=elf -x c -c -mcpu=24FJ128GA010 -I"../../include" -MMD -MF ${OBJECTDIR}/PS2IC.o.d -o ${OBJECTDIR}/PS2IC.o PS2IC.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/PS2IC.o.d > ${OBJECTDIR}/PS2IC.o.tmp
	${RM} ${OBJECTDIR}/PS2IC.o.d 
	${CP} ${OBJECTDIR}/PS2IC.o.tmp ${OBJECTDIR}/PS2IC.o.d 
	${RM} ${OBJECTDIR}/PS2IC.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/PS2IC.o.d > ${OBJECTDIR}/PS2IC.o.tmp
	${RM} ${OBJECTDIR}/PS2IC.o.d 
	${CP} ${OBJECTDIR}/PS2IC.o.tmp ${OBJECTDIR}/PS2IC.o.d 
	${RM} ${OBJECTDIR}/PS2IC.o.tmp}
endif
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/11-PS2IC.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  -omf=elf  -mcpu=24FJ128GA010  -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/11-PS2IC.${IMAGE_TYPE}.elf ${OBJECTFILES}      -Wl,--defsym=__MPLAB_BUILD=1,-Tp24FJ128GA010.gld,--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,-L"../../../../Program Files/Microchip/MPLAB C30/lib",-Map="$(TARGETBASE).map",--defsym=__ICD2RAM=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/11-PS2IC.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  -omf=elf  -mcpu=24FJ128GA010  -o dist/${CND_CONF}/${IMAGE_TYPE}/11-PS2IC.${IMAGE_TYPE}.elf ${OBJECTFILES}      -Wl,--defsym=__MPLAB_BUILD=1,-Tp24FJ128GA010.gld,-L"../../../../Program Files/Microchip/MPLAB C30/lib",-Map="$(TARGETBASE).map",--defsym=__ICD2RAM=1
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/11-PS2IC.${IMAGE_TYPE}.elf -omf=elf
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/default
	${RM} -r dist
# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
