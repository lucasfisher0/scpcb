// ==========================================================
// Bitmap conversion routines
//
// Design and implementation by
// - Floris van den Berg (flvdberg@wxs.nl)
// - Herv� Drolon (drolon@iut.univ-lehavre.fr)
// - Jani Kajala (janik@remedy.fi)
//
// This file is part of FreeImage 2
//
// COVERED CODE IS PROVIDED UNDER THIS LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTY
// OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, WITHOUT LIMITATION, WARRANTIES
// THAT THE COVERED CODE IS FREE OF DEFECTS, MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE
// OR NON-INFRINGING. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE COVERED
// CODE IS WITH YOU. SHOULD ANY COVERED CODE PROVE DEFECTIVE IN ANY RESPECT, YOU (NOT
// THE INITIAL DEVELOPER OR ANY OTHER CONTRIBUTOR) ASSUME THE COST OF ANY NECESSARY
// SERVICING, REPAIR OR CORRECTION. THIS DISCLAIMER OF WARRANTY CONSTITUTES AN ESSENTIAL
// PART OF THIS LICENSE. NO USE OF ANY COVERED CODE IS AUTHORIZED HEREUNDER EXCEPT UNDER
// THIS DISCLAIMER.
//
// Use at your own risk!
// ==========================================================

#include "FreeImage.h"
#include "Utilities.h"

// ----------------------------------------------------------

#define RGB555(r, g, b) (((r) >> 3) | (((g) >> 3) << 5) | (((b) >> 3) << 10))

// ----------------------------------------------------------
//  internal conversions X to 16 bits (555)
// ----------------------------------------------------------

void DLL_CALLCONV
FreeImage_ConvertLine1To16_555(BYTE *target, BYTE *source, int width_in_pixels, RGBQUAD *palette) {
	WORD *new_bits = (WORD *)target;

	for (int cols = 0; cols < width_in_pixels; cols++) {
		int index = (source[cols >> 3] & (0x80 >> (cols & 0x07))) != 0 ? 1 : 0;

		new_bits[cols] = RGB555(palette[index].rgbBlue, palette[index].rgbGreen, palette[index].rgbRed);
	}
}

void DLL_CALLCONV
FreeImage_ConvertLine4To16_555(BYTE *target, BYTE *source, int width_in_pixels, RGBQUAD *palette) {
	WORD *new_bits = (WORD *)target;
	BOOL lonibble = FALSE;
	int x = 0;

	for (int cols = 0; cols < width_in_pixels; cols++) {
		RGBQUAD *grab_palette;

		if (lonibble) {
			grab_palette = palette + LOWNIBBLE(source[x++]);
		} else {
			grab_palette = palette + (HINIBBLE(source[x]) >> 4);
		}

		new_bits[cols] = RGB555(grab_palette->rgbBlue, grab_palette->rgbGreen, grab_palette->rgbRed);

		lonibble = !lonibble;
	}
}

void DLL_CALLCONV
FreeImage_ConvertLine8To16_555(BYTE *target, BYTE *source, int width_in_pixels, RGBQUAD *palette) {
	WORD *new_bits = (WORD *)target;

	for (int cols = 0; cols < width_in_pixels; cols++) {
		RGBQUAD *grab_palette = palette + source[cols];

		new_bits[cols] = RGB555(grab_palette->rgbBlue, grab_palette->rgbGreen, grab_palette->rgbRed);
	}
}

void DLL_CALLCONV
FreeImage_ConvertLine16_565_To16_555(BYTE *target, BYTE *source, int width_in_pixels) {
	WORD *src_bits = (WORD *)source;
	WORD *new_bits = (WORD *)target;

	for (int cols = 0; cols < width_in_pixels; cols++) {
		new_bits[cols] = RGB555((((src_bits[cols] & 0x7C00) >> 10) * 0xFF) / 0x1F,
			                    (((src_bits[cols] & 0x3E0) >> 5) * 0xFF) / 0x1F,
								((src_bits[cols] & 0x1F) * 0xFF) / 0x1F);
	}
}

void DLL_CALLCONV
FreeImage_ConvertLine24To16_555(BYTE *target, BYTE *source, int width_in_pixels) {
	WORD *new_bits = (WORD *)target;

	for (int cols = 0; cols < width_in_pixels; cols++) {
		new_bits[cols] = RGB555(source[0], source[1], source[2]);

		source += 3;
	}
}

void DLL_CALLCONV
FreeImage_ConvertLine32To16_555(BYTE *target, BYTE *source, int width_in_pixels) {
	WORD *new_bits = (WORD *)target;

	for (int cols = 0; cols < width_in_pixels; cols++) {
		new_bits[cols] = RGB555(source[0], source[1], source[2]);

		source += 4;
	}
}

// ----------------------------------------------------------
//   smart convert X to 16 bits
// ----------------------------------------------------------

FIBITMAP * DLL_CALLCONV
FreeImage_ConvertTo16Bits555(FIBITMAP *dib) {
	if (dib != NULL) {
		int width = FreeImage_GetWidth(dib);
		int height = FreeImage_GetHeight(dib);

		switch (FreeImage_GetBPP(dib)) {
			case 1 :
			{
				FIBITMAP *new_dib = FreeImage_Allocate(width, height, 16, 0x1F, 0x3E0, 0x7C00);

				if (new_dib) {
					for (int rows = 0; rows < height; rows++)
						FreeImage_ConvertLine1To16_555(FreeImage_GetScanLine(new_dib, rows), FreeImage_GetScanLine(dib, rows), width, FreeImage_GetPalette(dib));

					return new_dib;
				}

				break;
			}

			case 4 :
			{
				FIBITMAP *new_dib = FreeImage_Allocate(width, height, 16, 0x1F, 0x3E0, 0x7C00);

				if (new_dib) {
					for (int rows = 0; rows < height; rows++)
						FreeImage_ConvertLine4To16_555(FreeImage_GetScanLine(new_dib, rows), FreeImage_GetScanLine(dib, rows), width, FreeImage_GetPalette(dib));

					return new_dib;
				}

				break;
			}

			case 8 :
			{
				FIBITMAP *new_dib = FreeImage_Allocate(width, height, 16, 0x1F, 0x3E0, 0x7C00);

				if (new_dib) {
					for (int rows = 0; rows < height; rows++)
						FreeImage_ConvertLine8To16_555(FreeImage_GetScanLine(new_dib, rows), FreeImage_GetScanLine(dib, rows), width, FreeImage_GetPalette(dib));

					return new_dib;
				}

				break;
			}

			case 16 :
			{

				FIBITMAP *new_dib = FreeImage_Allocate(width, height, 16, 0x1F, 0x3E0, 0x7C00);

				if (new_dib) {
					for (int rows = 0; rows < height; rows++)
						FreeImage_ConvertLine16_565_To16_555(FreeImage_GetScanLine(new_dib, rows), FreeImage_GetScanLine(dib, rows), width);

					return new_dib;
				}

				break;
			}

			case 24 :
			{
				FIBITMAP *new_dib = FreeImage_Allocate(width, height, 16, 0x1F, 0x3E0, 0x7C00);

				if (new_dib) {
					for (int rows = 0; rows < height; rows++)
						FreeImage_ConvertLine24To16_555(FreeImage_GetScanLine(new_dib, rows), FreeImage_GetScanLine(dib, rows), width);

					return new_dib;
				}

				break;
			}

			case 32 :
			{
				FIBITMAP *new_dib = FreeImage_Allocate(width, height, 16, 0x1F, 0x3E0, 0x7C00);

				if (new_dib) {
					for (int rows = 0; rows < height; rows++)
						FreeImage_ConvertLine32To16_555(FreeImage_GetScanLine(new_dib, rows), FreeImage_GetScanLine(dib, rows), width);

					return new_dib;
				}

				break;
			}
		}
	}

	return NULL;
}
