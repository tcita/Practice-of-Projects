#include "Question.h"

Question::Question(const std::string &question, const std::vector<std::string> &candidateAnswers, const std::vector<int> &answerIndex)
  :question(question)
  ,candidateAnswers(candidateAnswers)
  ,answerIndex(answerIndex)
{

}

Question::Question(std::string &&question, std::vector<std::string> &&candidateAnswers, std::vector<int> &&answerIndex)
  :question(std::move(question))
  ,candidateAnswers(std::move(candidateAnswers))
  ,answerIndex(std::move(answerIndex))
{

}

bool Question::isValidQuestion()
{
  if((question.size() > 0) && (candidateAnswers.size() > 0) && (answerIndex.size() > 0))
  {
    return true;
  }

  return false;
}

bool Question::isSingleChoiceQuestion()
{
  if(!isValidQuestion())
  {
    return false;
  }

  if(correctAnswerIndex.size() == 1)
  {
    return true;
  }

  return false;
}

bool Question::isMultipleChoiceQuestion()
{
  if(!isValidQuestion())
  {
    return false;
  }

  if(correctAnswerIndex.size() > 1)
  {
    return true;
  }

  return false;
}
