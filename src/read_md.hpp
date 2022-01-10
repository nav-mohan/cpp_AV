#include <stdio.h>

extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/dict.h>
}

int read_md(const char* filename);
