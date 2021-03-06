/* this is a local pdr s that are set up for linking in to the code
 * and used by the pdr managing routines */

#include "animinfo.h"
#include "errcodes.h"
#include "picdrive.h"
#include "picfile.h"
#include "pjbasics.h"

typedef struct picfile {
	Image_file ifile;
	Pic_header pic;
	XFILE *xf;
} Picfile;

static void close_picfile(Image_file **pif)
{
	Picfile *pf;

	if (!pj_assert(pif != NULL)) return;
	if (!pj_assert(*pif != NULL)) return;

	pf = (Picfile *)(*pif);
	xffclose(&pf->xf);
	pj_freez(pif);
}
static Errcode pic_read_first(Image_file *imf, Rcel *screen)
{
	Picfile *pf = (Picfile *)imf;

	return pj_read_picbody(pf->xf, &pf->pic, (Raster *)screen,screen->cmap);
}

static Errcode
open_picfile(Pdr *pd, char *path, Image_file **pif, Anim_info *ainfo)
{
	Picfile *pf;
	Errcode err;
	(void)pd;

	if (!pj_assert(pif != NULL)) return Err_bad_input;

	*pif = NULL;

	pf = pj_zalloc(sizeof(*pf));
	if (pf == NULL)
		return Err_no_memory;

	err = xffopen(path, &pf->xf, XREADONLY);
	if (err < Success)
		goto error;

	err = pj_read_pichead(pf->xf, &pf->pic);
	if (err < Success)
		goto error;

	if (ainfo) {
		clear_struct(ainfo);
		ainfo->x = pf->pic.x;
		ainfo->y = pf->pic.y;
		ainfo->width = pf->pic.width;
		ainfo->height = pf->pic.height;
		ainfo->depth = pf->pic.depth;
		ainfo->num_frames = 1;
	}

	*pif = &pf->ifile;
	return Success;

error:
	if (pf->xf != NULL)
		xffclose(&pf->xf);

	pj_free(pf);
	return err;
}

static char title_info[] = "\"PIC\" Uncompressed picture file.";


static Pdr pic_pdr_head = {
	{ REX_PICDRIVER, PDR_VERSION, NOFUNC, NOFUNC, NULL },
	title_info,  			/* title_info */
	NULL,  					/* long_info */
	".PIC",			 		/* default_suffi */
	1,1,					/* max_write_frames, max_read_frames */
	NOFUNC,					/* (*spec_best_fit)() */
	NOFUNC,					/* (*create_image_file)() */
	open_picfile,			/* (*open_image_file)() */
	close_picfile,			/* (*close_image_file)() */
	pic_read_first,			/* (*read_first_frame)() */
	NOFUNC,					/* (*read_delta_next)() */
	NOFUNC,	    			/* (*save_frames)() */
};

/* global items for outside */

char pic_pdr_name[] = "=PIC.PDR";
Local_pdr pic_local_pdr = {
	NULL,
	pic_pdr_name,
	&pic_pdr_head,
};


