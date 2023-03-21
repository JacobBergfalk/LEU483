##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## macOS
ProjectName            :=ex1rectangle
ConfigurationName      :=macOS
WorkspaceConfiguration :=macOS
WorkspacePath          :=/Users/jacobbergfalk/Downloads/set1
ProjectPath            :=/Users/jacobbergfalk/Downloads/set1/ex1rectangle
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/ex1rectangle
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jacob Bergfalk
Date                   :=01/11/2022
CodeLitePath           :="/Users/jacobbergfalk/Library/Application Support/CodeLite"
MakeDirCommand         :=mkdir -p
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/Users/jacobbergfalk/Downloads/set1/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := llvm-as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/ex1rectangle.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ex1rectangle.c$(ObjectSuffix): ex1rectangle.c 
	$(CC) $(SourceSwitch) "/Users/jacobbergfalk/Downloads/set1/ex1rectangle/ex1rectangle.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex1rectangle.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex1rectangle.c$(PreprocessSuffix): ex1rectangle.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex1rectangle.c$(PreprocessSuffix) ex1rectangle.c

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


