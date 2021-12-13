#include "Crawler.h"
#include <iostream>
#include <cstdio>
// #include <cstdlib>
#include <memory>

std::string Crawler::getArticle()
{
  const char *COMMAND = "java -jar ./lib/crawler/crawler.jar";
  std::unique_ptr<FILE, decltype(&pclose)> dataStream(popen(COMMAND, "r"), pclose);

  std::string data;
  char buffer[100];
  while(std::fgets(buffer, 100, dataStream.get()))
  {
    data += buffer;
  }

  return data;
}

std::string Crawler::getRandomArticle()
{
  return getArticle();
}
