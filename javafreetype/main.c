#include "jfreetype.h"
#include <stdio.h>

int main() {
	FT_Library library;
	FT_Face face;

	FT_Init_FreeType(&library);

	FT_New_Face(library, "C:/Windows/Fonts/arial.ttf", 0, &face);

	printf("Number of glyphs: %i\n", face->num_glyphs);

	Pointer library1 = CreateLibrary();

	Pointer face1 = CreateFace(library1, "C:/Windows/Fonts/arial.ttf", 0);

	printf("Number of glyphs: %i\n", GetNumFaceGlyphs(face1));

	FT_Load_Char(face, 'a', FT_LOAD_RENDER);
	LoadGlyph(face, GetCharIndex(face, 'a'), 0);
	Pointer bitmap = GetGlyphBitmap(face);

	if (bitmap == NULL)
		printf("Error\n");
	
	int ret = RenderGlyph(face, 0);

	if (ret != FT_Err_Ok) {
		printf("Error rasterizing\n");
	}
	if (bitmap == NULL)
		printf("Error!\n");
		
	if (ret == 0x60) {
		printf("Error: raster uninitialized\n");
	}

	if (ret == 0x61) {
		printf("Error: raster corrupted\n");
	}

	if (ret == 0x62) {
		printf("Error: raster overflow\n");
	}

	if (ret == 0x63) {
		printf("Error: raster negative height\n");
	}

	
	printf("Error code: %d\n", ret);
	return 0;
}