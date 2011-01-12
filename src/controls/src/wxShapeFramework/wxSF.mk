##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=wxSF
ConfigurationName      :=Release
IntermediateDirectory  :=.objsu
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/jankup/SourceCpp/wxsf/trunk/build"
ProjectPath            := "/home/jankup/SourceCpp/wxsf/trunk/src"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Peter Janků
Date                   :=9.1.2011
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
OutputFile             :=../lib/gcc_dll/libwx_gtk2u_wxsf-2.8.so
Preprocessors          :=$(PreprocessorSwitch)WXMAKINGDLL_WXSF $(PreprocessorSwitch)WXMAKINGDLL_WXXS $(PreprocessorSwitch)WXUSINGDLL $(PreprocessorSwitch)UNICODE $(PreprocessorSwitch)_UNICODE $(PreprocessorSwitch)__WX__ $(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -Wall -O3 -fPIC -fno-strict-aliasing `wx-config --debug=no --static=no --cflags`  $(Preprocessors)
C_CmpOptions           := -Wall -O3 -fPIC -fno-strict-aliasing `wx-config --debug=no --static=no --cflags`  $(Preprocessors)
LinkOptions            :=  -s `wx-config --debug=no --static=no --libs` 
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)../include" "$(IncludeSwitch)../src" 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../lib/gcc_dll" "$(LibraryPathSwitch)../build" 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix) $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix) $(IntermediateDirectory)/CanvasState$(ObjectSuffix) $(IntermediateDirectory)/SolidArrow$(ObjectSuffix) $(IntermediateDirectory)/RoundRectShape$(ObjectSuffix) $(IntermediateDirectory)/ControlShape$(ObjectSuffix) $(IntermediateDirectory)/CircleShape$(ObjectSuffix) $(IntermediateDirectory)/TextShapeXml$(ObjectSuffix) $(IntermediateDirectory)/MultiSelRect$(ObjectSuffix) $(IntermediateDirectory)/ShapeDataObject$(ObjectSuffix) \
	$(IntermediateDirectory)/RectShape$(ObjectSuffix) $(IntermediateDirectory)/ScaledDC$(ObjectSuffix) $(IntermediateDirectory)/OpenArrow$(ObjectSuffix) $(IntermediateDirectory)/SFEvents$(ObjectSuffix) $(IntermediateDirectory)/Printout$(ObjectSuffix) $(IntermediateDirectory)/PolygonShape$(ObjectSuffix) $(IntermediateDirectory)/ArrowBase$(ObjectSuffix) $(IntermediateDirectory)/OrthoShape$(ObjectSuffix) $(IntermediateDirectory)/GridShape$(ObjectSuffix) $(IntermediateDirectory)/ShapeBaseXml$(ObjectSuffix) \
	$(IntermediateDirectory)/AutoLayout$(ObjectSuffix) $(IntermediateDirectory)/PolygonShapeXml$(ObjectSuffix) $(IntermediateDirectory)/EditTextShape$(ObjectSuffix) $(IntermediateDirectory)/Thumbnail$(ObjectSuffix) $(IntermediateDirectory)/CurveShape$(ObjectSuffix) $(IntermediateDirectory)/FlexGridShape$(ObjectSuffix) $(IntermediateDirectory)/DiamondShape$(ObjectSuffix) $(IntermediateDirectory)/FixedRectShape$(ObjectSuffix) $(IntermediateDirectory)/ShapeDockpoint$(ObjectSuffix) $(IntermediateDirectory)/ShapeBase$(ObjectSuffix) \
	$(IntermediateDirectory)/DiamondArrow$(ObjectSuffix) $(IntermediateDirectory)/BitmapShape$(ObjectSuffix) $(IntermediateDirectory)/BitmapShapeXml$(ObjectSuffix) $(IntermediateDirectory)/ShapeHandle$(ObjectSuffix) $(IntermediateDirectory)/CanvasHistory$(ObjectSuffix) $(IntermediateDirectory)/LineShape$(ObjectSuffix) $(IntermediateDirectory)/CommonFcn$(ObjectSuffix) $(IntermediateDirectory)/ShapeCanvas$(ObjectSuffix) $(IntermediateDirectory)/TextShape$(ObjectSuffix) $(IntermediateDirectory)/DiagramManager$(ObjectSuffix) \
	$(IntermediateDirectory)/wx_pch$(ObjectSuffix) $(IntermediateDirectory)/CircleArrow$(ObjectSuffix) $(IntermediateDirectory)/EllipseShape$(ObjectSuffix) 

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
$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix): wxxmlserializer/XmlSerializer.cpp $(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/wxxmlserializer/XmlSerializer.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(DependSuffix): wxxmlserializer/XmlSerializer.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(ObjectSuffix) -MF$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/wxxmlserializer/XmlSerializer.cpp"

$(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(PreprocessSuffix): wxxmlserializer/XmlSerializer.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxxmlserializer_XmlSerializer$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/wxxmlserializer/XmlSerializer.cpp"

$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix): wxxmlserializer/PropertyIO.cpp $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/wxxmlserializer/PropertyIO.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(DependSuffix): wxxmlserializer/PropertyIO.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(ObjectSuffix) -MF$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/wxxmlserializer/PropertyIO.cpp"

$(IntermediateDirectory)/wxxmlserializer_PropertyIO$(PreprocessSuffix): wxxmlserializer/PropertyIO.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxxmlserializer_PropertyIO$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/wxxmlserializer/PropertyIO.cpp"

$(IntermediateDirectory)/CanvasState$(ObjectSuffix): CanvasState.cpp $(IntermediateDirectory)/CanvasState$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/CanvasState.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CanvasState$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CanvasState$(DependSuffix): CanvasState.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CanvasState$(ObjectSuffix) -MF$(IntermediateDirectory)/CanvasState$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/CanvasState.cpp"

$(IntermediateDirectory)/CanvasState$(PreprocessSuffix): CanvasState.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CanvasState$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/CanvasState.cpp"

$(IntermediateDirectory)/SolidArrow$(ObjectSuffix): SolidArrow.cpp $(IntermediateDirectory)/SolidArrow$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/SolidArrow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/SolidArrow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SolidArrow$(DependSuffix): SolidArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SolidArrow$(ObjectSuffix) -MF$(IntermediateDirectory)/SolidArrow$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/SolidArrow.cpp"

$(IntermediateDirectory)/SolidArrow$(PreprocessSuffix): SolidArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SolidArrow$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/SolidArrow.cpp"

$(IntermediateDirectory)/RoundRectShape$(ObjectSuffix): RoundRectShape.cpp $(IntermediateDirectory)/RoundRectShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/RoundRectShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/RoundRectShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RoundRectShape$(DependSuffix): RoundRectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RoundRectShape$(ObjectSuffix) -MF$(IntermediateDirectory)/RoundRectShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/RoundRectShape.cpp"

$(IntermediateDirectory)/RoundRectShape$(PreprocessSuffix): RoundRectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RoundRectShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/RoundRectShape.cpp"

$(IntermediateDirectory)/ControlShape$(ObjectSuffix): ControlShape.cpp $(IntermediateDirectory)/ControlShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ControlShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ControlShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ControlShape$(DependSuffix): ControlShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ControlShape$(ObjectSuffix) -MF$(IntermediateDirectory)/ControlShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ControlShape.cpp"

$(IntermediateDirectory)/ControlShape$(PreprocessSuffix): ControlShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ControlShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ControlShape.cpp"

$(IntermediateDirectory)/CircleShape$(ObjectSuffix): CircleShape.cpp $(IntermediateDirectory)/CircleShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/CircleShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CircleShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CircleShape$(DependSuffix): CircleShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CircleShape$(ObjectSuffix) -MF$(IntermediateDirectory)/CircleShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/CircleShape.cpp"

$(IntermediateDirectory)/CircleShape$(PreprocessSuffix): CircleShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CircleShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/CircleShape.cpp"

$(IntermediateDirectory)/TextShapeXml$(ObjectSuffix): TextShapeXml.cpp $(IntermediateDirectory)/TextShapeXml$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/TextShapeXml.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/TextShapeXml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextShapeXml$(DependSuffix): TextShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextShapeXml$(ObjectSuffix) -MF$(IntermediateDirectory)/TextShapeXml$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/TextShapeXml.cpp"

$(IntermediateDirectory)/TextShapeXml$(PreprocessSuffix): TextShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextShapeXml$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/TextShapeXml.cpp"

$(IntermediateDirectory)/MultiSelRect$(ObjectSuffix): MultiSelRect.cpp $(IntermediateDirectory)/MultiSelRect$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/MultiSelRect.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/MultiSelRect$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MultiSelRect$(DependSuffix): MultiSelRect.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MultiSelRect$(ObjectSuffix) -MF$(IntermediateDirectory)/MultiSelRect$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/MultiSelRect.cpp"

$(IntermediateDirectory)/MultiSelRect$(PreprocessSuffix): MultiSelRect.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MultiSelRect$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/MultiSelRect.cpp"

$(IntermediateDirectory)/ShapeDataObject$(ObjectSuffix): ShapeDataObject.cpp $(IntermediateDirectory)/ShapeDataObject$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeDataObject.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ShapeDataObject$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ShapeDataObject$(DependSuffix): ShapeDataObject.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ShapeDataObject$(ObjectSuffix) -MF$(IntermediateDirectory)/ShapeDataObject$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeDataObject.cpp"

$(IntermediateDirectory)/ShapeDataObject$(PreprocessSuffix): ShapeDataObject.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ShapeDataObject$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeDataObject.cpp"

$(IntermediateDirectory)/RectShape$(ObjectSuffix): RectShape.cpp $(IntermediateDirectory)/RectShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/RectShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/RectShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RectShape$(DependSuffix): RectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RectShape$(ObjectSuffix) -MF$(IntermediateDirectory)/RectShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/RectShape.cpp"

$(IntermediateDirectory)/RectShape$(PreprocessSuffix): RectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RectShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/RectShape.cpp"

$(IntermediateDirectory)/ScaledDC$(ObjectSuffix): ScaledDC.cpp $(IntermediateDirectory)/ScaledDC$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ScaledDC.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ScaledDC$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ScaledDC$(DependSuffix): ScaledDC.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ScaledDC$(ObjectSuffix) -MF$(IntermediateDirectory)/ScaledDC$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ScaledDC.cpp"

$(IntermediateDirectory)/ScaledDC$(PreprocessSuffix): ScaledDC.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ScaledDC$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ScaledDC.cpp"

$(IntermediateDirectory)/OpenArrow$(ObjectSuffix): OpenArrow.cpp $(IntermediateDirectory)/OpenArrow$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/OpenArrow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenArrow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenArrow$(DependSuffix): OpenArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenArrow$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenArrow$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/OpenArrow.cpp"

$(IntermediateDirectory)/OpenArrow$(PreprocessSuffix): OpenArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenArrow$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/OpenArrow.cpp"

$(IntermediateDirectory)/SFEvents$(ObjectSuffix): SFEvents.cpp $(IntermediateDirectory)/SFEvents$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/SFEvents.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/SFEvents$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SFEvents$(DependSuffix): SFEvents.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SFEvents$(ObjectSuffix) -MF$(IntermediateDirectory)/SFEvents$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/SFEvents.cpp"

$(IntermediateDirectory)/SFEvents$(PreprocessSuffix): SFEvents.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SFEvents$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/SFEvents.cpp"

$(IntermediateDirectory)/Printout$(ObjectSuffix): Printout.cpp $(IntermediateDirectory)/Printout$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/Printout.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Printout$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Printout$(DependSuffix): Printout.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Printout$(ObjectSuffix) -MF$(IntermediateDirectory)/Printout$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/Printout.cpp"

$(IntermediateDirectory)/Printout$(PreprocessSuffix): Printout.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Printout$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/Printout.cpp"

$(IntermediateDirectory)/PolygonShape$(ObjectSuffix): PolygonShape.cpp $(IntermediateDirectory)/PolygonShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/PolygonShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/PolygonShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PolygonShape$(DependSuffix): PolygonShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PolygonShape$(ObjectSuffix) -MF$(IntermediateDirectory)/PolygonShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/PolygonShape.cpp"

$(IntermediateDirectory)/PolygonShape$(PreprocessSuffix): PolygonShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PolygonShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/PolygonShape.cpp"

$(IntermediateDirectory)/ArrowBase$(ObjectSuffix): ArrowBase.cpp $(IntermediateDirectory)/ArrowBase$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ArrowBase.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ArrowBase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ArrowBase$(DependSuffix): ArrowBase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ArrowBase$(ObjectSuffix) -MF$(IntermediateDirectory)/ArrowBase$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ArrowBase.cpp"

$(IntermediateDirectory)/ArrowBase$(PreprocessSuffix): ArrowBase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ArrowBase$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ArrowBase.cpp"

$(IntermediateDirectory)/OrthoShape$(ObjectSuffix): OrthoShape.cpp $(IntermediateDirectory)/OrthoShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/OrthoShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OrthoShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OrthoShape$(DependSuffix): OrthoShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OrthoShape$(ObjectSuffix) -MF$(IntermediateDirectory)/OrthoShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/OrthoShape.cpp"

$(IntermediateDirectory)/OrthoShape$(PreprocessSuffix): OrthoShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OrthoShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/OrthoShape.cpp"

$(IntermediateDirectory)/GridShape$(ObjectSuffix): GridShape.cpp $(IntermediateDirectory)/GridShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/GridShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/GridShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GridShape$(DependSuffix): GridShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GridShape$(ObjectSuffix) -MF$(IntermediateDirectory)/GridShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/GridShape.cpp"

$(IntermediateDirectory)/GridShape$(PreprocessSuffix): GridShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GridShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/GridShape.cpp"

$(IntermediateDirectory)/ShapeBaseXml$(ObjectSuffix): ShapeBaseXml.cpp $(IntermediateDirectory)/ShapeBaseXml$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeBaseXml.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ShapeBaseXml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ShapeBaseXml$(DependSuffix): ShapeBaseXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ShapeBaseXml$(ObjectSuffix) -MF$(IntermediateDirectory)/ShapeBaseXml$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeBaseXml.cpp"

$(IntermediateDirectory)/ShapeBaseXml$(PreprocessSuffix): ShapeBaseXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ShapeBaseXml$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeBaseXml.cpp"

$(IntermediateDirectory)/AutoLayout$(ObjectSuffix): AutoLayout.cpp $(IntermediateDirectory)/AutoLayout$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/AutoLayout.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/AutoLayout$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AutoLayout$(DependSuffix): AutoLayout.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AutoLayout$(ObjectSuffix) -MF$(IntermediateDirectory)/AutoLayout$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/AutoLayout.cpp"

$(IntermediateDirectory)/AutoLayout$(PreprocessSuffix): AutoLayout.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AutoLayout$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/AutoLayout.cpp"

$(IntermediateDirectory)/PolygonShapeXml$(ObjectSuffix): PolygonShapeXml.cpp $(IntermediateDirectory)/PolygonShapeXml$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/PolygonShapeXml.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/PolygonShapeXml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PolygonShapeXml$(DependSuffix): PolygonShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PolygonShapeXml$(ObjectSuffix) -MF$(IntermediateDirectory)/PolygonShapeXml$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/PolygonShapeXml.cpp"

$(IntermediateDirectory)/PolygonShapeXml$(PreprocessSuffix): PolygonShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PolygonShapeXml$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/PolygonShapeXml.cpp"

$(IntermediateDirectory)/EditTextShape$(ObjectSuffix): EditTextShape.cpp $(IntermediateDirectory)/EditTextShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/EditTextShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/EditTextShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EditTextShape$(DependSuffix): EditTextShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EditTextShape$(ObjectSuffix) -MF$(IntermediateDirectory)/EditTextShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/EditTextShape.cpp"

$(IntermediateDirectory)/EditTextShape$(PreprocessSuffix): EditTextShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EditTextShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/EditTextShape.cpp"

$(IntermediateDirectory)/Thumbnail$(ObjectSuffix): Thumbnail.cpp $(IntermediateDirectory)/Thumbnail$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/Thumbnail.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Thumbnail$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Thumbnail$(DependSuffix): Thumbnail.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Thumbnail$(ObjectSuffix) -MF$(IntermediateDirectory)/Thumbnail$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/Thumbnail.cpp"

$(IntermediateDirectory)/Thumbnail$(PreprocessSuffix): Thumbnail.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Thumbnail$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/Thumbnail.cpp"

$(IntermediateDirectory)/CurveShape$(ObjectSuffix): CurveShape.cpp $(IntermediateDirectory)/CurveShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/CurveShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CurveShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CurveShape$(DependSuffix): CurveShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CurveShape$(ObjectSuffix) -MF$(IntermediateDirectory)/CurveShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/CurveShape.cpp"

$(IntermediateDirectory)/CurveShape$(PreprocessSuffix): CurveShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CurveShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/CurveShape.cpp"

$(IntermediateDirectory)/FlexGridShape$(ObjectSuffix): FlexGridShape.cpp $(IntermediateDirectory)/FlexGridShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/FlexGridShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/FlexGridShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FlexGridShape$(DependSuffix): FlexGridShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FlexGridShape$(ObjectSuffix) -MF$(IntermediateDirectory)/FlexGridShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/FlexGridShape.cpp"

$(IntermediateDirectory)/FlexGridShape$(PreprocessSuffix): FlexGridShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FlexGridShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/FlexGridShape.cpp"

$(IntermediateDirectory)/DiamondShape$(ObjectSuffix): DiamondShape.cpp $(IntermediateDirectory)/DiamondShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/DiamondShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DiamondShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DiamondShape$(DependSuffix): DiamondShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DiamondShape$(ObjectSuffix) -MF$(IntermediateDirectory)/DiamondShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/DiamondShape.cpp"

$(IntermediateDirectory)/DiamondShape$(PreprocessSuffix): DiamondShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DiamondShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/DiamondShape.cpp"

$(IntermediateDirectory)/FixedRectShape$(ObjectSuffix): FixedRectShape.cpp $(IntermediateDirectory)/FixedRectShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/FixedRectShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/FixedRectShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FixedRectShape$(DependSuffix): FixedRectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FixedRectShape$(ObjectSuffix) -MF$(IntermediateDirectory)/FixedRectShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/FixedRectShape.cpp"

$(IntermediateDirectory)/FixedRectShape$(PreprocessSuffix): FixedRectShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FixedRectShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/FixedRectShape.cpp"

$(IntermediateDirectory)/ShapeDockpoint$(ObjectSuffix): ShapeDockpoint.cpp $(IntermediateDirectory)/ShapeDockpoint$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeDockpoint.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ShapeDockpoint$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ShapeDockpoint$(DependSuffix): ShapeDockpoint.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ShapeDockpoint$(ObjectSuffix) -MF$(IntermediateDirectory)/ShapeDockpoint$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeDockpoint.cpp"

$(IntermediateDirectory)/ShapeDockpoint$(PreprocessSuffix): ShapeDockpoint.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ShapeDockpoint$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeDockpoint.cpp"

$(IntermediateDirectory)/ShapeBase$(ObjectSuffix): ShapeBase.cpp $(IntermediateDirectory)/ShapeBase$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeBase.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ShapeBase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ShapeBase$(DependSuffix): ShapeBase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ShapeBase$(ObjectSuffix) -MF$(IntermediateDirectory)/ShapeBase$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeBase.cpp"

$(IntermediateDirectory)/ShapeBase$(PreprocessSuffix): ShapeBase.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ShapeBase$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeBase.cpp"

$(IntermediateDirectory)/DiamondArrow$(ObjectSuffix): DiamondArrow.cpp $(IntermediateDirectory)/DiamondArrow$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/DiamondArrow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DiamondArrow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DiamondArrow$(DependSuffix): DiamondArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DiamondArrow$(ObjectSuffix) -MF$(IntermediateDirectory)/DiamondArrow$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/DiamondArrow.cpp"

$(IntermediateDirectory)/DiamondArrow$(PreprocessSuffix): DiamondArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DiamondArrow$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/DiamondArrow.cpp"

$(IntermediateDirectory)/BitmapShape$(ObjectSuffix): BitmapShape.cpp $(IntermediateDirectory)/BitmapShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/BitmapShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/BitmapShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BitmapShape$(DependSuffix): BitmapShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BitmapShape$(ObjectSuffix) -MF$(IntermediateDirectory)/BitmapShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/BitmapShape.cpp"

$(IntermediateDirectory)/BitmapShape$(PreprocessSuffix): BitmapShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BitmapShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/BitmapShape.cpp"

$(IntermediateDirectory)/BitmapShapeXml$(ObjectSuffix): BitmapShapeXml.cpp $(IntermediateDirectory)/BitmapShapeXml$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/BitmapShapeXml.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/BitmapShapeXml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BitmapShapeXml$(DependSuffix): BitmapShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BitmapShapeXml$(ObjectSuffix) -MF$(IntermediateDirectory)/BitmapShapeXml$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/BitmapShapeXml.cpp"

$(IntermediateDirectory)/BitmapShapeXml$(PreprocessSuffix): BitmapShapeXml.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BitmapShapeXml$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/BitmapShapeXml.cpp"

$(IntermediateDirectory)/ShapeHandle$(ObjectSuffix): ShapeHandle.cpp $(IntermediateDirectory)/ShapeHandle$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeHandle.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ShapeHandle$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ShapeHandle$(DependSuffix): ShapeHandle.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ShapeHandle$(ObjectSuffix) -MF$(IntermediateDirectory)/ShapeHandle$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeHandle.cpp"

$(IntermediateDirectory)/ShapeHandle$(PreprocessSuffix): ShapeHandle.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ShapeHandle$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeHandle.cpp"

$(IntermediateDirectory)/CanvasHistory$(ObjectSuffix): CanvasHistory.cpp $(IntermediateDirectory)/CanvasHistory$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/CanvasHistory.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CanvasHistory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CanvasHistory$(DependSuffix): CanvasHistory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CanvasHistory$(ObjectSuffix) -MF$(IntermediateDirectory)/CanvasHistory$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/CanvasHistory.cpp"

$(IntermediateDirectory)/CanvasHistory$(PreprocessSuffix): CanvasHistory.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CanvasHistory$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/CanvasHistory.cpp"

$(IntermediateDirectory)/LineShape$(ObjectSuffix): LineShape.cpp $(IntermediateDirectory)/LineShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/LineShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/LineShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LineShape$(DependSuffix): LineShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LineShape$(ObjectSuffix) -MF$(IntermediateDirectory)/LineShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/LineShape.cpp"

$(IntermediateDirectory)/LineShape$(PreprocessSuffix): LineShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LineShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/LineShape.cpp"

$(IntermediateDirectory)/CommonFcn$(ObjectSuffix): CommonFcn.cpp $(IntermediateDirectory)/CommonFcn$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/CommonFcn.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CommonFcn$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CommonFcn$(DependSuffix): CommonFcn.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CommonFcn$(ObjectSuffix) -MF$(IntermediateDirectory)/CommonFcn$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/CommonFcn.cpp"

$(IntermediateDirectory)/CommonFcn$(PreprocessSuffix): CommonFcn.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CommonFcn$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/CommonFcn.cpp"

$(IntermediateDirectory)/ShapeCanvas$(ObjectSuffix): ShapeCanvas.cpp $(IntermediateDirectory)/ShapeCanvas$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeCanvas.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ShapeCanvas$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ShapeCanvas$(DependSuffix): ShapeCanvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ShapeCanvas$(ObjectSuffix) -MF$(IntermediateDirectory)/ShapeCanvas$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeCanvas.cpp"

$(IntermediateDirectory)/ShapeCanvas$(PreprocessSuffix): ShapeCanvas.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ShapeCanvas$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/ShapeCanvas.cpp"

$(IntermediateDirectory)/TextShape$(ObjectSuffix): TextShape.cpp $(IntermediateDirectory)/TextShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/TextShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/TextShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextShape$(DependSuffix): TextShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextShape$(ObjectSuffix) -MF$(IntermediateDirectory)/TextShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/TextShape.cpp"

$(IntermediateDirectory)/TextShape$(PreprocessSuffix): TextShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/TextShape.cpp"

$(IntermediateDirectory)/DiagramManager$(ObjectSuffix): DiagramManager.cpp $(IntermediateDirectory)/DiagramManager$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/DiagramManager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DiagramManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DiagramManager$(DependSuffix): DiagramManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DiagramManager$(ObjectSuffix) -MF$(IntermediateDirectory)/DiagramManager$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/DiagramManager.cpp"

$(IntermediateDirectory)/DiagramManager$(PreprocessSuffix): DiagramManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DiagramManager$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/DiagramManager.cpp"

$(IntermediateDirectory)/wx_pch$(ObjectSuffix): wx_pch.cpp $(IntermediateDirectory)/wx_pch$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/wx_pch.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/wx_pch$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wx_pch$(DependSuffix): wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wx_pch$(ObjectSuffix) -MF$(IntermediateDirectory)/wx_pch$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/wx_pch.cpp"

$(IntermediateDirectory)/wx_pch$(PreprocessSuffix): wx_pch.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wx_pch$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/wx_pch.cpp"

$(IntermediateDirectory)/CircleArrow$(ObjectSuffix): CircleArrow.cpp $(IntermediateDirectory)/CircleArrow$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/CircleArrow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CircleArrow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CircleArrow$(DependSuffix): CircleArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CircleArrow$(ObjectSuffix) -MF$(IntermediateDirectory)/CircleArrow$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/CircleArrow.cpp"

$(IntermediateDirectory)/CircleArrow$(PreprocessSuffix): CircleArrow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CircleArrow$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/CircleArrow.cpp"

$(IntermediateDirectory)/EllipseShape$(ObjectSuffix): EllipseShape.cpp $(IntermediateDirectory)/EllipseShape$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jankup/SourceCpp/wxsf/trunk/src/EllipseShape.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/EllipseShape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EllipseShape$(DependSuffix): EllipseShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EllipseShape$(ObjectSuffix) -MF$(IntermediateDirectory)/EllipseShape$(DependSuffix) -MM "/home/jankup/SourceCpp/wxsf/trunk/src/EllipseShape.cpp"

$(IntermediateDirectory)/EllipseShape$(PreprocessSuffix): EllipseShape.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EllipseShape$(PreprocessSuffix) "/home/jankup/SourceCpp/wxsf/trunk/src/EllipseShape.cpp"


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
	$(RM) $(IntermediateDirectory)/CanvasState$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CanvasState$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CanvasState$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/SolidArrow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/SolidArrow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/SolidArrow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/RoundRectShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/RoundRectShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/RoundRectShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ControlShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ControlShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ControlShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CircleShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CircleShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CircleShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/TextShapeXml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/TextShapeXml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/TextShapeXml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MultiSelRect$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MultiSelRect$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MultiSelRect$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ShapeDataObject$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ShapeDataObject$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ShapeDataObject$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/RectShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/RectShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/RectShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ScaledDC$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ScaledDC$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ScaledDC$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenArrow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenArrow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenArrow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/SFEvents$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/SFEvents$(DependSuffix)
	$(RM) $(IntermediateDirectory)/SFEvents$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Printout$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Printout$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Printout$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/PolygonShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/PolygonShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/PolygonShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ArrowBase$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ArrowBase$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ArrowBase$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OrthoShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OrthoShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OrthoShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/GridShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/GridShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/GridShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ShapeBaseXml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ShapeBaseXml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ShapeBaseXml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/AutoLayout$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/AutoLayout$(DependSuffix)
	$(RM) $(IntermediateDirectory)/AutoLayout$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/PolygonShapeXml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/PolygonShapeXml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/PolygonShapeXml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/EditTextShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/EditTextShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/EditTextShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Thumbnail$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Thumbnail$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Thumbnail$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CurveShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CurveShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CurveShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/FlexGridShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/FlexGridShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/FlexGridShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DiamondShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DiamondShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DiamondShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/FixedRectShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/FixedRectShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/FixedRectShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ShapeDockpoint$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ShapeDockpoint$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ShapeDockpoint$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ShapeBase$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ShapeBase$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ShapeBase$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DiamondArrow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DiamondArrow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DiamondArrow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/BitmapShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/BitmapShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/BitmapShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/BitmapShapeXml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/BitmapShapeXml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/BitmapShapeXml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ShapeHandle$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ShapeHandle$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ShapeHandle$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CanvasHistory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CanvasHistory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CanvasHistory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/LineShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/LineShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/LineShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CommonFcn$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CommonFcn$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CommonFcn$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ShapeCanvas$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ShapeCanvas$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ShapeCanvas$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/TextShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/TextShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/TextShape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DiagramManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DiagramManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DiagramManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wx_pch$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CircleArrow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CircleArrow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CircleArrow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/EllipseShape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/EllipseShape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/EllipseShape$(PreprocessSuffix)
	$(RM) $(OutputFile)


