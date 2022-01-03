#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <set>

struct Question
{
  std::string question;
  std::vector<std::string> candidateAnswers;
  std::set<int> answerIndexes;

  Question() = default;
  Question(const std::string &question, const std::vector<std::string> &candidateAnswers, const std::set<int> &answerIndexes);
  Question(std::string &&question, std::vector<std::string> &&candidateAnswers, std::set<int> &&answerIndexes);

  bool isValidQuestion() const;
  bool isMultipleChoiceQuestion() const;
  bool isSingleChoiceQuestion() const;
};

#endif
