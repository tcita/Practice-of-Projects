#include "Questions.h"
#include "Config.h"
#include "Strings.h"
#include "Solution.h"

#include <random>
#include <iostream>
#include <algorithm>

std::vector<Question> Questions::makeQuestions(const std::string &article)
{
  std::vector<Question> questions;

  std::vector<std::pair<std::string,int>> wordFrequencies = Solution::wordFrequency(article, Config::getBannedWords());

  // Remove return character from article
  // From: https://en.cppreference.com/w/cpp/algorithm/remove
  // std::string noReturnArticle = std::remove(article.begin(), article.end(), '\n');
  std::string noReturnArticle;
  for(const std::string &sentence : Strings::splitString(article, '\n'))
  {
    noReturnArticle += sentence;
  }

  std::vector<std::string> candidateQuestions = Strings::splitString(noReturnArticle, '.');


  // Get distribute
  // From: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution/
  std::random_device randomDevice;
  std::mt19937 seedGenerator(randomDevice());
  std::uniform_int_distribution<int> answerDistribute(0, 4);
  std::uniform_int_distribution<int> wordFrequenciesDistribute(0, wordFrequencies.size());

  for(const std::string &candidateQuestion : candidateQuestions)
  {
    for(const std::pair<std::string, int>  &wordFrequency : wordFrequencies)
    {
      if(candidateQuestion.find(wordFrequency.first))
      {
        Question question;
        question.question = candidateQuestion;
        int answerIndex = answerDistribute(seedGenerator);
        question.answerIndexes.insert(answerIndex);

        for(auto i = 0; i < 4; ++i)
        {
          if(i == answerIndex)
          {
            // put in real answer
            question.candidateAnswers.push_back(wordFrequency.first);
          }
          else
          {
            // put in fake answer
            std::string fakeAnswer = wordFrequencies[wordFrequenciesDistribute(seedGenerator)].first;
            while(fakeAnswer != wordFrequency.first)
            {
              fakeAnswer = wordFrequencies[wordFrequenciesDistribute(seedGenerator)].first;
            }
            question.candidateAnswers.push_back(fakeAnswer);
          }
        }
        questions.push_back(question);

        break;
      }
    }
  }

  return questions; //debug
}
