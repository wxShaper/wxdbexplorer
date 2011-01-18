##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=wxPropGrid
ConfigurationName      :=Release
IntermediateDirectory  :=.objsu
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/jankup/SourceCpp/wxdbexplorer/build"
ProjectPath            := "/home/jankup/SourceCpp/wxdbexplorer/build/propgrid"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Peter Janků
Date                   :=18.1.2011
CodeLitePath           :="/home/jankup/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
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
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=../../bin/gcc/lib/libwx_gtk2u_propgrid-2.8_cd.so
Preprocessors          :=$(PreprocessorSwitch)WXMAKINGDLL_PROPGRID $(PreprocessorSwitch)MONOLITHIC $(PreprocessorSwitch)WXUSINGDLL $(PreprocessorSwitch)UNICODE $(PreprocessorSwitch)_UNICODE $(PreprocessorSwitch)__WX__ $(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -Wall -O3 -fPIC -fno-strict-aliasing `wx-config --debug=no --cflags`  $(Preprocessors)
C_CmpOptions           := -Wall -O3 -fPIC -fno-strict-aliasing `wx-config --debug=no --cflags`  $(Preprocessors)
LinkOptions            :=  -s `wx-config --libs` 
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../../src/controls/include" 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../../bin/gcc/lib" "$(LibraryPathSwitch)../../bin/gcc" 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/propgrid_odcombo$(ObjectSuffix) $(IntermediateDirectory)/propgrid_extras$(ObjectSuffix) $(IntermediateDirectory)/propgrid_manager$(ObjectSuffix) $(IntermediateDirectory)/propgrid_advprops$(ObjectSuffix) $(IntermediateDirectory)/propgrid_propgrid$(ObjectSuffix) $(IntermediateDirectory)/propgrid_props$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d .objsu || $(MakeDirCommand) .objsu

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/propgrid_odcombo$(ObjectSuffix): ../../src/controls/src/propgrid/odcombo.cpp $(IntermediateDirectory)/propgrid_odcombo$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/odcombo.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/propgrid_odcombo$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/propgrid_odcombo$(DependSuffix): ../../src/controls/src/propgrid/odcombo.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/propgrid_odcombo$(ObjectSuffix) -MF$(IntermediateDirectory)/propgrid_odcombo$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/odcombo.cpp"

$(IntermediateDirectory)/propgrid_odcombo$(PreprocessSuffix): ../../src/controls/src/propgrid/odcombo.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/propgrid_odcombo$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/odcombo.cpp"

$(IntermediateDirectory)/propgrid_extras$(ObjectSuffix): ../../src/controls/src/propgrid/extras.cpp $(IntermediateDirectory)/propgrid_extras$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/extras.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/propgrid_extras$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/propgrid_extras$(DependSuffix): ../../src/controls/src/propgrid/extras.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/propgrid_extras$(ObjectSuffix) -MF$(IntermediateDirectory)/propgrid_extras$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/extras.cpp"

$(IntermediateDirectory)/propgrid_extras$(PreprocessSuffix): ../../src/controls/src/propgrid/extras.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/propgrid_extras$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/extras.cpp"

$(IntermediateDirectory)/propgrid_manager$(ObjectSuffix): ../../src/controls/src/propgrid/manager.cpp $(IntermediateDirectory)/propgrid_manager$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/manager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/propgrid_manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/propgrid_manager$(DependSuffix): ../../src/controls/src/propgrid/manager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/propgrid_manager$(ObjectSuffix) -MF$(IntermediateDirectory)/propgrid_manager$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/manager.cpp"

$(IntermediateDirectory)/propgrid_manager$(PreprocessSuffix): ../../src/controls/src/propgrid/manager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/propgrid_manager$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/manager.cpp"

$(IntermediateDirectory)/propgrid_advprops$(ObjectSuffix): ../../src/controls/src/propgrid/advprops.cpp $(IntermediateDirectory)/propgrid_advprops$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/advprops.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/propgrid_advprops$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/propgrid_advprops$(DependSuffix): ../../src/controls/src/propgrid/advprops.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/propgrid_advprops$(ObjectSuffix) -MF$(IntermediateDirectory)/propgrid_advprops$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/advprops.cpp"

$(IntermediateDirectory)/propgrid_advprops$(PreprocessSuffix): ../../src/controls/src/propgrid/advprops.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/propgrid_advprops$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/advprops.cpp"

$(IntermediateDirectory)/propgrid_propgrid$(ObjectSuffix): ../../src/controls/src/propgrid/propgrid.cpp $(IntermediateDirectory)/propgrid_propgrid$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/propgrid.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/propgrid_propgrid$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/propgrid_propgrid$(DependSuffix): ../../src/controls/src/propgrid/propgrid.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/propgrid_propgrid$(ObjectSuffix) -MF$(IntermediateDirectory)/propgrid_propgrid$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/propgrid.cpp"

$(IntermediateDirectory)/propgrid_propgrid$(PreprocessSuffix): ../../src/controls/src/propgrid/propgrid.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/propgrid_propgrid$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/propgrid.cpp"

$(IntermediateDirectory)/propgrid_props$(ObjectSuffix): ../../src/controls/src/propgrid/props.cpp $(IntermediateDirectory)/propgrid_props$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/props.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/propgrid_props$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/propgrid_props$(DependSuffix): ../../src/controls/src/propgrid/props.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/propgrid_props$(ObjectSuffix) -MF$(IntermediateDirectory)/propgrid_props$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/props.cpp"

$(IntermediateDirectory)/propgrid_props$(PreprocessSuffix): ../../src/controls/src/propgrid/props.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/propgrid_props$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/controls/src/propgrid/props.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/propgrid_odcombo$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_odcombo$(DependSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_odcombo$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_extras$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_extras$(DependSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_extras$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_advprops$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_advprops$(DependSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_advprops$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_propgrid$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_propgrid$(DependSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_propgrid$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_props$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_props$(DependSuffix)
	$(RM) $(IntermediateDirectory)/propgrid_props$(PreprocessSuffix)
	$(RM) $(OutputFile)


