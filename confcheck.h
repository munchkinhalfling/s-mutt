#include "config.h"
#if HAVE_MALLOC == 0
#error Must have malloc
#endif
#if HAVE_LIBNCURSES == 0
#error Must have nCurses
#endif