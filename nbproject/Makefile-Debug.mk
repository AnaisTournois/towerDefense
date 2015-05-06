#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Balle.o \
	${OBJECTDIR}/BalleAttaque.o \
	${OBJECTDIR}/BalleRalentissante.o \
	${OBJECTDIR}/Cellule.o \
	${OBJECTDIR}/Chemin.o \
	${OBJECTDIR}/ElementCombattant.o \
	${OBJECTDIR}/ElementDynamique.o \
	${OBJECTDIR}/ElementVisuel.o \
	${OBJECTDIR}/Jeu.o \
	${OBJECTDIR}/Joueur.o \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/Monstre.o \
	${OBJECTDIR}/Point.o \
	${OBJECTDIR}/Tour.o \
	${OBJECTDIR}/TourAttaque.o \
	${OBJECTDIR}/TourRalentissante.o \
	${OBJECTDIR}/Vague.o \
	${OBJECTDIR}/Virage.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/towerdefense.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/towerdefense.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/towerdefense ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Balle.o: Balle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Balle.o Balle.cpp

${OBJECTDIR}/BalleAttaque.o: BalleAttaque.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/BalleAttaque.o BalleAttaque.cpp

${OBJECTDIR}/BalleRalentissante.o: BalleRalentissante.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/BalleRalentissante.o BalleRalentissante.cpp

${OBJECTDIR}/Cellule.o: Cellule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Cellule.o Cellule.cpp

${OBJECTDIR}/Chemin.o: Chemin.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Chemin.o Chemin.cpp

${OBJECTDIR}/ElementCombattant.o: ElementCombattant.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ElementCombattant.o ElementCombattant.cpp

${OBJECTDIR}/ElementDynamique.o: ElementDynamique.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ElementDynamique.o ElementDynamique.cpp

${OBJECTDIR}/ElementVisuel.o: ElementVisuel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ElementVisuel.o ElementVisuel.cpp

${OBJECTDIR}/Jeu.o: Jeu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Jeu.o Jeu.cpp

${OBJECTDIR}/Joueur.o: Joueur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Joueur.o Joueur.cpp

${OBJECTDIR}/Main.o: Main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/Monstre.o: Monstre.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Monstre.o Monstre.cpp

${OBJECTDIR}/Point.o: Point.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Point.o Point.cpp

${OBJECTDIR}/Tour.o: Tour.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tour.o Tour.cpp

${OBJECTDIR}/TourAttaque.o: TourAttaque.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TourAttaque.o TourAttaque.cpp

${OBJECTDIR}/TourRalentissante.o: TourRalentissante.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TourRalentissante.o TourRalentissante.cpp

${OBJECTDIR}/Vague.o: Vague.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Vague.o Vague.cpp

${OBJECTDIR}/Virage.o: Virage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Virage.o Virage.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/towerdefense.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
