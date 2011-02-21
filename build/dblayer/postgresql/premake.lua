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

addoption( "dbl-postgresql-headers", "PostgreSQL header files path" )
addoption( "dbl-postgresql-libs", "PostgreSQL library files path" )

-- Set the name of your package.
package.name = "DatabaseLayerPostgreSQL"
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
	matchfiles( "../../../src/controls/include/wx/dblayer/include/Database*.h", "../../../src/controls/include/wx/dblayer/include/Postgres*.h", "../../../src/controls/include/wx/dblayer/include/PreparedStatement.h" ),
	matchfiles( "../../../src/controls/src/dblayer/Database*.cpp", "../../../src/controls/src/dblayer/Postgres*.cpp", "../../../src/controls/src/dblayer/PreparedStatement.cpp" )
}
-- Set the include paths.
package.includepaths = { "../../../src/controls/include/wx/dblayer/include",  options["dbl-postgresql-headers"] }

-- Set the library paths.
package.libpaths = { options["dbl-postgresql-libs"] }

-- Set the defines.
package.defines = { "WXMAKINGDLL_DATABASELAYER", "__WX__", "PIC" }
if( windows ) then
	table.insert( package.defines, "HAVE_W32API_H" )
end

-- Set wxWidgets presets
dofile('../../premake/scripts/wxpresets.lua')

