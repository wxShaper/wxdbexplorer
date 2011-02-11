##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=DatabaseExplorer
ConfigurationName      :=Release
IntermediateDirectory  :=.objsu
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/jankup/SourcesCpp/wxdbexplorer/build"
ProjectPath            := "/home/jankup/SourcesCpp/wxdbexplorer/src"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Peter Janků
Date                   :=10.2.2011
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
OutputFile             :=../bin/gcc/DatabaseExplorer
Preprocessors          :=$(PreprocessorSwitch)WXUSINGDLL $(PreprocessorSwitch)UNICODE $(PreprocessorSwitch)_UNICODE $(PreprocessorSwitch)__WX__ $(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -Wall -O3 -fno-strict-aliasing `wx-config --debug=no --cflags`  $(Preprocessors)
C_CmpOptions           := -Wall -O3 -fno-strict-aliasing `wx-config --debug=no --cflags`  $(Preprocessors)
LinkOptions            :=  -s -Wl,-rpath,$$``ORIGIN/lib/ `wx-config --libs` 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)controls/include $(IncludeSwitch). 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)wx_gtk2u_propgrid-2.8_cd $(LibrarySwitch)wx_gtk2u_scintilla-2.8_cd $(LibrarySwitch)wx_gtk2u_shapeframework-2.8_cd $(LibrarySwitch)wxcode_gtk2_databaselayer_mysql-2.8 $(LibrarySwitch)wxcode_gtk2_databaselayer_sqlite-2.8 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../bin/gcc $(LibraryPathSwitch)../bin/gcc/lib $(LibraryPathSwitch)../bin/gcc/lib $(LibraryPathSwitch)../bin/gcc/lib 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/DbEngine_database$(ObjectSuffix) $(IntermediateDirectory)/DbEngine_column$(ObjectSuffix) $(IntermediateDirectory)/DbEngine_dbitem$(ObjectSuffix) $(IntermediateDirectory)/DbEngine_dbconnection$(ObjectSuffix) $(IntermediateDirectory)/DbEngine_table$(ObjectSuffix) $(IntermediateDirectory)/DbEngine_tablecol$(ObjectSuffix) $(IntermediateDirectory)/DbEngine_constraint$(ObjectSuffix) $(IntermediateDirectory)/ErdEngine_FrameCanvas$(ObjectSuffix) $(IntermediateDirectory)/ErdEngine_DnDTableShape$(ObjectSuffix) $(IntermediateDirectory)/ErdEngine_ErdTable$(ObjectSuffix) \
	$(IntermediateDirectory)/Gui_TableSettingsDialog$(ObjectSuffix) $(IntermediateDirectory)/Gui_DbSettingDialog$(ObjectSuffix) $(IntermediateDirectory)/Gui_ErdPanel$(ObjectSuffix) $(IntermediateDirectory)/Gui_MysqlConnectionHistory$(ObjectSuffix) $(IntermediateDirectory)/Gui_SqlCommandPanel$(ObjectSuffix) $(IntermediateDirectory)/Gui_DbViewerPanel$(ObjectSuffix) $(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(ObjectSuffix) $(IntermediateDirectory)/Gui_GUI$(ObjectSuffix) $(IntermediateDirectory)/Gui_AdapterSelectDlg$(ObjectSuffix) $(IntermediateDirectory)/Interfaces_IDbItem$(ObjectSuffix) \
	$(IntermediateDirectory)/Main_DatabaseExplorerApp$(ObjectSuffix) $(IntermediateDirectory)/Main_MySqlType$(ObjectSuffix) $(IntermediateDirectory)/Main_MySqlDbAdapter$(ObjectSuffix) $(IntermediateDirectory)/Main_SqliteDbAdapter$(ObjectSuffix) $(IntermediateDirectory)/Main_wx_pch$(ObjectSuffix) $(IntermediateDirectory)/SqliteType$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d .objsu || $(MakeDirCommand) .objsu

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/DbEngine_database$(ObjectSuffix): DbEngine/database.cpp $(IntermediateDirectory)/DbEngine_database$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/database.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbEngine_database$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbEngine_database$(DependSuffix): DbEngine/database.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbEngine_database$(ObjectSuffix) -MF$(IntermediateDirectory)/DbEngine_database$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/database.cpp"

$(IntermediateDirectory)/DbEngine_database$(PreprocessSuffix): DbEngine/database.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbEngine_database$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/database.cpp"

$(IntermediateDirectory)/DbEngine_column$(ObjectSuffix): DbEngine/column.cpp $(IntermediateDirectory)/DbEngine_column$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/column.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbEngine_column$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbEngine_column$(DependSuffix): DbEngine/column.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbEngine_column$(ObjectSuffix) -MF$(IntermediateDirectory)/DbEngine_column$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/column.cpp"

$(IntermediateDirectory)/DbEngine_column$(PreprocessSuffix): DbEngine/column.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbEngine_column$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/column.cpp"

$(IntermediateDirectory)/DbEngine_dbitem$(ObjectSuffix): DbEngine/dbitem.cpp $(IntermediateDirectory)/DbEngine_dbitem$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/dbitem.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbEngine_dbitem$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbEngine_dbitem$(DependSuffix): DbEngine/dbitem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbEngine_dbitem$(ObjectSuffix) -MF$(IntermediateDirectory)/DbEngine_dbitem$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/dbitem.cpp"

$(IntermediateDirectory)/DbEngine_dbitem$(PreprocessSuffix): DbEngine/dbitem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbEngine_dbitem$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/dbitem.cpp"

$(IntermediateDirectory)/DbEngine_dbconnection$(ObjectSuffix): DbEngine/dbconnection.cpp $(IntermediateDirectory)/DbEngine_dbconnection$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/dbconnection.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbEngine_dbconnection$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbEngine_dbconnection$(DependSuffix): DbEngine/dbconnection.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbEngine_dbconnection$(ObjectSuffix) -MF$(IntermediateDirectory)/DbEngine_dbconnection$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/dbconnection.cpp"

$(IntermediateDirectory)/DbEngine_dbconnection$(PreprocessSuffix): DbEngine/dbconnection.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbEngine_dbconnection$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/dbconnection.cpp"

$(IntermediateDirectory)/DbEngine_table$(ObjectSuffix): DbEngine/table.cpp $(IntermediateDirectory)/DbEngine_table$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/table.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbEngine_table$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbEngine_table$(DependSuffix): DbEngine/table.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbEngine_table$(ObjectSuffix) -MF$(IntermediateDirectory)/DbEngine_table$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/table.cpp"

$(IntermediateDirectory)/DbEngine_table$(PreprocessSuffix): DbEngine/table.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbEngine_table$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/table.cpp"

$(IntermediateDirectory)/DbEngine_tablecol$(ObjectSuffix): DbEngine/tablecol.cpp $(IntermediateDirectory)/DbEngine_tablecol$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/tablecol.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbEngine_tablecol$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbEngine_tablecol$(DependSuffix): DbEngine/tablecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbEngine_tablecol$(ObjectSuffix) -MF$(IntermediateDirectory)/DbEngine_tablecol$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/tablecol.cpp"

$(IntermediateDirectory)/DbEngine_tablecol$(PreprocessSuffix): DbEngine/tablecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbEngine_tablecol$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/tablecol.cpp"

$(IntermediateDirectory)/DbEngine_constraint$(ObjectSuffix): DbEngine/constraint.cpp $(IntermediateDirectory)/DbEngine_constraint$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/constraint.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbEngine_constraint$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbEngine_constraint$(DependSuffix): DbEngine/constraint.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbEngine_constraint$(ObjectSuffix) -MF$(IntermediateDirectory)/DbEngine_constraint$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/constraint.cpp"

$(IntermediateDirectory)/DbEngine_constraint$(PreprocessSuffix): DbEngine/constraint.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbEngine_constraint$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/DbEngine/constraint.cpp"

$(IntermediateDirectory)/ErdEngine_FrameCanvas$(ObjectSuffix): ErdEngine/FrameCanvas.cpp $(IntermediateDirectory)/ErdEngine_FrameCanvas$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/FrameCanvas.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ErdEngine_FrameCanvas$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ErdEngine_FrameCanvas$(DependSuffix): ErdEngine/FrameCanvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ErdEngine_FrameCanvas$(ObjectSuffix) -MF$(IntermediateDirectory)/ErdEngine_FrameCanvas$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/FrameCanvas.cpp"

$(IntermediateDirectory)/ErdEngine_FrameCanvas$(PreprocessSuffix): ErdEngine/FrameCanvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ErdEngine_FrameCanvas$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/FrameCanvas.cpp"

$(IntermediateDirectory)/ErdEngine_DnDTableShape$(ObjectSuffix): ErdEngine/DnDTableShape.cpp $(IntermediateDirectory)/ErdEngine_DnDTableShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/DnDTableShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ErdEngine_DnDTableShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ErdEngine_DnDTableShape$(DependSuffix): ErdEngine/DnDTableShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ErdEngine_DnDTableShape$(ObjectSuffix) -MF$(IntermediateDirectory)/ErdEngine_DnDTableShape$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/DnDTableShape.cpp"

$(IntermediateDirectory)/ErdEngine_DnDTableShape$(PreprocessSuffix): ErdEngine/DnDTableShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ErdEngine_DnDTableShape$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/DnDTableShape.cpp"

$(IntermediateDirectory)/ErdEngine_ErdTable$(ObjectSuffix): ErdEngine/ErdTable.cpp $(IntermediateDirectory)/ErdEngine_ErdTable$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/ErdTable.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ErdEngine_ErdTable$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ErdEngine_ErdTable$(DependSuffix): ErdEngine/ErdTable.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ErdEngine_ErdTable$(ObjectSuffix) -MF$(IntermediateDirectory)/ErdEngine_ErdTable$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/ErdTable.cpp"

$(IntermediateDirectory)/ErdEngine_ErdTable$(PreprocessSuffix): ErdEngine/ErdTable.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ErdEngine_ErdTable$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/ErdEngine/ErdTable.cpp"

$(IntermediateDirectory)/Gui_TableSettingsDialog$(ObjectSuffix): Gui/TableSettingsDialog.cpp $(IntermediateDirectory)/Gui_TableSettingsDialog$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/TableSettingsDialog.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_TableSettingsDialog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_TableSettingsDialog$(DependSuffix): Gui/TableSettingsDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_TableSettingsDialog$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_TableSettingsDialog$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/TableSettingsDialog.cpp"

$(IntermediateDirectory)/Gui_TableSettingsDialog$(PreprocessSuffix): Gui/TableSettingsDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_TableSettingsDialog$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/TableSettingsDialog.cpp"

$(IntermediateDirectory)/Gui_DbSettingDialog$(ObjectSuffix): Gui/DbSettingDialog.cpp $(IntermediateDirectory)/Gui_DbSettingDialog$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DbSettingDialog.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_DbSettingDialog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_DbSettingDialog$(DependSuffix): Gui/DbSettingDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_DbSettingDialog$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_DbSettingDialog$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DbSettingDialog.cpp"

$(IntermediateDirectory)/Gui_DbSettingDialog$(PreprocessSuffix): Gui/DbSettingDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_DbSettingDialog$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DbSettingDialog.cpp"

$(IntermediateDirectory)/Gui_ErdPanel$(ObjectSuffix): Gui/ErdPanel.cpp $(IntermediateDirectory)/Gui_ErdPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/ErdPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_ErdPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_ErdPanel$(DependSuffix): Gui/ErdPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_ErdPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_ErdPanel$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/ErdPanel.cpp"

$(IntermediateDirectory)/Gui_ErdPanel$(PreprocessSuffix): Gui/ErdPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_ErdPanel$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/ErdPanel.cpp"

$(IntermediateDirectory)/Gui_MysqlConnectionHistory$(ObjectSuffix): Gui/MysqlConnectionHistory.cpp $(IntermediateDirectory)/Gui_MysqlConnectionHistory$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/MysqlConnectionHistory.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_MysqlConnectionHistory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_MysqlConnectionHistory$(DependSuffix): Gui/MysqlConnectionHistory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_MysqlConnectionHistory$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_MysqlConnectionHistory$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/MysqlConnectionHistory.cpp"

$(IntermediateDirectory)/Gui_MysqlConnectionHistory$(PreprocessSuffix): Gui/MysqlConnectionHistory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_MysqlConnectionHistory$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/MysqlConnectionHistory.cpp"

$(IntermediateDirectory)/Gui_SqlCommandPanel$(ObjectSuffix): Gui/SqlCommandPanel.cpp $(IntermediateDirectory)/Gui_SqlCommandPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/SqlCommandPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_SqlCommandPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_SqlCommandPanel$(DependSuffix): Gui/SqlCommandPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_SqlCommandPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_SqlCommandPanel$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/SqlCommandPanel.cpp"

$(IntermediateDirectory)/Gui_SqlCommandPanel$(PreprocessSuffix): Gui/SqlCommandPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_SqlCommandPanel$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/SqlCommandPanel.cpp"

$(IntermediateDirectory)/Gui_DbViewerPanel$(ObjectSuffix): Gui/DbViewerPanel.cpp $(IntermediateDirectory)/Gui_DbViewerPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DbViewerPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_DbViewerPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_DbViewerPanel$(DependSuffix): Gui/DbViewerPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_DbViewerPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_DbViewerPanel$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DbViewerPanel.cpp"

$(IntermediateDirectory)/Gui_DbViewerPanel$(PreprocessSuffix): Gui/DbViewerPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_DbViewerPanel$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DbViewerPanel.cpp"

$(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(ObjectSuffix): Gui/DatabaseExplorerFrame.cpp $(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DatabaseExplorerFrame.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(DependSuffix): Gui/DatabaseExplorerFrame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DatabaseExplorerFrame.cpp"

$(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(PreprocessSuffix): Gui/DatabaseExplorerFrame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/DatabaseExplorerFrame.cpp"

$(IntermediateDirectory)/Gui_GUI$(ObjectSuffix): Gui/GUI.cpp $(IntermediateDirectory)/Gui_GUI$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/GUI.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_GUI$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_GUI$(DependSuffix): Gui/GUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_GUI$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_GUI$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/GUI.cpp"

$(IntermediateDirectory)/Gui_GUI$(PreprocessSuffix): Gui/GUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_GUI$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/GUI.cpp"

$(IntermediateDirectory)/Gui_AdapterSelectDlg$(ObjectSuffix): Gui/AdapterSelectDlg.cpp $(IntermediateDirectory)/Gui_AdapterSelectDlg$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/AdapterSelectDlg.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Gui_AdapterSelectDlg$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gui_AdapterSelectDlg$(DependSuffix): Gui/AdapterSelectDlg.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Gui_AdapterSelectDlg$(ObjectSuffix) -MF$(IntermediateDirectory)/Gui_AdapterSelectDlg$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/AdapterSelectDlg.cpp"

$(IntermediateDirectory)/Gui_AdapterSelectDlg$(PreprocessSuffix): Gui/AdapterSelectDlg.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gui_AdapterSelectDlg$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Gui/AdapterSelectDlg.cpp"

$(IntermediateDirectory)/Interfaces_IDbItem$(ObjectSuffix): Interfaces/IDbItem.cpp $(IntermediateDirectory)/Interfaces_IDbItem$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Interfaces/IDbItem.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Interfaces_IDbItem$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Interfaces_IDbItem$(DependSuffix): Interfaces/IDbItem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Interfaces_IDbItem$(ObjectSuffix) -MF$(IntermediateDirectory)/Interfaces_IDbItem$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Interfaces/IDbItem.cpp"

$(IntermediateDirectory)/Interfaces_IDbItem$(PreprocessSuffix): Interfaces/IDbItem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Interfaces_IDbItem$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Interfaces/IDbItem.cpp"

$(IntermediateDirectory)/Main_DatabaseExplorerApp$(ObjectSuffix): Main/DatabaseExplorerApp.cpp $(IntermediateDirectory)/Main_DatabaseExplorerApp$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/DatabaseExplorerApp.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Main_DatabaseExplorerApp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Main_DatabaseExplorerApp$(DependSuffix): Main/DatabaseExplorerApp.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Main_DatabaseExplorerApp$(ObjectSuffix) -MF$(IntermediateDirectory)/Main_DatabaseExplorerApp$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/DatabaseExplorerApp.cpp"

$(IntermediateDirectory)/Main_DatabaseExplorerApp$(PreprocessSuffix): Main/DatabaseExplorerApp.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Main_DatabaseExplorerApp$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/DatabaseExplorerApp.cpp"

$(IntermediateDirectory)/Main_MySqlType$(ObjectSuffix): Main/MySqlType.cpp $(IntermediateDirectory)/Main_MySqlType$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/MySqlType.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Main_MySqlType$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Main_MySqlType$(DependSuffix): Main/MySqlType.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Main_MySqlType$(ObjectSuffix) -MF$(IntermediateDirectory)/Main_MySqlType$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/MySqlType.cpp"

$(IntermediateDirectory)/Main_MySqlType$(PreprocessSuffix): Main/MySqlType.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Main_MySqlType$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/MySqlType.cpp"

$(IntermediateDirectory)/Main_MySqlDbAdapter$(ObjectSuffix): Main/MySqlDbAdapter.cpp $(IntermediateDirectory)/Main_MySqlDbAdapter$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/MySqlDbAdapter.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Main_MySqlDbAdapter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Main_MySqlDbAdapter$(DependSuffix): Main/MySqlDbAdapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Main_MySqlDbAdapter$(ObjectSuffix) -MF$(IntermediateDirectory)/Main_MySqlDbAdapter$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/MySqlDbAdapter.cpp"

$(IntermediateDirectory)/Main_MySqlDbAdapter$(PreprocessSuffix): Main/MySqlDbAdapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Main_MySqlDbAdapter$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/MySqlDbAdapter.cpp"

$(IntermediateDirectory)/Main_SqliteDbAdapter$(ObjectSuffix): Main/SqliteDbAdapter.cpp $(IntermediateDirectory)/Main_SqliteDbAdapter$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/SqliteDbAdapter.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Main_SqliteDbAdapter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Main_SqliteDbAdapter$(DependSuffix): Main/SqliteDbAdapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Main_SqliteDbAdapter$(ObjectSuffix) -MF$(IntermediateDirectory)/Main_SqliteDbAdapter$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/SqliteDbAdapter.cpp"

$(IntermediateDirectory)/Main_SqliteDbAdapter$(PreprocessSuffix): Main/SqliteDbAdapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Main_SqliteDbAdapter$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/SqliteDbAdapter.cpp"

$(IntermediateDirectory)/Main_wx_pch$(ObjectSuffix): Main/wx_pch.cpp $(IntermediateDirectory)/Main_wx_pch$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/wx_pch.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Main_wx_pch$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Main_wx_pch$(DependSuffix): Main/wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Main_wx_pch$(ObjectSuffix) -MF$(IntermediateDirectory)/Main_wx_pch$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/wx_pch.cpp"

$(IntermediateDirectory)/Main_wx_pch$(PreprocessSuffix): Main/wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Main_wx_pch$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/Main/wx_pch.cpp"

$(IntermediateDirectory)/SqliteType$(ObjectSuffix): SqliteType.cpp $(IntermediateDirectory)/SqliteType$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourcesCpp/wxdbexplorer/src/SqliteType.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/SqliteType$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SqliteType$(DependSuffix): SqliteType.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SqliteType$(ObjectSuffix) -MF$(IntermediateDirectory)/SqliteType$(DependSuffix) -MM "/home/jankup/SourcesCpp/wxdbexplorer/src/SqliteType.cpp"

$(IntermediateDirectory)/SqliteType$(PreprocessSuffix): SqliteType.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SqliteType$(PreprocessSuffix) "/home/jankup/SourcesCpp/wxdbexplorer/src/SqliteType.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/DbEngine_database$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_database$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_database$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_column$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_column$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_column$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_dbitem$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_dbitem$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_dbitem$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_dbconnection$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_dbconnection$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_dbconnection$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_table$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_table$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_table$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_tablecol$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_tablecol$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_tablecol$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_constraint$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_constraint$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbEngine_constraint$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_FrameCanvas$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_FrameCanvas$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_FrameCanvas$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_DnDTableShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_DnDTableShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_DnDTableShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_ErdTable$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_ErdTable$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ErdEngine_ErdTable$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_TableSettingsDialog$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_TableSettingsDialog$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_TableSettingsDialog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DbSettingDialog$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DbSettingDialog$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DbSettingDialog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_ErdPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_ErdPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_ErdPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_MysqlConnectionHistory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_MysqlConnectionHistory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_MysqlConnectionHistory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_SqlCommandPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_SqlCommandPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_SqlCommandPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DbViewerPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DbViewerPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DbViewerPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_DatabaseExplorerFrame$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_GUI$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_GUI$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_GUI$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Gui_AdapterSelectDlg$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Gui_AdapterSelectDlg$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Gui_AdapterSelectDlg$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Interfaces_IDbItem$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Interfaces_IDbItem$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Interfaces_IDbItem$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Main_DatabaseExplorerApp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Main_DatabaseExplorerApp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Main_DatabaseExplorerApp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Main_MySqlType$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Main_MySqlType$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Main_MySqlType$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Main_MySqlDbAdapter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Main_MySqlDbAdapter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Main_MySqlDbAdapter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Main_SqliteDbAdapter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Main_SqliteDbAdapter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Main_SqliteDbAdapter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Main_wx_pch$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Main_wx_pch$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Main_wx_pch$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/SqliteType$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/SqliteType$(DependSuffix)
	$(RM) $(IntermediateDirectory)/SqliteType$(PreprocessSuffix)
	$(RM) $(OutputFile)


