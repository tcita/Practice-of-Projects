#include "Crawler.h"
#include <cstdio>
#include <memory>

std::string Crawler::getArticle(const std::string &articleType)
{
  std::string command = "java -jar ./lib/crawler/crawler.jar " + articleType;
  std::unique_ptr<FILE, decltype(&pclose)> dataStream(popen(command.c_str(), "r"), pclose);

  std::string data;
  char buffer[5000];
  while(std::fgets(buffer, 5000, dataStream.get()))
  {
    data += buffer;
  }

  return data;
}
