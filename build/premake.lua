project.name = "DatabaseExplorer"

addoption( "dbl-sqlite", "Use SQLite connector" )
addoption( "dbl-mysql", "Use MySQL connector" )
addoption( "dbl-postgresql", "Use PostgreSQL connector" )
-- Set common output directory
if ( ( target == "vs2003" ) or ( target == "vs2005" ) ) then
	project.bindir = "../bin/vc"
	project.libdir = "../bin/vc"
else
	project.bindir = "../bin/gcc"
	project.libdir = "../bin/gcc"
end

-- Configurations. All I am doing is reordering them so that
-- it defaults to a Release build.
project.configs = { "Release", "Debug" }

-- Add packages here.
if( options["dbl-sqlite"] ) then
	dopackage( "dblayer/sqlite" )
end
if( options["dbl-mysql"] ) then
	dopackage( "dblayer/mysql" )
end
if( options["dbl-postgresql"] ) then
	dopackage( "dblayer/postgresql" )
end
dopackage( "propgrid" )
dopackage( "wxScintilla" )
dopackage( "wxShapeFramework" )
dopackage( "../src" )

