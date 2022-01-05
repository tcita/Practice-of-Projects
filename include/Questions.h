#ifndef QUESTIONS_H
#define QUESTIONS_H

#include "Question.h"

#include <vector>

// Helper functions for question
namespace Questions
{
  std::vector<Question> makeQuestions(const std::string &article);
};

#endif
