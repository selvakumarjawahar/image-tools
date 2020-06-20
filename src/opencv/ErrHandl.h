//
// Created by selva on 6/20/20.
//
#include <string>
#include <string_view>

#ifndef IMAGE_TOOLS_ERRHANDL_H
#define IMAGE_TOOLS_ERRHANDL_H

struct PanaromaExceptions {
  explicit PanaromaExceptions(std::string_view err_msg):errMsg{err_msg}{}
  std::string errMsg;
};
#endif // IMAGE_TOOLS_ERRHANDL_H
