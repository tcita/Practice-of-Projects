#include "Question.h"

Question::Question(const std::string &question, const std::vector<std::string> &candidateAnswers, const std::set<int> &answerIndexes)
    :question(question)
    ,candidateAnswers(candidateAnswers)
    ,answerIndexes(answerIndexes) {

}

Question::Question(std::string &&question, std::vector<std::string> &&candidateAnswers, std::set<int> &&answerIndexes)
    :question(std::move(question))
    ,candidateAnswers(std::move(candidateAnswers))
    ,answerIndexes(std::move(answerIndexes)) {

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
