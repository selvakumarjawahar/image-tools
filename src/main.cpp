
#include <drogon/drogon.h>

int main(int argc, char** argv) {
  drogon::app().setDocumentRoot("/home/selva/Projects/image-tools/src/drogon/static")
      .setLogLevel(trantor::Logger::kWarn)
      .addListener("0.0.0.0", 8000)
      .setThreadNum(4)
      .enableRunAsDaemon()
      .run();
}
