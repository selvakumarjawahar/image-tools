//
// Created by selva on 6/20/20.
//
#include <opencv2/opencv.hpp>
#include <vector>
#include <string_view>
#include <fmt/format.h>
#include <filesystem>

#include "ErrHandl.h"

#ifndef IMAGE_TOOLS_PANAROMA_H
#define IMAGE_TOOLS_PANAROMA_H

class Panaroma {
public:
  Panaroma() : divideImage{false}, mode{cv::Stitcher::SCANS} {}
  Panaroma(bool divide_image, cv::Stitcher::Mode mode)
      : divideImage{divide_image}, mode{mode} {}
  void inputImages(const std::vector<std::string_view>& image_paths);
  void setPanaromaOutput(std::string_view ouput_path,
                         std::string_view output_filename);
  void CreatePanaroma();



private:
  bool divideImage;
  cv::Stitcher::Mode mode;
  std::vector<cv::Mat> images;
  std::filesystem::path outputPath;


};

#endif // IMAGE_TOOLS_PANAROMA_H
