#ifndef QUESTIONS_H
#define QUESTIONS_H

#include "Question.h"

#include <vector>

namespace Questions
{
  std::vector<Question> makeQuestions(const std::string &article);
};

#endif
