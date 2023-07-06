#include <iostream>
#include <ffmpeg.h>

void decode_video(const char* input_file, const char* output_file) {
  // Create a format context object from the input file
  AVFormatContext* input_format = nullptr;
  if (avformat_open_input(&input_format, input_file, nullptr, nullptr) < 0) {
    std::cerr << "Could not open input file\n";
    return;
  }
  // Find the stream information for the input format
  if (avformat_find_stream_info(input_format, nullptr) < 0) {
    std::cerr << "Could not find stream information\n";
    return;
  }
  // Find the index of the first video stream in the input format
  int video_stream_index = -1;
  for (int i = 0; i < input_format->nb_streams; i++) {
    if (input_format->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
      video_stream_index = i;
      break;
    }
  }
  if (video_stream_index == -1) {
    std::cerr << "Could not find video stream\n";
    return;
  }
  // Get the codec parameters for the video stream
  AVCodecParameters* video_codec_params = input_format->streams[video_stream_index]->codecpar;
  // Find the decoder for the video stream
  AVCodec* video_decoder = avcodec_find_decoder(video_codec_params->codec_id);
  if (video_decoder == nullptr) {
    std::cerr << "Could not find decoder\n";
    return;
  }
  // Create a codec context object for the video stream
  AVCodecContext* video_codec_context = avcodec_alloc_context3(video_decoder);
  if (video_codec_context == nullptr) {
    std::cerr << "Could not allocate codec context\n";
    return;
  }
  // Copy the codec parameters to the codec context
  if (avcodec_parameters_to_context(video_codec_context, video_codec_params) < 0) {
    std::cerr << "Could not copy codec parameters\n";
    return;
  }
  // Open the codec context
  if (avcodec_open2(video_codec_context, video_decoder, nullptr) < 0) {
    std::cerr << "Could not open codec context\n";
    return;
  }
  // Create a packet object to hold the encoded data
  AVPacket* packet = av_packet_alloc();
  if (packet == nullptr) {
    std::cerr << "Could not allocate packet\n";
    return;
  }
  // Create a frame object to hold the decoded data
  AVFrame* frame = av_frame_alloc();
  if (frame == nullptr) {
    std::cerr << "Could not allocate frame\n";
    return;
  }
  // Create a format context object for the output file
  AVFormatContext* output_format = nullptr;
  if (avformat_alloc_output_context2(&output_format, nullptr, nullptr, output_file) < 0) {
    std::cerr << "Could not allocate output context\n";
    return;
  }
  // Add a new stream to the output format with the same codec parameters as the input video stream
  AVStream* output_stream = avformat_new_stream(output_format, nullptr);
  if (output_stream == nullptr) {
    std::cerr << "Could not create output stream\n";
    return;
  }
  


