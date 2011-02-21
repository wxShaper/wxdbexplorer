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

addoption( "dbl-mysql-headers", "MySQL header files path" )
addoption( "dbl-mysql-libs", "MySQL library files path" )

-- Set the name of your package.
package.name = "DatabaseLayerMySQL"
-- Set this if you want a different name for your target than the package's name.
targetName = "dblayer_mysql"
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
	matchfiles( "../../../src/controls/include/wx/dblayer/include/Database*.h", "../../../src/controls/include/wx/dblayer/include/Mysql*.h", "../../../src/controls/include/wx/dblayer/include/PreparedStatement.h" ),
	matchfiles( "../../../src/controls/src/dblayer/Database*.cpp", "../../../src/controls/src/dblayer/Mysql*.cpp", "../../../src/controls/src/dblayer/PreparedStatement.cpp" )
}
-- Set the include paths.
package.includepaths = { "../../../src/controls/include/wx/dblayer/include",  options["dbl-mysql-headers"] }

-- Set the library paths.
package.libpaths = { options["mysql-lib-path"] }

-- Set the defines.
package.defines = { "WXMAKINGDLL_DATABASELAYER", "__WX__", "PIC" }
if( windows ) then
	table.insert( package.defines, "HAVE_W32API_H" )
end

-- Set wxWidgets presets
dofile('../../premake/scripts/wxpresets.lua')

