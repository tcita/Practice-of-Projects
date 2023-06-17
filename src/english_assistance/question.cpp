#include <iostream>
#include <random>
#include <string>

#include "english_assistance/config.h"
#include "english_assistance/question.h"
#include "english_assistance/util.h"

namespace english_assistance {
    namespace question {
        Question::Question(const std::string &question, const std::vector<std::string> &candidateAnswers, const std::set<int> &answerIndexes)
            :question(question)
            ,candidateAnswers(candidateAnswers)
            ,answerIndexes(answerIndexes) {

        }

        bool Question::isValid() const {
            if((question.size() > 0) && (candidateAnswers.size() > 0) && (answerIndexes.size() > 0)) {
                return true;
            }

            return false;
        }

        bool Question::isSingleChoiceQuestion() const {
            if(!isValid()) {
                return false;
            }

            if(answerIndexes.size() == 1) {
                return true;
            }

            return false;
        }

        bool Question::isMultipleChoiceQuestion() const
        {
            if(!isValid()) {
                return false;
            }

            if(answerIndexes.size() > 1) {
                return true;
            }

            return false;
        }
        
        std::vector<Question> makeQuestions(const std::string &article) {
            std::vector<Question> questions;
            std::vector<std::pair<std::string,int>> wordFrequencies = util::wordFrequency(article, config::readBannedWords());

            // Remove return character from article
            // From: https://en.cppreference.com/w/cpp/algorithm/remove
            // std::string noReturnArticle = std::remove(article.begin(), article.end(), '\n');
            std::string noReturnArticle;
            for(const std::string &sentence : util::split(article, '\n')) {
                noReturnArticle += sentence;
            }

            std::vector<std::string> candidateQuestions = util::split(noReturnArticle, '.');

            // Get distribute
            // From: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution/
            std::random_device randomDevice;
            std::mt19937 seedGenerator(randomDevice());
            std::uniform_int_distribution<int> answerDistribute(0, 4);
            std::uniform_int_distribution<int> wordFrequenciesDistribute(0, wordFrequencies.size());

            for(const std::string &candidateQuestion : candidateQuestions) {
                for(const std::pair<std::string, int>  &wordFrequency : wordFrequencies) {
                    // std::cout << wordFrequency.first << "\n\n";
                    std::size_t wordIndex = candidateQuestion.find(std::string(" ") + wordFrequency.first + std::string(" "));
                    if(wordIndex != std::string::npos) {
                        ++wordIndex;
                        std::cout << candidateQuestion << "\n" << wordFrequency.first << "\n";
                        // std::cout << wordIndex << "\n"; //debug

                        std::string modifiedQuestion = candidateQuestion + ".";
                        modifiedQuestion.erase(wordIndex, wordFrequency.first.size());
                        modifiedQuestion.insert(wordIndex, "_____");

                        Question question;
                        question.question = modifiedQuestion;
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
                                while(fakeAnswer == wordFrequency.first)
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

            return questions;
        }
    }
}