##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=shopping
ConfigurationName      :=Debug
WorkspacePath          :=/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping
ProjectPath            :=/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/shopping
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=krzys
Date                   :=09/05/18
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
ObjectsFileList        :="shopping.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
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
CXXFLAGS :=  -g -Wall -O0 $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Basket.cpp$(ObjectSuffix) $(IntermediateDirectory)/Product.cpp$(ObjectSuffix) $(IntermediateDirectory)/structures.cpp$(ObjectSuffix) $(IntermediateDirectory)/Category.cpp$(ObjectSuffix) $(IntermediateDirectory)/Month.cpp$(ObjectSuffix) $(IntermediateDirectory)/Purchase.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/shopping/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Basket.cpp$(ObjectSuffix): Basket.cpp $(IntermediateDirectory)/Basket.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/shopping/Basket.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Basket.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Basket.cpp$(DependSuffix): Basket.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Basket.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Basket.cpp$(DependSuffix) -MM Basket.cpp

$(IntermediateDirectory)/Basket.cpp$(PreprocessSuffix): Basket.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Basket.cpp$(PreprocessSuffix) Basket.cpp

$(IntermediateDirectory)/Product.cpp$(ObjectSuffix): Product.cpp $(IntermediateDirectory)/Product.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/shopping/Product.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Product.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Product.cpp$(DependSuffix): Product.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Product.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Product.cpp$(DependSuffix) -MM Product.cpp

$(IntermediateDirectory)/Product.cpp$(PreprocessSuffix): Product.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Product.cpp$(PreprocessSuffix) Product.cpp

$(IntermediateDirectory)/structures.cpp$(ObjectSuffix): structures.cpp $(IntermediateDirectory)/structures.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/shopping/structures.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/structures.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/structures.cpp$(DependSuffix): structures.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/structures.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/structures.cpp$(DependSuffix) -MM structures.cpp

$(IntermediateDirectory)/structures.cpp$(PreprocessSuffix): structures.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/structures.cpp$(PreprocessSuffix) structures.cpp

$(IntermediateDirectory)/Category.cpp$(ObjectSuffix): Category.cpp $(IntermediateDirectory)/Category.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/shopping/Category.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Category.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Category.cpp$(DependSuffix): Category.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Category.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Category.cpp$(DependSuffix) -MM Category.cpp

$(IntermediateDirectory)/Category.cpp$(PreprocessSuffix): Category.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Category.cpp$(PreprocessSuffix) Category.cpp

$(IntermediateDirectory)/Month.cpp$(ObjectSuffix): Month.cpp $(IntermediateDirectory)/Month.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/shopping/Month.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Month.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Month.cpp$(DependSuffix): Month.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Month.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Month.cpp$(DependSuffix) -MM Month.cpp

$(IntermediateDirectory)/Month.cpp$(PreprocessSuffix): Month.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Month.cpp$(PreprocessSuffix) Month.cpp

$(IntermediateDirectory)/Purchase.cpp$(ObjectSuffix): Purchase.cpp $(IntermediateDirectory)/Purchase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Dokumenty/programowanie/laborki/PROI/shopping/codelite/shopping/shopping/Purchase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Purchase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Purchase.cpp$(DependSuffix): Purchase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Purchase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Purchase.cpp$(DependSuffix) -MM Purchase.cpp

$(IntermediateDirectory)/Purchase.cpp$(PreprocessSuffix): Purchase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Purchase.cpp$(PreprocessSuffix) Purchase.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


