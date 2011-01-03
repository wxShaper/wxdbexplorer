.PHONY: clean All

All:
	@echo ----------Building project:[ wxPropGrid - Release ]----------
	@cd "propgrid" && "$(MAKE)" -f "wxPropGrid.mk"
	@echo ----------Building project:[ wxScintilla - Release ]----------
	@cd "wxScintilla" && "$(MAKE)" -f "wxScintilla.mk"
	@echo ----------Building project:[ wxShapeFramework - Release ]----------
	@cd "wxShapeFramework" && "$(MAKE)" -f "wxShapeFramework.mk"
	@echo ----------Building project:[ DatabaseExplorer - Release ]----------
	@cd "../src" && "$(MAKE)" -f "DatabaseExplorer.mk"
clean:
	@echo ----------Cleaning project:[ wxPropGrid - Release ]----------
	@cd "propgrid" && "$(MAKE)" -f "wxPropGrid.mk"  clean
	@echo ----------Cleaning project:[ wxScintilla - Release ]----------
	@cd "wxScintilla" && "$(MAKE)" -f "wxScintilla.mk"  clean
	@echo ----------Cleaning project:[ wxShapeFramework - Release ]----------
	@cd "wxShapeFramework" && "$(MAKE)" -f "wxShapeFramework.mk"  clean
	@echo ----------Cleaning project:[ DatabaseExplorer - Release ]----------
	@cd "../src" && "$(MAKE)" -f "DatabaseExplorer.mk" clean
