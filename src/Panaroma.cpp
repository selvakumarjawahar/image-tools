//
// Created by selva on 6/20/20.
//

#include "Panaroma.h"

void Panaroma::inputImages(const std::vector<std::string_view>& image_paths) {
  for(auto& elem: image_paths){
    cv::Mat img = cv::imread(elem.data());
    if(img.empty()){
      fmt::print("Cannot Load Image from {}\t Skipping Image ",
                 elem.data());
      throw PanaromaExceptions{"Cannot Load Image"};
    }
    if (divideImage)
    {
      cv::Rect rect(0, 0, img.cols / 2, img.rows);
      images.push_back(img(rect).clone());
      rect.x = img.cols / 3;
      images.push_back(img(rect).clone());
      rect.x = img.cols / 2;
      images.push_back(img(rect).clone());
    }
    else
      images.push_back(img);
  }
  return;
}

void Panaroma::setPanaromaOutput(std::string_view ouput_path,
                                 std::string_view output_filename) {
  outputPath.clear();
  outputPath += ouput_path;
  outputPath += output_filename;
}

void Panaroma::CreatePanaroma() {
  cv::Mat pano_img;
  cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(mode);
  fmt::print("Number of images to stitch = {}\n",images.size());
  cv::Stitcher::Status status = stitcher->stitch(images,pano_img);
  if (status != cv::Stitcher::OK)
  {
    fmt::print("Can't stitch images, error code = {}\n",int(status));
    throw PanaromaExceptions{"Can't stitch images"};
  }
  if(!outputPath.empty())
    cv::imwrite(outputPath.string(),pano_img);
  else
    cv::imwrite("result.jpg",pano_img);
}