#ifndef FFMPEG_H
#define FFMPEG_H

#define AV_LOG_QUIET -8
#define AV_LOG_PANIC 0
#define AV_LOG_FATAL 8
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_LOG_INFO 32
#define AV_LOG_VERBOSE 40
#define AV_LOG_DEBUG 48
#define AV_LOG_TRACE 56

// Mirrors the part of FFmpeg's AVPixelFormat that bindgen needs to name. The
// upstream enum is append-only, and util.cpp static-asserts these against the
// real macros, so a drift between the two is a build error rather than a
// silently misformatted frame.
enum AVPixelFormat {
  AV_PIX_FMT_YUV420P = 0,
  AV_PIX_FMT_YUV444P = 5,
  AV_PIX_FMT_NV12 = 23,
  AV_PIX_FMT_YUV420P10LE = 62,
  AV_PIX_FMT_YUV444P10LE = 68,
  AV_PIX_FMT_P010LE = 158,
};

int av_log_get_level(void);
void av_log_set_level(int level);
void hwcodec_set_av_log_callback();
void hwcodec_set_flag_could_not_find_ref_with_poc();

#endif