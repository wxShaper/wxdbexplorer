--*****************************************************************************
--*	Author:		Michal Bližňák
--*	Date:		09/01/2010
--*	Version:	1.00
--*	
--*	NOTES:
--*		- use the '/' slash for all paths.
--*****************************************************************************

-- Initialize wxWigets and other presets
dofile('../../premake/scripts/init.lua')
wx_custom = "_dbe"

--******* Initial Setup ************
--*	Most of the setting are set here.
--**********************************

-- Set the name of your package.
package.name = "DatabaseLayerSQLite"
-- Set this if you want a different name for your target than the package's name.
targetName = "dblayer_sqlite"
-- Set the kind of package you want to create.
--		Options: exe | winexe | lib | dll
package.kind = "dll"
if( windows ) then
	package.bindir = "../../../bin/gcc"
else
	package.bindir = "../../../bin/gcc/lib"
end
-- Set the files to include.
package.files =
{
	matchfiles( "../../../src/controls/include/wx/dblayer/include/Database*.h", "../../../src/controls/include/wx/dblayer/include/Sqlite*.h", "../../../src/controls/include/wx/dblayer/include/PreparedStatement.h" ),
	matchfiles( "../../../src/controls/src/dblayer/Database*.cpp", "../../../src/controls/src/dblayer/Sqlite*.cpp", "../../../src/controls/src/dblayer/PreparedStatement.cpp", "../../../src/controls/src/sqlite3/sqlite3.c" )
}
-- Set the include paths.
package.includepaths = { "../../../src/controls/include/wx/dblayer/include",  "../../../src/controls/src/sqlite3" }
-- Set libraries to link.

-- Set the defines.
package.defines = { "WXMAKINGDLL_DATABASELAYER", "__WX__", "PIC" }
if( windows ) then
	table.insert( package.defines, "HAVE_W32API_H" )
end

-- Set wxWidgets presets
dofile('../../premake/scripts/wxpresets.lua')

