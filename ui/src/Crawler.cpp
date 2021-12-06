#include "Crawler.h"
#include <iostream>
#include <cstdio>
// #include <cstdlib>
#include <memory>

std::string Crawler::getArtical()
{
  const char *COMMAND = "java -jar crawler.jar";
  std::unique_ptr<FILE, decltype(&pclose)> dataStream(popen(COMMAND, "r"), pclose);

  std::string data;
  char buffer[100];
  while(std::fgets(buffer, 100, dataStream.get()))
  {
    data += buffer;
  }
  
  return data;
}
