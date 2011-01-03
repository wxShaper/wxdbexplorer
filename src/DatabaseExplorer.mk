##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=DatabaseExplorer
ConfigurationName      :=Release
IntermediateDirectory  :=.objsu
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/jankup/SourceCpp/wxdbexplorer/trunk/build"
ProjectPath            := "/home/jankup/SourceCpp/wxdbexplorer/trunk/src"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Peter Janků
Date                   :=3.1.2011
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
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)controls/include" "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)wx_gtk2u_propgrid-2.8_cd $(LibrarySwitch)wx_gtk2u_scintilla-2.8_cd $(LibrarySwitch)wx_gtk2u_shapeframework-2.8_cd $(LibrarySwitch)wxcode_gtk2_databaselayer_mysql-2.8 $(LibrarySwitch)wxcode_gtk2_databaselayer_sqlite-2.8 
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../bin/gcc" "$(LibraryPathSwitch)../bin/gcc/lib" "$(LibraryPathSwitch)../bin/gcc/lib" "$(LibraryPathSwitch)../bin/gcc/lib" 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix) $(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix) $(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix) $(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix) $(IntermediateDirectory)/gui_GUI$(ObjectSuffix) $(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix) $(IntermediateDirectory)/IDbItem$(ObjectSuffix) $(IntermediateDirectory)/column$(ObjectSuffix) $(IntermediateDirectory)/columncol$(ObjectSuffix) $(IntermediateDirectory)/tablecol$(ObjectSuffix) \
	$(IntermediateDirectory)/table$(ObjectSuffix) $(IntermediateDirectory)/DbDatabase$(ObjectSuffix) $(IntermediateDirectory)/DbColumn$(ObjectSuffix) $(IntermediateDirectory)/database$(ObjectSuffix) $(IntermediateDirectory)/databasecol$(ObjectSuffix) $(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix) $(IntermediateDirectory)/DbTable$(ObjectSuffix) $(IntermediateDirectory)/SqliteDbConnector$(ObjectSuffix) $(IntermediateDirectory)/MySqlDbConnector$(ObjectSuffix) $(IntermediateDirectory)/dbitem$(ObjectSuffix) \
	$(IntermediateDirectory)/mysqldbadapter$(ObjectSuffix) $(IntermediateDirectory)/wx_pch$(ObjectSuffix) $(IntermediateDirectory)/frame_canvas$(ObjectSuffix) $(IntermediateDirectory)/erd_table$(ObjectSuffix) 

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
$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix): gui/DatabaseExplorerFrame.cpp $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DatabaseExplorerFrame.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(DependSuffix): gui/DatabaseExplorerFrame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DatabaseExplorerFrame.cpp"

$(IntermediateDirectory)/gui_DatabaseExplorerFrame$(PreprocessSuffix): gui/DatabaseExplorerFrame.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DatabaseExplorerFrame.cpp"

$(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix): gui/DbSettingDialog.cpp $(IntermediateDirectory)/gui_DbSettingDialog$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DbSettingDialog.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DbSettingDialog$(DependSuffix): gui/DbSettingDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DbSettingDialog$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DbSettingDialog.cpp"

$(IntermediateDirectory)/gui_DbSettingDialog$(PreprocessSuffix): gui/DbSettingDialog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DbSettingDialog$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DbSettingDialog.cpp"

$(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix): gui/DbViewerPanel.cpp $(IntermediateDirectory)/gui_DbViewerPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DbViewerPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DbViewerPanel$(DependSuffix): gui/DbViewerPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DbViewerPanel$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DbViewerPanel.cpp"

$(IntermediateDirectory)/gui_DbViewerPanel$(PreprocessSuffix): gui/DbViewerPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DbViewerPanel$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/DbViewerPanel.cpp"

$(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix): gui/ErdPanel.cpp $(IntermediateDirectory)/gui_ErdPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/ErdPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_ErdPanel$(DependSuffix): gui/ErdPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_ErdPanel$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/ErdPanel.cpp"

$(IntermediateDirectory)/gui_ErdPanel$(PreprocessSuffix): gui/ErdPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_ErdPanel$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/ErdPanel.cpp"

$(IntermediateDirectory)/gui_GUI$(ObjectSuffix): gui/GUI.cpp $(IntermediateDirectory)/gui_GUI$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/GUI.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_GUI$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_GUI$(DependSuffix): gui/GUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_GUI$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_GUI$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/GUI.cpp"

$(IntermediateDirectory)/gui_GUI$(PreprocessSuffix): gui/GUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_GUI$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/GUI.cpp"

$(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix): gui/SqlCommandPanel.cpp $(IntermediateDirectory)/gui_SqlCommandPanel$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/SqlCommandPanel.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_SqlCommandPanel$(DependSuffix): gui/SqlCommandPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_SqlCommandPanel$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/SqlCommandPanel.cpp"

$(IntermediateDirectory)/gui_SqlCommandPanel$(PreprocessSuffix): gui/SqlCommandPanel.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_SqlCommandPanel$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/gui/SqlCommandPanel.cpp"

$(IntermediateDirectory)/IDbItem$(ObjectSuffix): IDbItem.cpp $(IntermediateDirectory)/IDbItem$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/IDbItem.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/IDbItem$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IDbItem$(DependSuffix): IDbItem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IDbItem$(ObjectSuffix) -MF$(IntermediateDirectory)/IDbItem$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/IDbItem.cpp"

$(IntermediateDirectory)/IDbItem$(PreprocessSuffix): IDbItem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IDbItem$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/IDbItem.cpp"

$(IntermediateDirectory)/column$(ObjectSuffix): column.cpp $(IntermediateDirectory)/column$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/column.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/column$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/column$(DependSuffix): column.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/column$(ObjectSuffix) -MF$(IntermediateDirectory)/column$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/column.cpp"

$(IntermediateDirectory)/column$(PreprocessSuffix): column.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/column$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/column.cpp"

$(IntermediateDirectory)/columncol$(ObjectSuffix): columncol.cpp $(IntermediateDirectory)/columncol$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/columncol.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/columncol$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/columncol$(DependSuffix): columncol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/columncol$(ObjectSuffix) -MF$(IntermediateDirectory)/columncol$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/columncol.cpp"

$(IntermediateDirectory)/columncol$(PreprocessSuffix): columncol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/columncol$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/columncol.cpp"

$(IntermediateDirectory)/tablecol$(ObjectSuffix): tablecol.cpp $(IntermediateDirectory)/tablecol$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/tablecol.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/tablecol$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tablecol$(DependSuffix): tablecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tablecol$(ObjectSuffix) -MF$(IntermediateDirectory)/tablecol$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/tablecol.cpp"

$(IntermediateDirectory)/tablecol$(PreprocessSuffix): tablecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tablecol$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/tablecol.cpp"

$(IntermediateDirectory)/table$(ObjectSuffix): table.cpp $(IntermediateDirectory)/table$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/table.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/table$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/table$(DependSuffix): table.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/table$(ObjectSuffix) -MF$(IntermediateDirectory)/table$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/table.cpp"

$(IntermediateDirectory)/table$(PreprocessSuffix): table.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/table$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/table.cpp"

$(IntermediateDirectory)/DbDatabase$(ObjectSuffix): DbDatabase.cpp $(IntermediateDirectory)/DbDatabase$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbDatabase.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbDatabase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbDatabase$(DependSuffix): DbDatabase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbDatabase$(ObjectSuffix) -MF$(IntermediateDirectory)/DbDatabase$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbDatabase.cpp"

$(IntermediateDirectory)/DbDatabase$(PreprocessSuffix): DbDatabase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbDatabase$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbDatabase.cpp"

$(IntermediateDirectory)/DbColumn$(ObjectSuffix): DbColumn.cpp $(IntermediateDirectory)/DbColumn$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbColumn.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbColumn$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbColumn$(DependSuffix): DbColumn.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbColumn$(ObjectSuffix) -MF$(IntermediateDirectory)/DbColumn$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbColumn.cpp"

$(IntermediateDirectory)/DbColumn$(PreprocessSuffix): DbColumn.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbColumn$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbColumn.cpp"

$(IntermediateDirectory)/database$(ObjectSuffix): database.cpp $(IntermediateDirectory)/database$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/database.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/database$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/database$(DependSuffix): database.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/database$(ObjectSuffix) -MF$(IntermediateDirectory)/database$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/database.cpp"

$(IntermediateDirectory)/database$(PreprocessSuffix): database.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/database$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/database.cpp"

$(IntermediateDirectory)/databasecol$(ObjectSuffix): databasecol.cpp $(IntermediateDirectory)/databasecol$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/databasecol.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/databasecol$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/databasecol$(DependSuffix): databasecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/databasecol$(ObjectSuffix) -MF$(IntermediateDirectory)/databasecol$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/databasecol.cpp"

$(IntermediateDirectory)/databasecol$(PreprocessSuffix): databasecol.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/databasecol$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/databasecol.cpp"

$(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix): DatabaseExplorerApp.cpp $(IntermediateDirectory)/DatabaseExplorerApp$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DatabaseExplorerApp.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DatabaseExplorerApp$(DependSuffix): DatabaseExplorerApp.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix) -MF$(IntermediateDirectory)/DatabaseExplorerApp$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DatabaseExplorerApp.cpp"

$(IntermediateDirectory)/DatabaseExplorerApp$(PreprocessSuffix): DatabaseExplorerApp.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DatabaseExplorerApp$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DatabaseExplorerApp.cpp"

$(IntermediateDirectory)/DbTable$(ObjectSuffix): DbTable.cpp $(IntermediateDirectory)/DbTable$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbTable.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DbTable$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DbTable$(DependSuffix): DbTable.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DbTable$(ObjectSuffix) -MF$(IntermediateDirectory)/DbTable$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbTable.cpp"

$(IntermediateDirectory)/DbTable$(PreprocessSuffix): DbTable.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DbTable$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/DbTable.cpp"

$(IntermediateDirectory)/SqliteDbConnector$(ObjectSuffix): SqliteDbConnector.cpp $(IntermediateDirectory)/SqliteDbConnector$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/SqliteDbConnector.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/SqliteDbConnector$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SqliteDbConnector$(DependSuffix): SqliteDbConnector.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SqliteDbConnector$(ObjectSuffix) -MF$(IntermediateDirectory)/SqliteDbConnector$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/SqliteDbConnector.cpp"

$(IntermediateDirectory)/SqliteDbConnector$(PreprocessSuffix): SqliteDbConnector.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SqliteDbConnector$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/SqliteDbConnector.cpp"

$(IntermediateDirectory)/MySqlDbConnector$(ObjectSuffix): MySqlDbConnector.cpp $(IntermediateDirectory)/MySqlDbConnector$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/MySqlDbConnector.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/MySqlDbConnector$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MySqlDbConnector$(DependSuffix): MySqlDbConnector.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MySqlDbConnector$(ObjectSuffix) -MF$(IntermediateDirectory)/MySqlDbConnector$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/MySqlDbConnector.cpp"

$(IntermediateDirectory)/MySqlDbConnector$(PreprocessSuffix): MySqlDbConnector.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MySqlDbConnector$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/MySqlDbConnector.cpp"

$(IntermediateDirectory)/dbitem$(ObjectSuffix): dbitem.cpp $(IntermediateDirectory)/dbitem$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/dbitem.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/dbitem$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/dbitem$(DependSuffix): dbitem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/dbitem$(ObjectSuffix) -MF$(IntermediateDirectory)/dbitem$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/dbitem.cpp"

$(IntermediateDirectory)/dbitem$(PreprocessSuffix): dbitem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/dbitem$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/dbitem.cpp"

$(IntermediateDirectory)/mysqldbadapter$(ObjectSuffix): mysqldbadapter.cpp $(IntermediateDirectory)/mysqldbadapter$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/mysqldbadapter.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/mysqldbadapter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mysqldbadapter$(DependSuffix): mysqldbadapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mysqldbadapter$(ObjectSuffix) -MF$(IntermediateDirectory)/mysqldbadapter$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/mysqldbadapter.cpp"

$(IntermediateDirectory)/mysqldbadapter$(PreprocessSuffix): mysqldbadapter.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mysqldbadapter$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/mysqldbadapter.cpp"

$(IntermediateDirectory)/wx_pch$(ObjectSuffix): wx_pch.cpp $(IntermediateDirectory)/wx_pch$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/wx_pch.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wx_pch$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wx_pch$(DependSuffix): wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wx_pch$(ObjectSuffix) -MF$(IntermediateDirectory)/wx_pch$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/wx_pch.cpp"

$(IntermediateDirectory)/wx_pch$(PreprocessSuffix): wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wx_pch$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/wx_pch.cpp"

$(IntermediateDirectory)/frame_canvas$(ObjectSuffix): frame_canvas.cpp $(IntermediateDirectory)/frame_canvas$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/frame_canvas.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/frame_canvas$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/frame_canvas$(DependSuffix): frame_canvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/frame_canvas$(ObjectSuffix) -MF$(IntermediateDirectory)/frame_canvas$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/frame_canvas.cpp"

$(IntermediateDirectory)/frame_canvas$(PreprocessSuffix): frame_canvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/frame_canvas$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/frame_canvas.cpp"

$(IntermediateDirectory)/erd_table$(ObjectSuffix): erd_table.cpp $(IntermediateDirectory)/erd_table$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/erd_table.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/erd_table$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/erd_table$(DependSuffix): erd_table.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/erd_table$(ObjectSuffix) -MF$(IntermediateDirectory)/erd_table$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/erd_table.cpp"

$(IntermediateDirectory)/erd_table$(PreprocessSuffix): erd_table.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/erd_table$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/erd_table.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DatabaseExplorerFrame$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbSettingDialog$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbSettingDialog$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbSettingDialog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbViewerPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbViewerPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DbViewerPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_ErdPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_ErdPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_ErdPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_GUI$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_GUI$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_GUI$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_SqlCommandPanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_SqlCommandPanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_SqlCommandPanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/IDbItem$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/IDbItem$(DependSuffix)
	$(RM) $(IntermediateDirectory)/IDbItem$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/column$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/column$(DependSuffix)
	$(RM) $(IntermediateDirectory)/column$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/columncol$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/columncol$(DependSuffix)
	$(RM) $(IntermediateDirectory)/columncol$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tablecol$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tablecol$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tablecol$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/table$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/table$(DependSuffix)
	$(RM) $(IntermediateDirectory)/table$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbDatabase$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbDatabase$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbDatabase$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbColumn$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbColumn$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbColumn$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/database$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/database$(DependSuffix)
	$(RM) $(IntermediateDirectory)/database$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/databasecol$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/databasecol$(DependSuffix)
	$(RM) $(IntermediateDirectory)/databasecol$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DatabaseExplorerApp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DatabaseExplorerApp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DatabaseExplorerApp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DbTable$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DbTable$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DbTable$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/SqliteDbConnector$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/SqliteDbConnector$(DependSuffix)
	$(RM) $(IntermediateDirectory)/SqliteDbConnector$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MySqlDbConnector$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MySqlDbConnector$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MySqlDbConnector$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/dbitem$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/dbitem$(DependSuffix)
	$(RM) $(IntermediateDirectory)/dbitem$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/mysqldbadapter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/mysqldbadapter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/mysqldbadapter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/frame_canvas$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/frame_canvas$(DependSuffix)
	$(RM) $(IntermediateDirectory)/frame_canvas$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/erd_table$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/erd_table$(DependSuffix)
	$(RM) $(IntermediateDirectory)/erd_table$(PreprocessSuffix)
	$(RM) $(OutputFile)


