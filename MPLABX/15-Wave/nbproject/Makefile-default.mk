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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.elf
else
IMAGE_TYPE=production
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.elf
endif
# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}
# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1445267685/EX16.o ${OBJECTDIR}/_ext/1445267685/AudioPWM.o ${OBJECTDIR}/Wave.o ${OBJECTDIR}/_ext/1445267685/fileio.o ${OBJECTDIR}/WaveTest.o ${OBJECTDIR}/_ext/1445267685/SDMMC.o


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.elf

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1445267685/EX16.o: ../../lib/EX16.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${MP_CC} -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/EX16.o.d -o ${OBJECTDIR}/_ext/1445267685/EX16.o ../../lib/EX16.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/EX16.o.d > ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/EX16.o.d > ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp}
endif
${OBJECTDIR}/_ext/1445267685/AudioPWM.o: ../../lib/AudioPWM.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${MP_CC} -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d -o ${OBJECTDIR}/_ext/1445267685/AudioPWM.o ../../lib/AudioPWM.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d > ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d > ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp}
endif
${OBJECTDIR}/Wave.o: Wave.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR} 
	${RM} ${OBJECTDIR}/Wave.o.d 
	${MP_CC} -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/Wave.o.d -o ${OBJECTDIR}/Wave.o Wave.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/Wave.o.d > ${OBJECTDIR}/Wave.o.tmp
	${RM} ${OBJECTDIR}/Wave.o.d 
	${CP} ${OBJECTDIR}/Wave.o.tmp ${OBJECTDIR}/Wave.o.d 
	${RM} ${OBJECTDIR}/Wave.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/Wave.o.d > ${OBJECTDIR}/Wave.o.tmp
	${RM} ${OBJECTDIR}/Wave.o.d 
	${CP} ${OBJECTDIR}/Wave.o.tmp ${OBJECTDIR}/Wave.o.d 
	${RM} ${OBJECTDIR}/Wave.o.tmp}
endif
${OBJECTDIR}/_ext/1445267685/fileio.o: ../../lib/fileio.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${MP_CC} -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/fileio.o.d -o ${OBJECTDIR}/_ext/1445267685/fileio.o ../../lib/fileio.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/fileio.o.d > ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/fileio.o.d > ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp}
endif
${OBJECTDIR}/WaveTest.o: WaveTest.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR} 
	${RM} ${OBJECTDIR}/WaveTest.o.d 
	${MP_CC} -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/WaveTest.o.d -o ${OBJECTDIR}/WaveTest.o WaveTest.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/WaveTest.o.d > ${OBJECTDIR}/WaveTest.o.tmp
	${RM} ${OBJECTDIR}/WaveTest.o.d 
	${CP} ${OBJECTDIR}/WaveTest.o.tmp ${OBJECTDIR}/WaveTest.o.d 
	${RM} ${OBJECTDIR}/WaveTest.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/WaveTest.o.d > ${OBJECTDIR}/WaveTest.o.tmp
	${RM} ${OBJECTDIR}/WaveTest.o.d 
	${CP} ${OBJECTDIR}/WaveTest.o.tmp ${OBJECTDIR}/WaveTest.o.d 
	${RM} ${OBJECTDIR}/WaveTest.o.tmp}
endif
${OBJECTDIR}/_ext/1445267685/SDMMC.o: ../../lib/SDMMC.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${MP_CC} -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d -o ${OBJECTDIR}/_ext/1445267685/SDMMC.o ../../lib/SDMMC.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d > ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d > ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp}
endif
else
${OBJECTDIR}/_ext/1445267685/EX16.o: ../../lib/EX16.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${MP_CC}  -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/EX16.o.d -o ${OBJECTDIR}/_ext/1445267685/EX16.o ../../lib/EX16.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/EX16.o.d > ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/EX16.o.d > ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp ${OBJECTDIR}/_ext/1445267685/EX16.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/EX16.o.tmp}
endif
${OBJECTDIR}/_ext/1445267685/AudioPWM.o: ../../lib/AudioPWM.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${MP_CC}  -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d -o ${OBJECTDIR}/_ext/1445267685/AudioPWM.o ../../lib/AudioPWM.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d > ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d > ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/AudioPWM.o.tmp}
endif
${OBJECTDIR}/Wave.o: Wave.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR} 
	${RM} ${OBJECTDIR}/Wave.o.d 
	${MP_CC}  -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/Wave.o.d -o ${OBJECTDIR}/Wave.o Wave.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/Wave.o.d > ${OBJECTDIR}/Wave.o.tmp
	${RM} ${OBJECTDIR}/Wave.o.d 
	${CP} ${OBJECTDIR}/Wave.o.tmp ${OBJECTDIR}/Wave.o.d 
	${RM} ${OBJECTDIR}/Wave.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/Wave.o.d > ${OBJECTDIR}/Wave.o.tmp
	${RM} ${OBJECTDIR}/Wave.o.d 
	${CP} ${OBJECTDIR}/Wave.o.tmp ${OBJECTDIR}/Wave.o.d 
	${RM} ${OBJECTDIR}/Wave.o.tmp}
endif
${OBJECTDIR}/_ext/1445267685/fileio.o: ../../lib/fileio.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${MP_CC}  -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/fileio.o.d -o ${OBJECTDIR}/_ext/1445267685/fileio.o ../../lib/fileio.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/fileio.o.d > ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/fileio.o.d > ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp ${OBJECTDIR}/_ext/1445267685/fileio.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/fileio.o.tmp}
endif
${OBJECTDIR}/WaveTest.o: WaveTest.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR} 
	${RM} ${OBJECTDIR}/WaveTest.o.d 
	${MP_CC}  -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/WaveTest.o.d -o ${OBJECTDIR}/WaveTest.o WaveTest.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/WaveTest.o.d > ${OBJECTDIR}/WaveTest.o.tmp
	${RM} ${OBJECTDIR}/WaveTest.o.d 
	${CP} ${OBJECTDIR}/WaveTest.o.tmp ${OBJECTDIR}/WaveTest.o.d 
	${RM} ${OBJECTDIR}/WaveTest.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/WaveTest.o.d > ${OBJECTDIR}/WaveTest.o.tmp
	${RM} ${OBJECTDIR}/WaveTest.o.d 
	${CP} ${OBJECTDIR}/WaveTest.o.tmp ${OBJECTDIR}/WaveTest.o.d 
	${RM} ${OBJECTDIR}/WaveTest.o.tmp}
endif
${OBJECTDIR}/_ext/1445267685/SDMMC.o: ../../lib/SDMMC.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1445267685 
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${MP_CC}  -omf=elf -x c -c -mcpu=24FJ128GA010 -Wall -I"../../include" -O1 -MMD -MF ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d -o ${OBJECTDIR}/_ext/1445267685/SDMMC.o ../../lib/SDMMC.c 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	 sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d > ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp}
else 
	 sed -e 's/\"//g' ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d > ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${CP} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp ${OBJECTDIR}/_ext/1445267685/SDMMC.o.d 
	${RM} ${OBJECTDIR}/_ext/1445267685/SDMMC.o.tmp}
endif
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  -omf=elf  -mcpu=24FJ128GA010  -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.elf ${OBJECTFILES}      -Wl,--defsym=__MPLAB_BUILD=1,-Tp24FJ128GA010.gld,--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,--heap=2000,-L"../../../../Program Files/Microchip/MPLAB C30/lib",-Map="$(TARGETBASE).map",--defsym=__ICD2RAM=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  -omf=elf  -mcpu=24FJ128GA010  -o dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.elf ${OBJECTFILES}      -Wl,--defsym=__MPLAB_BUILD=1,-Tp24FJ128GA010.gld,--heap=2000,-L"../../../../Program Files/Microchip/MPLAB C30/lib",-Map="$(TARGETBASE).map",--defsym=__ICD2RAM=1
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/15-Wave.${IMAGE_TYPE}.elf -omf=elf
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
