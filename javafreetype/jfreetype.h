#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include <stdint.h>

#ifndef Pointer
#define Pointer long long
#endif


#ifndef string
#define string char*
#endif

#ifndef EXPORT
#define EXPORT __declspec(dllexport)
#endif

/*
*		ABSTRACTED API
*/
EXPORT Pointer CreateLibrary();

EXPORT long DestroyLibrary(Pointer library);

EXPORT Pointer CreateFace(Pointer library, string path, long index);

EXPORT int GetNumFaceGlyphs(Pointer face);

EXPORT short GetFaceAscender(Pointer face);

EXPORT long SetCharSize(Pointer face, int width, int height, int horizontalRes, int verticalRes);

EXPORT long SetPixelSizes(Pointer face, int width, int height);

EXPORT long GetCharIndex(Pointer face, long charcode);

EXPORT long LoadGlyph(Pointer face, int glyphIndex, int32_t flags);

EXPORT int RenderGlyph(Pointer face, int mode);

EXPORT long GetGlyphHorizontalAdvance(Pointer face);

EXPORT long GetGlyphVerticalAdvance(Pointer face);

EXPORT long GetNumGlyphBitmapRows(Pointer face);

EXPORT long GetGlyphBitmapWidth(Pointer face);

EXPORT Pointer GetGlyphBitmap(Pointer face);

/*
*			LOW LEVEL API
*/

//EXPORT Pointer nFT_Init_FreeType();

//EXPORT long nFT_Done_FreeType(Pointer library);

//EXPORT Pointer nFT_New_Library();

//EXPORT long nFT_Done_Library(Pointer library);

