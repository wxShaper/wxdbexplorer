##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=wxShapeFramework
ConfigurationName      :=Release
IntermediateDirectory  :=.objsu
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/jankup/SourceCpp/wxdbexplorer/trunk/build"
ProjectPath            := "/home/jankup/SourceCpp/wxdbexplorer/trunk/build/wxShapeFramework"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Peter Janků
Date                   :=12.1.2011
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
OutputFile             :=../../bin/gcc/lib/libwx_gtk2u_shapeframework-2.8_cd.so
Preprocessors          :=$(PreprocessorSwitch)WXMAKINGDLL_WXSF $(PreprocessorSwitch)WXMAKINGDLL_WXXS $(PreprocessorSwitch)MONOLITHIC $(PreprocessorSwitch)WXUSINGDLL $(PreprocessorSwitch)UNICODE $(PreprocessorSwitch)_UNICODE $(PreprocessorSwitch)__WX__ $(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -Wall -O3 -fPIC -fno-strict-aliasing `wx-config --debug=no --cflags`  $(Preprocessors)
C_CmpOptions           := -Wall -O3 -fPIC -fno-strict-aliasing `wx-config --debug=no --cflags`  $(Preprocessors)
LinkOptions            :=  -s `wx-config --libs` 
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../../src/controls/include" "$(IncludeSwitch)../../src/controls/src/wxShapeFramework" 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../../bin/gcc/lib" "$(LibraryPathSwitch)../../bin/gcc" 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix) $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_CanvasState$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_SolidArrow$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ControlShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_CircleShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(ObjectSuffix) \
	$(IntermediateDirectory)/wxShapeFramework_RectShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ScaledDC$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_OpenArrow$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_SFEvents$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_Printout$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_PolygonShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ArrowBase$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_OrthoShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_GridShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(ObjectSuffix) \
	$(IntermediateDirectory)/wxShapeFramework_AutoLayout$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_EditTextShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_Thumbnail$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_CurveShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_DiamondShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ShapeBase$(ObjectSuffix) \
	$(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_BitmapShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_LineShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_CommonFcn$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_TextShape$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_DiagramManager$(ObjectSuffix) \
	$(IntermediateDirectory)/wxShapeFramework_wx_pch$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_CircleArrow$(ObjectSuffix) $(IntermediateDirectory)/wxShapeFramework_EllipseShape$(ObjectSuffix) 

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
$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/wxxmlserializer/XmlSerializer.cpp $(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wxxmlserializer/XmlSerializer.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(DependSuffix): ../../src/controls/src/wxShapeFramework/wxxmlserializer/XmlSerializer.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix) -MF$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wxxmlserializer/XmlSerializer.cpp"

$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/wxxmlserializer/XmlSerializer.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wxxmlserializer/XmlSerializer.cpp"

$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/wxxmlserializer/PropertyIO.cpp $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wxxmlserializer/PropertyIO.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(DependSuffix): ../../src/controls/src/wxShapeFramework/wxxmlserializer/PropertyIO.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix) -MF$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wxxmlserializer/PropertyIO.cpp"

$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/wxxmlserializer/PropertyIO.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wxxmlserializer/PropertyIO.cpp"

$(IntermediateDirectory)/wxShapeFramework_CanvasState$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/CanvasState.cpp $(IntermediateDirectory)/wxShapeFramework_CanvasState$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CanvasState.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_CanvasState$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_CanvasState$(DependSuffix): ../../src/controls/src/wxShapeFramework/CanvasState.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_CanvasState$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_CanvasState$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CanvasState.cpp"

$(IntermediateDirectory)/wxShapeFramework_CanvasState$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/CanvasState.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_CanvasState$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CanvasState.cpp"

$(IntermediateDirectory)/wxShapeFramework_SolidArrow$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/SolidArrow.cpp $(IntermediateDirectory)/wxShapeFramework_SolidArrow$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/SolidArrow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_SolidArrow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_SolidArrow$(DependSuffix): ../../src/controls/src/wxShapeFramework/SolidArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_SolidArrow$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_SolidArrow$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/SolidArrow.cpp"

$(IntermediateDirectory)/wxShapeFramework_SolidArrow$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/SolidArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_SolidArrow$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/SolidArrow.cpp"

$(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/RoundRectShape.cpp $(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/RoundRectShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/RoundRectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/RoundRectShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/RoundRectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/RoundRectShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_ControlShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ControlShape.cpp $(IntermediateDirectory)/wxShapeFramework_ControlShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ControlShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ControlShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ControlShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/ControlShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ControlShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ControlShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ControlShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_ControlShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ControlShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ControlShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ControlShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_CircleShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/CircleShape.cpp $(IntermediateDirectory)/wxShapeFramework_CircleShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CircleShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_CircleShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_CircleShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/CircleShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_CircleShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_CircleShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CircleShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_CircleShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/CircleShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_CircleShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CircleShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/TextShapeXml.cpp $(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/TextShapeXml.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(DependSuffix): ../../src/controls/src/wxShapeFramework/TextShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/TextShapeXml.cpp"

$(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/TextShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/TextShapeXml.cpp"

$(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/MultiSelRect.cpp $(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/MultiSelRect.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(DependSuffix): ../../src/controls/src/wxShapeFramework/MultiSelRect.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/MultiSelRect.cpp"

$(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/MultiSelRect.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/MultiSelRect.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ShapeDataObject.cpp $(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeDataObject.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(DependSuffix): ../../src/controls/src/wxShapeFramework/ShapeDataObject.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeDataObject.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ShapeDataObject.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeDataObject.cpp"

$(IntermediateDirectory)/wxShapeFramework_RectShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/RectShape.cpp $(IntermediateDirectory)/wxShapeFramework_RectShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/RectShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_RectShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_RectShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/RectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_RectShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_RectShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/RectShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_RectShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/RectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_RectShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/RectShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_ScaledDC$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ScaledDC.cpp $(IntermediateDirectory)/wxShapeFramework_ScaledDC$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ScaledDC.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ScaledDC$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ScaledDC$(DependSuffix): ../../src/controls/src/wxShapeFramework/ScaledDC.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ScaledDC$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ScaledDC$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ScaledDC.cpp"

$(IntermediateDirectory)/wxShapeFramework_ScaledDC$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ScaledDC.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ScaledDC$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ScaledDC.cpp"

$(IntermediateDirectory)/wxShapeFramework_OpenArrow$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/OpenArrow.cpp $(IntermediateDirectory)/wxShapeFramework_OpenArrow$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/OpenArrow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_OpenArrow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_OpenArrow$(DependSuffix): ../../src/controls/src/wxShapeFramework/OpenArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_OpenArrow$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_OpenArrow$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/OpenArrow.cpp"

$(IntermediateDirectory)/wxShapeFramework_OpenArrow$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/OpenArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_OpenArrow$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/OpenArrow.cpp"

$(IntermediateDirectory)/wxShapeFramework_SFEvents$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/SFEvents.cpp $(IntermediateDirectory)/wxShapeFramework_SFEvents$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/SFEvents.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_SFEvents$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_SFEvents$(DependSuffix): ../../src/controls/src/wxShapeFramework/SFEvents.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_SFEvents$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_SFEvents$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/SFEvents.cpp"

$(IntermediateDirectory)/wxShapeFramework_SFEvents$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/SFEvents.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_SFEvents$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/SFEvents.cpp"

$(IntermediateDirectory)/wxShapeFramework_Printout$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/Printout.cpp $(IntermediateDirectory)/wxShapeFramework_Printout$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/Printout.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_Printout$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_Printout$(DependSuffix): ../../src/controls/src/wxShapeFramework/Printout.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_Printout$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_Printout$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/Printout.cpp"

$(IntermediateDirectory)/wxShapeFramework_Printout$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/Printout.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_Printout$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/Printout.cpp"

$(IntermediateDirectory)/wxShapeFramework_PolygonShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/PolygonShape.cpp $(IntermediateDirectory)/wxShapeFramework_PolygonShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/PolygonShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_PolygonShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_PolygonShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/PolygonShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_PolygonShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_PolygonShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/PolygonShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_PolygonShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/PolygonShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_PolygonShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/PolygonShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_ArrowBase$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ArrowBase.cpp $(IntermediateDirectory)/wxShapeFramework_ArrowBase$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ArrowBase.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ArrowBase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ArrowBase$(DependSuffix): ../../src/controls/src/wxShapeFramework/ArrowBase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ArrowBase$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ArrowBase$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ArrowBase.cpp"

$(IntermediateDirectory)/wxShapeFramework_ArrowBase$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ArrowBase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ArrowBase$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ArrowBase.cpp"

$(IntermediateDirectory)/wxShapeFramework_OrthoShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/OrthoShape.cpp $(IntermediateDirectory)/wxShapeFramework_OrthoShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/OrthoShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_OrthoShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_OrthoShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/OrthoShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_OrthoShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_OrthoShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/OrthoShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_OrthoShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/OrthoShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_OrthoShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/OrthoShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_GridShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/GridShape.cpp $(IntermediateDirectory)/wxShapeFramework_GridShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/GridShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_GridShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_GridShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/GridShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_GridShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_GridShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/GridShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_GridShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/GridShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_GridShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/GridShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ShapeBaseXml.cpp $(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeBaseXml.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(DependSuffix): ../../src/controls/src/wxShapeFramework/ShapeBaseXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeBaseXml.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ShapeBaseXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeBaseXml.cpp"

$(IntermediateDirectory)/wxShapeFramework_AutoLayout$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/AutoLayout.cpp $(IntermediateDirectory)/wxShapeFramework_AutoLayout$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/AutoLayout.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_AutoLayout$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_AutoLayout$(DependSuffix): ../../src/controls/src/wxShapeFramework/AutoLayout.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_AutoLayout$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_AutoLayout$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/AutoLayout.cpp"

$(IntermediateDirectory)/wxShapeFramework_AutoLayout$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/AutoLayout.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_AutoLayout$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/AutoLayout.cpp"

$(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/PolygonShapeXml.cpp $(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/PolygonShapeXml.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(DependSuffix): ../../src/controls/src/wxShapeFramework/PolygonShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/PolygonShapeXml.cpp"

$(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/PolygonShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/PolygonShapeXml.cpp"

$(IntermediateDirectory)/wxShapeFramework_EditTextShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/EditTextShape.cpp $(IntermediateDirectory)/wxShapeFramework_EditTextShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/EditTextShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_EditTextShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_EditTextShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/EditTextShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_EditTextShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_EditTextShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/EditTextShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_EditTextShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/EditTextShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_EditTextShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/EditTextShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_Thumbnail$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/Thumbnail.cpp $(IntermediateDirectory)/wxShapeFramework_Thumbnail$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/Thumbnail.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_Thumbnail$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_Thumbnail$(DependSuffix): ../../src/controls/src/wxShapeFramework/Thumbnail.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_Thumbnail$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_Thumbnail$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/Thumbnail.cpp"

$(IntermediateDirectory)/wxShapeFramework_Thumbnail$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/Thumbnail.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_Thumbnail$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/Thumbnail.cpp"

$(IntermediateDirectory)/wxShapeFramework_CurveShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/CurveShape.cpp $(IntermediateDirectory)/wxShapeFramework_CurveShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CurveShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_CurveShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_CurveShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/CurveShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_CurveShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_CurveShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CurveShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_CurveShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/CurveShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_CurveShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CurveShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/FlexGridShape.cpp $(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/FlexGridShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/FlexGridShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/FlexGridShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/FlexGridShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/FlexGridShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_DiamondShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/DiamondShape.cpp $(IntermediateDirectory)/wxShapeFramework_DiamondShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiamondShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_DiamondShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_DiamondShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/DiamondShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_DiamondShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_DiamondShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiamondShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_DiamondShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/DiamondShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_DiamondShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiamondShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/FixedRectShape.cpp $(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/FixedRectShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/FixedRectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/FixedRectShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/FixedRectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/FixedRectShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ShapeDockpoint.cpp $(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeDockpoint.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(DependSuffix): ../../src/controls/src/wxShapeFramework/ShapeDockpoint.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeDockpoint.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ShapeDockpoint.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeDockpoint.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeBase$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ShapeBase.cpp $(IntermediateDirectory)/wxShapeFramework_ShapeBase$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeBase.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ShapeBase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ShapeBase$(DependSuffix): ../../src/controls/src/wxShapeFramework/ShapeBase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ShapeBase$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ShapeBase$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeBase.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeBase$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ShapeBase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ShapeBase$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeBase.cpp"

$(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/DiamondArrow.cpp $(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiamondArrow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(DependSuffix): ../../src/controls/src/wxShapeFramework/DiamondArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiamondArrow.cpp"

$(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/DiamondArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiamondArrow.cpp"

$(IntermediateDirectory)/wxShapeFramework_BitmapShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/BitmapShape.cpp $(IntermediateDirectory)/wxShapeFramework_BitmapShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/BitmapShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_BitmapShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_BitmapShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/BitmapShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_BitmapShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_BitmapShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/BitmapShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_BitmapShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/BitmapShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_BitmapShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/BitmapShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/BitmapShapeXml.cpp $(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/BitmapShapeXml.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(DependSuffix): ../../src/controls/src/wxShapeFramework/BitmapShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/BitmapShapeXml.cpp"

$(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/BitmapShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/BitmapShapeXml.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ShapeHandle.cpp $(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeHandle.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(DependSuffix): ../../src/controls/src/wxShapeFramework/ShapeHandle.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeHandle.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ShapeHandle.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeHandle.cpp"

$(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/CanvasHistory.cpp $(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CanvasHistory.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(DependSuffix): ../../src/controls/src/wxShapeFramework/CanvasHistory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CanvasHistory.cpp"

$(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/CanvasHistory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CanvasHistory.cpp"

$(IntermediateDirectory)/wxShapeFramework_LineShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/LineShape.cpp $(IntermediateDirectory)/wxShapeFramework_LineShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/LineShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_LineShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_LineShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/LineShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_LineShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_LineShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/LineShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_LineShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/LineShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_LineShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/LineShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_CommonFcn$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/CommonFcn.cpp $(IntermediateDirectory)/wxShapeFramework_CommonFcn$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CommonFcn.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_CommonFcn$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_CommonFcn$(DependSuffix): ../../src/controls/src/wxShapeFramework/CommonFcn.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_CommonFcn$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_CommonFcn$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CommonFcn.cpp"

$(IntermediateDirectory)/wxShapeFramework_CommonFcn$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/CommonFcn.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_CommonFcn$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CommonFcn.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/ShapeCanvas.cpp $(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeCanvas.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(DependSuffix): ../../src/controls/src/wxShapeFramework/ShapeCanvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeCanvas.cpp"

$(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/ShapeCanvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/ShapeCanvas.cpp"

$(IntermediateDirectory)/wxShapeFramework_TextShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/TextShape.cpp $(IntermediateDirectory)/wxShapeFramework_TextShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/TextShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_TextShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_TextShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/TextShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_TextShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_TextShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/TextShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_TextShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/TextShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_TextShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/TextShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_DiagramManager$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/DiagramManager.cpp $(IntermediateDirectory)/wxShapeFramework_DiagramManager$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiagramManager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_DiagramManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_DiagramManager$(DependSuffix): ../../src/controls/src/wxShapeFramework/DiagramManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_DiagramManager$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_DiagramManager$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiagramManager.cpp"

$(IntermediateDirectory)/wxShapeFramework_DiagramManager$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/DiagramManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_DiagramManager$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/DiagramManager.cpp"

$(IntermediateDirectory)/wxShapeFramework_wx_pch$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/wx_pch.cpp $(IntermediateDirectory)/wxShapeFramework_wx_pch$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wx_pch.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_wx_pch$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_wx_pch$(DependSuffix): ../../src/controls/src/wxShapeFramework/wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_wx_pch$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_wx_pch$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wx_pch.cpp"

$(IntermediateDirectory)/wxShapeFramework_wx_pch$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_wx_pch$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/wx_pch.cpp"

$(IntermediateDirectory)/wxShapeFramework_CircleArrow$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/CircleArrow.cpp $(IntermediateDirectory)/wxShapeFramework_CircleArrow$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CircleArrow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_CircleArrow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_CircleArrow$(DependSuffix): ../../src/controls/src/wxShapeFramework/CircleArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_CircleArrow$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_CircleArrow$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CircleArrow.cpp"

$(IntermediateDirectory)/wxShapeFramework_CircleArrow$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/CircleArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_CircleArrow$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/CircleArrow.cpp"

$(IntermediateDirectory)/wxShapeFramework_EllipseShape$(ObjectSuffix): ../../src/controls/src/wxShapeFramework/EllipseShape.cpp $(IntermediateDirectory)/wxShapeFramework_EllipseShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/EllipseShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxShapeFramework_EllipseShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxShapeFramework_EllipseShape$(DependSuffix): ../../src/controls/src/wxShapeFramework/EllipseShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxShapeFramework_EllipseShape$(ObjectSuffix) -MF$(IntermediateDirectory)/wxShapeFramework_EllipseShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/EllipseShape.cpp"

$(IntermediateDirectory)/wxShapeFramework_EllipseShape$(PreprocessSuffix): ../../src/controls/src/wxShapeFramework/EllipseShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxShapeFramework_EllipseShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxdbexplorer/trunk/src/controls/src/wxShapeFramework/EllipseShape.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CanvasState$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CanvasState$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CanvasState$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_SolidArrow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_SolidArrow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_SolidArrow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_RoundRectShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ControlShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ControlShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ControlShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CircleShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CircleShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CircleShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_TextShapeXml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_MultiSelRect$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeDataObject$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_RectShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_RectShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_RectShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ScaledDC$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ScaledDC$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ScaledDC$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_OpenArrow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_OpenArrow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_OpenArrow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_SFEvents$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_SFEvents$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_SFEvents$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_Printout$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_Printout$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_Printout$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_PolygonShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_PolygonShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_PolygonShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ArrowBase$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ArrowBase$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ArrowBase$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_OrthoShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_OrthoShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_OrthoShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_GridShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_GridShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_GridShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeBaseXml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_AutoLayout$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_AutoLayout$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_AutoLayout$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_PolygonShapeXml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_EditTextShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_EditTextShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_EditTextShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_Thumbnail$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_Thumbnail$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_Thumbnail$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CurveShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CurveShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CurveShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_FlexGridShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiamondShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiamondShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiamondShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_FixedRectShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeDockpoint$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeBase$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeBase$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeBase$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiamondArrow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_BitmapShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_BitmapShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_BitmapShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_BitmapShapeXml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeHandle$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CanvasHistory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_LineShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_LineShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_LineShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CommonFcn$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CommonFcn$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CommonFcn$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_ShapeCanvas$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_TextShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_TextShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_TextShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiagramManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiagramManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_DiagramManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_wx_pch$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_wx_pch$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_wx_pch$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CircleArrow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CircleArrow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_CircleArrow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_EllipseShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_EllipseShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxShapeFramework_EllipseShape$(PreprocessSuffix)
	$(RM) $(OutputFile)


