#include "read_md.hpp"

int read_md(const char* filename){
	printf("%s\n",filename);
	AVFormatContext* fmt_ctx = NULL;//the file
	const AVDictionaryEntry* tag = NULL;//dict of tags
	int ret;//error codes

	if ((ret = avformat_open_input(&fmt_ctx, filename, NULL, NULL))){
		printf("%d : Failed to Open File\n",ret);
		return ret;
	}

	if ((ret = avformat_find_stream_info(fmt_ctx,NULL) < 0)){
		av_log(NULL, AV_LOG_ERROR, "Cannot find stream information\n");
		return ret;
	}

//	while ((tag =av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))){
	while ((tag =av_dict_get(fmt_ctx->metadata, "ARTIST", tag, AV_DICT_IGNORE_SUFFIX))){
		printf("%s=%s\n",tag->key, tag->value);
	}

	avformat_close_input(&fmt_ctx);

	return 0;
}
