add_definitions(-DCLIB_MEMORY)

## very low level utilities, assembler interfaces etc
set(LOWUTIL_SRC_FILES
	dosecode.c
	i86dswap.c
	i86swap.c
	pjassert.c
	ptrenorm.c
	)

## temporary file system compatible memory management
set(MEMC_SRC_FILES
	memalloc.c
	memcask.c
	memclow.c
	)

## basic memory oriented utilities
set(MEM_SRC_FILES
	blockall.c
	membkcpy.c
	membnon0.c
	memcask.c
	memcrc.c
	memeallo.c
	memfreez.c
	memgfree.c
	memnulod.c
	mempeek.c
	mempoke.c
	memswap.c
	memzero.c
	)

## string and data oriented utilities
set(STR_SRC_FILES
	newname.c
	parsemi.c
	strclone.c
	strcrc.c
	textutil.c
	trstring.c
	txtcmp.c
	txtncmp.c
	upc.c
	wildcmp.c
	)

## string formatting utilities sprintf and the like
set(FORMATF_SRC_FILES
	folenf.c
	fonsprtf.c
	formatf.c
	formatxt.c
	forparse.c
	ftextf.c
	ftextfmt.c
	snftextf.c
	vnftextf.c
	)

## linked list utilities including a shell sort
set(LINKLIST_SRC_FILES
	argparse.c
	dlist.c
	dlclone.c
	dlfndhdr.c
	dlinscmp.c
	dlisort.c
	dlistlen.c
	dlremnod.c
	dlswap.c
	nalngest.c
	namein.c
	namesort.c
	shelsort.c
	slist.c
	slrevers.c
	slstsort.c
	textin.c
	)

## integer and fixed point math utilities
set(IMATH_SRC_FILES
	imclcdst.c
	imlcmult.c
	imptlrot.c
	imrotate.c
	imrsclby.c
	imsincos.c
	imsqroot.c
	imssclby.c
	imusclby.c
	imintmin.c
	imintmax.c
	imintabs.c
	fixpoint.c
	)

## floating point math utilities
set(FMATH_SRC_FILES
	fmath.c
	)

## utilities library with all modules and temp file (trd) memory allocation
add_library(trdutil
	${FMATH_SRC_FILES}
	${FORMATF_SRC_FILES}
	${IMATH_SRC_FILES}
	${LINKLIST_SRC_FILES}
	${LOWUTIL_SRC_FILES}
	${MEMC_SRC_FILES}
	${MEM_SRC_FILES}
	${STR_SRC_FILES})
