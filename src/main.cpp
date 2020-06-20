
#include <vector>
#include <string_view>
#include <exception>

#include "ErrHandl.h"
#include "Panaroma.h"

int main(int argc, char** argv) {

  Panaroma panaroma;
  if(argc < 3){
    fmt::print("{} <image1> <image2> ...\n",argv[0]);
    fmt::print("Provide Atleast 2 Images\n");
    return 0;
  }
  std::vector<std::string_view> input_imgaes;
  for(int i=1;i<argc;++i){
    input_imgaes.push_back(argv[i]);
  }
  try{
    panaroma.inputImages(input_imgaes);
    panaroma.CreatePanaroma();
  }
  catch(PanaromaExceptions pan_err){
    fmt::print("Error {}\n",pan_err.errMsg);
  }
  catch (std::exception err) {
    fmt::print("Error {}\n",err.what());
  }
  catch(...){
    fmt::print("Unknown Error\n");
  }
  return 0;
}
