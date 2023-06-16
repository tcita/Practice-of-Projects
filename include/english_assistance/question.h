#pragma once

#include <string>
#include <vector>
#include <set>

namespace english_assistance {
    namespace question {
        // Store needed information for testing panel question
        struct Question {
            std::string question;
            std::vector<std::string> candidateAnswers;
            std::set<int> answerIndexes;

            Question() = default;
            Question(const std::string &question, const std::vector<std::string> &candidateAnswers, const std::set<int> &answerIndexes);

            bool isValid() const;
            bool isMultipleChoiceQuestion() const;
            bool isSingleChoiceQuestion() const;
        };

        std::vector<Question> makeQuestions(const std::string &article);
    }
}