#include "Crawler.h"
#include <cstdio>
#include <memory>

std::string Crawler::getArticle(const std::string &articleType)
{
  // popen: https://stackoverflow.com/questions/8538324/what-is-the-difference-between-popen-and-system-in-c
  std::string command = "java -jar ./lib/crawler/crawler.jar " + articleType;
  std::unique_ptr<FILE, decltype(&pclose)> dataStream(popen(command.c_str(), "r"), &pclose);

  std::string data;
  
  // FILE to std::string: https://stackoverflow.com/questions/10667972/c-popens-output-to-a-string
  const int BUFFER_SIZE = 5000;
  char buffer[BUFFER_SIZE];
  while(std::fgets(buffer, BUFFER_SIZE, dataStream.get()))
  {
    data += buffer;
  }

  return data;
}
