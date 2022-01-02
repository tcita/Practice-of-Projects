#ifndef QUESTION_H
#define QUESTION_H

struct Question
{
  std::string question;
  std::vector<std::string> candidateAnswers;
  std::vector<int> answerIndex;

  Question() = default;
  Question(const std::string &question, const std::vector<std::string> &candidateAnswers, const std::vector<int> &answerIndex);
  Question(std::string &&question, std::vector<std::string> &&candidateAnswers, std::vector<int> &&answerIndex);

  bool isValidQuestion();
  bool isMultipleChoiceQuestion();
  bool isSingleChoiceQuestion();
};

#endif
