##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Tree
ConfigurationName      :=Debug
WorkspacePath          :=/home/user/Dokumenty/programowanie/laborki/PROI/PROI
ProjectPath            :=/home/user/Dokumenty/programowanie/laborki/PROI/PROI/Tree
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=krzys
Date                   :=06/06/18
CodeLitePath           :=/home/user/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Tree.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
Objects0=$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(ObjectSuffix): ../../shopping/codelite/shopping/Drzewa/pomocnicze.cpp $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/Drzewa/pomocnicze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(DependSuffix): ../../shopping/codelite/shopping/Drzewa/pomocnicze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(DependSuffix) -MM ../../shopping/codelite/shopping/Drzewa/pomocnicze.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(PreprocessSuffix): ../../shopping/codelite/shopping/Drzewa/pomocnicze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_pomocnicze.cpp$(PreprocessSuffix) ../../shopping/codelite/shopping/Drzewa/pomocnicze.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(ObjectSuffix): ../../shopping/codelite/shopping/Drzewa/IntUI.cpp $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/Drzewa/IntUI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(DependSuffix): ../../shopping/codelite/shopping/Drzewa/IntUI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(DependSuffix) -MM ../../shopping/codelite/shopping/Drzewa/IntUI.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(PreprocessSuffix): ../../shopping/codelite/shopping/Drzewa/IntUI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_IntUI.cpp$(PreprocessSuffix) ../../shopping/codelite/shopping/Drzewa/IntUI.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(ObjectSuffix): ../../shopping/codelite/shopping/Drzewa/main.cpp $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/Drzewa/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(DependSuffix): ../../shopping/codelite/shopping/Drzewa/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(DependSuffix) -MM ../../shopping/codelite/shopping/Drzewa/main.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(PreprocessSuffix): ../../shopping/codelite/shopping/Drzewa/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_main.cpp$(PreprocessSuffix) ../../shopping/codelite/shopping/Drzewa/main.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(ObjectSuffix): ../../shopping/codelite/shopping/Drzewa/Iterator.cpp $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/Drzewa/Iterator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(DependSuffix): ../../shopping/codelite/shopping/Drzewa/Iterator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(DependSuffix) -MM ../../shopping/codelite/shopping/Drzewa/Iterator.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(PreprocessSuffix): ../../shopping/codelite/shopping/Drzewa/Iterator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_Iterator.cpp$(PreprocessSuffix) ../../shopping/codelite/shopping/Drzewa/Iterator.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(ObjectSuffix): ../../shopping/codelite/shopping/Drzewa/exeptions.cpp $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/Drzewa/exeptions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(DependSuffix): ../../shopping/codelite/shopping/Drzewa/exeptions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(DependSuffix) -MM ../../shopping/codelite/shopping/Drzewa/exeptions.cpp

$(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(PreprocessSuffix): ../../shopping/codelite/shopping/Drzewa/exeptions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_shopping_codelite_shopping_Drzewa_exeptions.cpp$(PreprocessSuffix) ../../shopping/codelite/shopping/Drzewa/exeptions.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


