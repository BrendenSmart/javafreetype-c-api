#include "jfreetype.h"

Pointer CreateLibrary() {
	FT_Library library;

	FT_Init_FreeType(&library);

	return library;
}

long DestroyLibrary(Pointer library) {
	return FT_Done_FreeType(library);
} 

Pointer CreateFace(Pointer library, String path, long index) {
	FT_Face face;

	FT_New_Face(library, path, index, &face);

	
	return face;
}

long GetNumFaceGlyphs(Pointer face) {
	FT_Face f = (FT_Face)face;
	return f->num_glyphs;
}

short GetFaceAscender(Pointer face) {
	FT_Face f = (FT_Face)face;
	return f->ascender;
}

long SetCharSize(Pointer face, int width, int height, int horizontalRes, int verticalRes) {
	return FT_Set_Char_Size(face, width, height, horizontalRes, verticalRes);
}

long SetPixelSizes(Pointer face, int width, int height) {
	return FT_Set_Pixel_Sizes(face, width, height);
}

long GetCharIndex(Pointer face, long charcode) {
	return FT_Get_Char_Index(face, charcode);
}

long LoadGlyph(Pointer face, int glyphIndex, int32_t flags) {
	return FT_Load_Glyph(face, glyphIndex, FT_LOAD_DEFAULT);
}

int RenderGlyph(Pointer face, int renderMode) {
	FT_Face f = (FT_Face)face;
	return FT_Render_Glyph(f->glyph, FT_RENDER_MODE_NORMAL);
}

long GetGlyphHorizontalAdvance(Pointer face) {
	FT_Face f = (FT_Face)face;
	return f->glyph->advance.x;
}

long GetGlyphVerticalAdvance(Pointer face) {
	FT_Face f = (FT_Face)face;
	return f->glyph->advance.y;
}

long GetNumGlyphBitmapRows(Pointer face) {
	FT_Face f = (FT_Face)face;
	return f->glyph->bitmap.rows;
}

long GetGlyphBitmapWidth(Pointer face) {
	FT_Face f = (FT_Face)face;
	return f->glyph->bitmap.width;
}

Pointer GetGlyphBitmap(Pointer face) {
	FT_Face f = (FT_Face)face;
	
	return f->glyph->bitmap.buffer;
}

Pointer nFT_Init_FreeType() {
	FT_Library library;

	FT_Init_FreeType(&library);
}

void nFT_Done_FreeType(Pointer library) {
	return FT_Done_FreeType(library);
}

Pointer nFT_New_Face(Pointer library, String filepath, long index) {
	FT_Face face;

	FT_New_Face(library, filepath, index, &face);

	return face;
}

void nFT_Done_Face(Pointer face) {
	FT_Done_Face(face);
}

int nFT_Library_Version_Major(Pointer library) {
	int major;
	int* minor = malloc(sizeof(int));
	int* patch = malloc(sizeof(int));

	FT_Library_Version(library, &major, minor, patch);
	free(minor);
	free(patch);
	return major;
}

int nFT_Library_Version_Minor(Pointer library) {
	int minor;
	int* major = malloc(sizeof(int)), patch = malloc(sizeof(int));

	FT_Library_Version(library, major, &minor, patch);

	free(major);
	free(patch);
}

int nFT_Library_Version_Patch(Pointer library) {
	int patch;

	int* major = malloc(sizeof(int));
	int* minor = malloc(sizeof(int));

	FT_Library_Version(library, major, minor, &patch);
	free(major);
	free(minor);
	return patch;
}

Pointer nFT_New_Memory_Face(Pointer library, char* filecontents, long size, long index) {
	FT_Face face;

	FT_New_Memory_Face(library, filecontents, size, index, &face);

	return face;
}

void nFT_Library_Version(Pointer library, int* major, int* minor, int* patch) {
	FT_Library_Version(library, major, minor, patch);
}


void nFT_Set_Pixel_Sizes(Pointer face, int width, int height) {
	FT_Set_Pixel_Sizes(face, width, height);
}

void nFT_Load_Char(Pointer face, long codepoint, int flags) {
	FT_Load_Char(face, codepoint, flags);
}

Pointer nFT_Get_Bitmap(Pointer glyph) {
	return ((FT_GlyphSlot)glyph)->bitmap.buffer;
}

Pointer nFT_Get_Glyph(Pointer face) {
	FT_GlyphSlot glyph = (FT_GlyphSlot) ((FT_Face) face)->glyph;
	return glyph;
}

int nFT_Get_Glyph_Bitmap_Width(Pointer glyph) {
	FT_GlyphSlot ftglyph = (FT_GlyphSlot)glyph;
	return ftglyph->bitmap.width;
}

int nFT_Get_Glyph_Bitmap_Rows(Pointer glyph) {
	FT_GlyphSlot ftglyph = (FT_GlyphSlot)glyph;
	return ftglyph->bitmap.rows;
}

int nFT_Get_Glyph_Advance(Pointer glyph) {
	FT_GlyphSlot ftglyph = (FT_GlyphSlot)glyph;
	return ftglyph->advance.x;
}

int nFT_Get_Glyph_Bitmap_Left(Pointer glyph) {
	FT_GlyphSlot ftglyph = (FT_GlyphSlot)glyph;
	return ftglyph->bitmap_left;
}

int nFT_FT_Get_Glyph_Bitmap_Top(Pointer glyph) {
	FT_GlyphSlot ftglyph = (FT_GlyphSlot)glyph;
	return ftglyph->bitmap_top;
}
