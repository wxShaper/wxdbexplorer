project.name = "DatabaseExplorer"

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
dopackage( "propgrid" )
dopackage( "wxScintilla" )
dopackage( "wxShapeFramework" )dopackage( "../src" )

