#ifndef TESTING_RESULT_H
#define TESTING_RESULT_H

#include "Question.h"

struct TestingResult : public Question
{
  std::set<int> choosedAnswerIndexes;

  TestingResult(const std::string &question, const std::vector<std::string> &candidateAnswers, const std::set<int> &answer, const std::set<int> &choosedAnswerIndexes);
  TestingResult(std::string &&question, std::vector<std::string> &&candidateAnswers, std::set<int> &&answer, std::set<int> &&choosedAnswerIndexses);
  TestingResult(const Question &question, const std::set<int> &choosedAnswerIndexes);
};

#endif
