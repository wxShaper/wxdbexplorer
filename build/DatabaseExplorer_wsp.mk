.PHONY: clean All

All:
	@echo ----------Building project:[ DatabaseExplorer - Release ]----------
	@cd "../src" && "$(MAKE)" -f "DatabaseExplorer.mk"
clean:
	@echo ----------Cleaning project:[ DatabaseExplorer - Release ]----------
	@cd "../src" && "$(MAKE)" -f "DatabaseExplorer.mk" clean
