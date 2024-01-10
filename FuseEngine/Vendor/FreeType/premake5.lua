project "FreeTypeOLD"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    
    targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "include/f2build.h",
        "include/freetype/**.h",

		"src/svg/**.h",
		"src/svg/**.c",
		
	-- base components (required)
		"src/base/ftsystem.c",
		"src/base/ftinit.c",
		"src/base/ftdebug.c",
		
		"src/base/ftbase.c",
		
		"src/base/ftbbox.c",		-- recommended, see <ftbbox.h>
		"src/base/ftglyph.c",		-- recommended, see <ftglyph.h>
		
		"src/base/ftbdf.c",			-- optional, see <ftbdf.h>
		"src/base/ftbitmap.c",		-- optional, see <ftbitmap.h>
		"src/base/ftcid.c",			-- optional, see <ftcid.h>
		"src/base/ftfstype.c", 		-- optional
		"src/base/ftgasp.c",		-- optional, see <ftgasp.h>
		"src/base/ftgxval.c",		-- optional, see <ftgxval.h>
		"src/base/ftmm.c",			-- optional, see <ftmm.h>
		"src/base/ftotval.c",		-- optional, see <ftotval.h>
		"src/base/ftpatent.c",      -- optional
		"src/base/ftpfr.c",         -- optional, see <ftpfr.h>
		"src/base/ftstroke.c",      -- optional, see <ftstroke.h>
		"src/base/ftsynth.c",       -- optional, see <ftsynth.h>
		"src/base/fttype1.c",       -- optional, see <t1tables.h>
		"src/base/ftwinfnt.c",      -- optional, see <ftwinfnt.h>
		
	-- font drivers (optional; at least one is needed)
		"src/bdf/bdf.c",			-- BDF font driver
		"src/cff/cff.c",			-- CFF/OpenType font driver
		"src/cid/type1cid.c",		-- Type 1 CID-keyed font driver
		"src/pcf/pcf.c",			-- PCF font driver
		"src/pfr/pfr.c",			-- PFR/TrueDoc font driver
		"src/sfnt/sfnt.c",			-- SFNT files support (TrueType & OpenType)
		"src/truetype/truetype.c",	-- TrueType font driver
		"src/type1/type1.c",		-- Type 1 font driver
		"src/type42/type42.c",		-- Type 42 font driver
		"src/winfonts/winfnt.c",	-- Windows FONT / FNT font driver
		
	-- rasterizers (optional; at least one is needed for vector formats)
		"src/raster/raster.c",		-- monochrome rasterizer
		"src/sdf/sdf.c",			-- Signed Distance Field driver
		"src/smooth/smooth.c",		-- anti-aliasing rasterizer
		
	-- auxiliary modules (optional)
		"src/autofit/autofit.c",	-- auto hinting module
		"src/cache/ftcache.c",		-- cache sub-system (in beta)
		"src/gzip/ftgzip.c",		-- support for compressed fonts (.gz)
		"src/lzw/ftlzw.c",			-- support for compressed fonts (.Z)
		"src/bzip2/ftbzip2.c",		-- support for compressed fonts (.bz2)
		"src/gxvalid/gxvalid.c",	-- TrueTypeGX/AAT table validation
		"src/otvalid/otvalid.c",	-- OpenType table validation
		"src/psaux/psaux.c",		-- PostScript Type 1 parsing
		"src/pshinter/pshinter.c",	-- PS hinting module
		"src/psnames/psnames.c",	-- PostScript glyph names support
    }

    includedirs
    {
        "include"
    }
    
    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
		defines
		{
			"WIN32",
			"_DEBUG",
			"_LIB",
			"_CRT_SECURE_NO_WARNINGS",
			"FT2_BUILD_LIBRARY",
			"FT_DEBUG_LEVEL_ERROR",
			"FT_DEBUG_LEVEL_TRACE"

		}
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
		defines
		{
			"WIN32",
			"NDEBUG",
			"_LIB",
			"_CRT_SECURE_NO_WARNINGS",
			"FT2_BUILD_LIBRARY"
		}
        runtime "Release"
        optimize "on"