##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DatabaseExplorer
ConfigurationName      :=Debug
IntermediateDirectory  :=.objsud
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/jankup/SourceCpp/wxdbexplorer/build"
ProjectPath            := "/home/jankup/SourceCpp/wxdbexplorer/src"
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
OutputFile             :=../bin/gcc/DatabaseExplorer_d
Preprocessors          :=$(PreprocessorSwitch)WXUSINGDLL $(PreprocessorSwitch)UNICODE $(PreprocessorSwitch)_UNICODE $(PreprocessorSwitch)__WX__ $(PreprocessorSwitch)DEBUG $(PreprocessorSwitch)_DEBUG $(PreprocessorSwitch)__WXDEBUG__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -Wall -g -O0 `wx-config --debug=yes --cflags`  $(Preprocessors)
C_CmpOptions           := -Wall -g -O0 `wx-config --debug=yes --cflags`  $(Preprocessors)
LinkOptions            :=  -Wl,-rpath,$$``ORIGIN/lib/ `wx-config --debug=yes --libs` 
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)controls/include" "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)wx_gtk2ud_propgrid-2.8_cd $(LibrarySwitch)wx_gtk2ud_scintilla-2.8_cd $(LibrarySwitch)wx_gtk2ud_shapeframework-2.8_cd $(LibrarySwitch)wxcode_gtk2_databaselayer_mysql-2.8 $(LibrarySwitch)wxcode_gtk2_databaselayer_sqlite-2.8 
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../bin/gcc" "$(LibraryPathSwitch)../bin/gcc/lib" "$(LibraryPathSwitch)../bin/gcc/lib" "$(LibraryPathSwitch)../bin/gcc/lib" 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/gui_GUI$(ObjectSuffix) $(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix) $(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix) $(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix) $(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix) $(IntermediateDirectory)/gui_TableSettingsDialog$(ObjectSuffix) $(IntermediateDirectory)/column$(ObjectSuffix) $(IntermediateDirectory)/tablecol$(ObjectSuffix) $(IntermediateDirectory)/table$(ObjectSuffix) \
	$(IntermediateDirectory)/database$(ObjectSuffix) $(IntermediateDirectory)/databasecol$(ObjectSuffix) $(IntermediateDirectory)/dbitem$(ObjectSuffix) $(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix) $(IntermediateDirectory)/wx_pch$(ObjectSuffix) $(IntermediateDirectory)/MySqlType$(ObjectSuffix) $(IntermediateDirectory)/MySqlDbAdapter$(ObjectSuffix) $(IntermediateDirectory)/SqliteDbAdapter$(ObjectSuffix) $(IntermediateDirectory)/IDbItem$(ObjectSuffix) $(IntermediateDirectory)/ErdTable$(ObjectSuffix) \
	$(IntermediateDirectory)/DnDTableShape$(ObjectSuffix) $(IntermediateDirectory)/FrameCanvas$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d .objsud || $(MakeDirCommand) .objsud

PreBuild:
	@echo Executing Pre Build commands ...
	python $(ProjectPath)/create_buildnum.py
	@echo Done


##
## Objects
##
$(IntermediateDirectory)/gui_GUI$(ObjectSuffix): gui/GUI.cpp $(IntermediateDirectory)/gui_GUI$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/GUI.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_GUI$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_GUI$(DependSuffix): gui/GUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_GUI$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_GUI$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/gui/GUI.cpp"

$(IntermediateDirectory)/gui_GUI$(PreprocessSuffix): gui/GUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_GUI$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/GUI.cpp"

$(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix): gui/DbViewerPanel.cpp $(IntermediateDirectory)/gui_DbViewerPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DbViewerPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DbViewerPanel$(DependSuffix): gui/DbViewerPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DbViewerPanel$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DbViewerPanel.cpp"

$(IntermediateDirectory)/gui_DbViewerPanel$(PreprocessSuffix): gui/DbViewerPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DbViewerPanel$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DbViewerPanel.cpp"

$(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix): gui/SqlCommandPanel.cpp $(IntermediateDirectory)/gui_SqlCommandPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/SqlCommandPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_SqlCommandPanel$(DependSuffix): gui/SqlCommandPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_SqlCommandPanel$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/gui/SqlCommandPanel.cpp"

$(IntermediateDirectory)/gui_SqlCommandPanel$(PreprocessSuffix): gui/SqlCommandPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_SqlCommandPanel$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/SqlCommandPanel.cpp"

$(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix): gui/ErdPanel.cpp $(IntermediateDirectory)/gui_ErdPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/ErdPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_ErdPanel$(DependSuffix): gui/ErdPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_ErdPanel$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/gui/ErdPanel.cpp"

$(IntermediateDirectory)/gui_ErdPanel$(PreprocessSuffix): gui/ErdPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_ErdPanel$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/ErdPanel.cpp"

$(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix): gui/DbSettingDialog.cpp $(IntermediateDirectory)/gui_DbSettingDialog$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DbSettingDialog.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DbSettingDialog$(DependSuffix): gui/DbSettingDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DbSettingDialog$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DbSettingDialog.cpp"

$(IntermediateDirectory)/gui_DbSettingDialog$(PreprocessSuffix): gui/DbSettingDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DbSettingDialog$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DbSettingDialog.cpp"

$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix): gui/DatabaseExplorerFrame.cpp $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DatabaseExplorerFrame.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(DependSuffix): gui/DatabaseExplorerFrame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DatabaseExplorerFrame.cpp"

$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(PreprocessSuffix): gui/DatabaseExplorerFrame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/DatabaseExplorerFrame.cpp"

$(IntermediateDirectory)/gui_TableSettingsDialog$(ObjectSuffix): gui/TableSettingsDialog.cpp $(IntermediateDirectory)/gui_TableSettingsDialog$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/TableSettingsDialog.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_TableSettingsDialog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_TableSettingsDialog$(DependSuffix): gui/TableSettingsDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_TableSettingsDialog$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_TableSettingsDialog$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/gui/TableSettingsDialog.cpp"

$(IntermediateDirectory)/gui_TableSettingsDialog$(PreprocessSuffix): gui/TableSettingsDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_TableSettingsDialog$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/gui/TableSettingsDialog.cpp"

$(IntermediateDirectory)/column$(ObjectSuffix): column.cpp $(IntermediateDirectory)/column$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/column.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/column$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/column$(DependSuffix): column.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/column$(ObjectSuffix) -MF$(IntermediateDirectory)/column$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/column.cpp"

$(IntermediateDirectory)/column$(PreprocessSuffix): column.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/column$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/column.cpp"

$(IntermediateDirectory)/tablecol$(ObjectSuffix): tablecol.cpp $(IntermediateDirectory)/tablecol$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/tablecol.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/tablecol$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tablecol$(DependSuffix): tablecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tablecol$(ObjectSuffix) -MF$(IntermediateDirectory)/tablecol$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/tablecol.cpp"

$(IntermediateDirectory)/tablecol$(PreprocessSuffix): tablecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tablecol$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/tablecol.cpp"

$(IntermediateDirectory)/table$(ObjectSuffix): table.cpp $(IntermediateDirectory)/table$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/table.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/table$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/table$(DependSuffix): table.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/table$(ObjectSuffix) -MF$(IntermediateDirectory)/table$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/table.cpp"

$(IntermediateDirectory)/table$(PreprocessSuffix): table.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/table$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/table.cpp"

$(IntermediateDirectory)/database$(ObjectSuffix): database.cpp $(IntermediateDirectory)/database$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/database.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/database$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/database$(DependSuffix): database.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/database$(ObjectSuffix) -MF$(IntermediateDirectory)/database$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/database.cpp"

$(IntermediateDirectory)/database$(PreprocessSuffix): database.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/database$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/database.cpp"

$(IntermediateDirectory)/databasecol$(ObjectSuffix): databasecol.cpp $(IntermediateDirectory)/databasecol$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/databasecol.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/databasecol$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/databasecol$(DependSuffix): databasecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/databasecol$(ObjectSuffix) -MF$(IntermediateDirectory)/databasecol$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/databasecol.cpp"

$(IntermediateDirectory)/databasecol$(PreprocessSuffix): databasecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/databasecol$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/databasecol.cpp"

$(IntermediateDirectory)/dbitem$(ObjectSuffix): dbitem.cpp $(IntermediateDirectory)/dbitem$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/dbitem.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/dbitem$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/dbitem$(DependSuffix): dbitem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/dbitem$(ObjectSuffix) -MF$(IntermediateDirectory)/dbitem$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/dbitem.cpp"

$(IntermediateDirectory)/dbitem$(PreprocessSuffix): dbitem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/dbitem$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/dbitem.cpp"

$(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix): DatabaseExplorerApp.cpp $(IntermediateDirectory)/DatabaseExplorerApp$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/DatabaseExplorerApp.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DatabaseExplorerApp$(DependSuffix): DatabaseExplorerApp.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix) -MF$(IntermediateDirectory)/DatabaseExplorerApp$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/DatabaseExplorerApp.cpp"

$(IntermediateDirectory)/DatabaseExplorerApp$(PreprocessSuffix): DatabaseExplorerApp.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DatabaseExplorerApp$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/DatabaseExplorerApp.cpp"

$(IntermediateDirectory)/wx_pch$(ObjectSuffix): wx_pch.cpp $(IntermediateDirectory)/wx_pch$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/wx_pch.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wx_pch$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wx_pch$(DependSuffix): wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wx_pch$(ObjectSuffix) -MF$(IntermediateDirectory)/wx_pch$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/wx_pch.cpp"

$(IntermediateDirectory)/wx_pch$(PreprocessSuffix): wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wx_pch$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/wx_pch.cpp"

$(IntermediateDirectory)/MySqlType$(ObjectSuffix): MySqlType.cpp $(IntermediateDirectory)/MySqlType$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/MySqlType.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/MySqlType$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MySqlType$(DependSuffix): MySqlType.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MySqlType$(ObjectSuffix) -MF$(IntermediateDirectory)/MySqlType$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/MySqlType.cpp"

$(IntermediateDirectory)/MySqlType$(PreprocessSuffix): MySqlType.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MySqlType$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/MySqlType.cpp"

$(IntermediateDirectory)/MySqlDbAdapter$(ObjectSuffix): MySqlDbAdapter.cpp $(IntermediateDirectory)/MySqlDbAdapter$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/MySqlDbAdapter.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/MySqlDbAdapter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MySqlDbAdapter$(DependSuffix): MySqlDbAdapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MySqlDbAdapter$(ObjectSuffix) -MF$(IntermediateDirectory)/MySqlDbAdapter$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/MySqlDbAdapter.cpp"

$(IntermediateDirectory)/MySqlDbAdapter$(PreprocessSuffix): MySqlDbAdapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MySqlDbAdapter$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/MySqlDbAdapter.cpp"

$(IntermediateDirectory)/SqliteDbAdapter$(ObjectSuffix): SqliteDbAdapter.cpp $(IntermediateDirectory)/SqliteDbAdapter$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/SqliteDbAdapter.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/SqliteDbAdapter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SqliteDbAdapter$(DependSuffix): SqliteDbAdapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SqliteDbAdapter$(ObjectSuffix) -MF$(IntermediateDirectory)/SqliteDbAdapter$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/SqliteDbAdapter.cpp"

$(IntermediateDirectory)/SqliteDbAdapter$(PreprocessSuffix): SqliteDbAdapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SqliteDbAdapter$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/SqliteDbAdapter.cpp"

$(IntermediateDirectory)/IDbItem$(ObjectSuffix): IDbItem.cpp $(IntermediateDirectory)/IDbItem$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/IDbItem.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/IDbItem$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IDbItem$(DependSuffix): IDbItem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IDbItem$(ObjectSuffix) -MF$(IntermediateDirectory)/IDbItem$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/IDbItem.cpp"

$(IntermediateDirectory)/IDbItem$(PreprocessSuffix): IDbItem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IDbItem$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/IDbItem.cpp"

$(IntermediateDirectory)/ErdTable$(ObjectSuffix): ErdTable.cpp $(IntermediateDirectory)/ErdTable$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/ErdTable.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ErdTable$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ErdTable$(DependSuffix): ErdTable.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ErdTable$(ObjectSuffix) -MF$(IntermediateDirectory)/ErdTable$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/ErdTable.cpp"

$(IntermediateDirectory)/ErdTable$(PreprocessSuffix): ErdTable.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ErdTable$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/ErdTable.cpp"

$(IntermediateDirectory)/DnDTableShape$(ObjectSuffix): DnDTableShape.cpp $(IntermediateDirectory)/DnDTableShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/DnDTableShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DnDTableShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DnDTableShape$(DependSuffix): DnDTableShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DnDTableShape$(ObjectSuffix) -MF$(IntermediateDirectory)/DnDTableShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/DnDTableShape.cpp"

$(IntermediateDirectory)/DnDTableShape$(PreprocessSuffix): DnDTableShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DnDTableShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/DnDTableShape.cpp"

$(IntermediateDirectory)/FrameCanvas$(ObjectSuffix): FrameCanvas.cpp $(IntermediateDirectory)/FrameCanvas$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/src/FrameCanvas.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/FrameCanvas$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FrameCanvas$(DependSuffix): FrameCanvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FrameCanvas$(ObjectSuffix) -MF$(IntermediateDirectory)/FrameCanvas$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/src/FrameCanvas.cpp"

$(IntermediateDirectory)/FrameCanvas$(PreprocessSuffix): FrameCanvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FrameCanvas$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/src/FrameCanvas.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/gui_GUI$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_GUI$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_GUI$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbViewerPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbViewerPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_SqlCommandPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_SqlCommandPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_ErdPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_ErdPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbSettingDialog$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbSettingDialog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_TableSettingsDialog$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_TableSettingsDialog$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_TableSettingsDialog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/column$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/column$(DependSuffix)
	$(RM) $(IntermediateDirectory)/column$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tablecol$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tablecol$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tablecol$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/table$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/table$(DependSuffix)
	$(RM) $(IntermediateDirectory)/table$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/database$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/database$(DependSuffix)
	$(RM) $(IntermediateDirectory)/database$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/databasecol$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/databasecol$(DependSuffix)
	$(RM) $(IntermediateDirectory)/databasecol$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/dbitem$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/dbitem$(DependSuffix)
	$(RM) $(IntermediateDirectory)/dbitem$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DatabaseExplorerApp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DatabaseExplorerApp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MySqlType$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MySqlType$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MySqlType$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MySqlDbAdapter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MySqlDbAdapter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MySqlDbAdapter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/SqliteDbAdapter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/SqliteDbAdapter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/SqliteDbAdapter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/IDbItem$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/IDbItem$(DependSuffix)
	$(RM) $(IntermediateDirectory)/IDbItem$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ErdTable$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ErdTable$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ErdTable$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DnDTableShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DnDTableShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DnDTableShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/FrameCanvas$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/FrameCanvas$(DependSuffix)
	$(RM) $(IntermediateDirectory)/FrameCanvas$(PreprocessSuffix)
	$(RM) $(OutputFile)


