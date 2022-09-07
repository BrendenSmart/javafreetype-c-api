#include "jfreetype.h"

Pointer CreateLibrary() {
	FT_Library library;

	FT_Init_FreeType(&library);

	return library;
}

long DestroyLibrary(Pointer library) {
	return FT_Done_FreeType(library);
} 

Pointer CreateFace(Pointer library, string path, long index) {
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

