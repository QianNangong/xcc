#pragma once

#include "cc_file_sh.h"
#include "cc_structures.h"
#include "virtual_image.h"

class Ctga_file: public Ccc_file_sh<t_tga_header>
{
public:
	int decode(Cvirtual_image& d) const;
	bool is_valid() const;

	int cx() const
	{
		return get_header()->cx;
	}

	int cy() const
	{
		return get_header()->cy;
	}

	int cb_pixel() const
	{
		return get_header()->cb_pixel >> 3;
	}

	const byte* image() const
	{
		return get_data() + sizeof(t_tga_header) + get_header()->id_size;
	}
};

Cvirtual_file tga_file_write(const byte* image, int cx, int cy, int cb_pixel);
Cvirtual_file tga_file_write(const byte* image, int cx, int cy, const t_palet_entry* palet);
