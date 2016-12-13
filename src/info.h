#ifndef __INFO_H
#define __INFO_H

#include "fs_api.h"

/* Print all the MAME info records */
void print_mame_info(FILE* out, const struct GameDriver* games[]);

#endif
