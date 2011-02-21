--*****************************************************************************
--*	Author:		Michal Bližňák
--*	Date:		09/01/2010
--*	Version:	1.00
--*	
--*	NOTES:
--*		- use the '/' slash for all paths.
--*****************************************************************************

-- Initialize wxWigets and other presets
dofile('../premake/scripts/init.lua')
wx_custom = "_dbe"

--******* Initial Setup ************
--*	Most of the setting are set here.
--**********************************

-- Set the name of your package.
package.name = "wxPropGrid"
-- Set this if you want a different name for your target than the package's name.
targetName = "propgrid"
-- Set the kind of package you want to create.
--		Options: exe | winexe | lib | dll
package.kind = "dll"
if( windows ) then
	package.bindir = "../../bin/gcc"
else
	package.bindir = "../../bin/gcc/lib"
end
-- Set the files to include.
package.files = { matchfiles( "../../src/controls/src/propgrid/*.cpp", "../../src/controls/include/wx/propgrid/*.h") }
-- Set the include paths.
package.includepaths = { "../../src/controls/include" }
-- Set the defines.
package.defines = { "WXMAKINGDLL_PROPGRID", "MONOLITHIC" }

-- Set wxWidgets presets
dofile('../premake/scripts/wxpresets.lua')

