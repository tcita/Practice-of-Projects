#include <iostream>

#include <nlohmann/json.hpp>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>

#include "english_assistance/translate.h"

namespace english_assistance {
    namespace translate {
        std::string translate(const std::string &input, const std::string &destLanguageType, const std::string &srcLanguageType) {
            // Create google translate url
            // From: https://stackoverflow.com/questions/8085743/google-translate-vs-translate-api
            // From: https://stackoverflow.com/questions/8550147/how-to-use-google-translate-api-with-c
            // From: https://blog.csdn.net/panshiqu/article/details/104193607
            std::string clientType = std::string("client=") + std::string("gtx");
            // std::string clientType = std::string("client=") + std::string("at");
            std::string sourceLanguageType = std::string("sl=") + srcLanguageType;
            std::string targetLanguageType = std::string("tl=") + destLanguageType;
            std::string queryText = std::string("q=") + input;
            std::string onlyReplyTranslateResult = std::string("dt=") + std::string("t");

            std::string url = std::string("https://translate.googleapis.com/translate_a/single");
            url += "?" + clientType + "&" + sourceLanguageType + "&" + targetLanguageType + "&" + queryText + "&" + onlyReplyTranslateResult;

            // Request and get reply data
            QNetworkAccessManager networkAccessManager;
            QNetworkReply *networkReply = networkAccessManager.get(QNetworkRequest(QString::fromStdString(url)));

            // Wait for network reply finished
            QEventLoop waitForNetworkReply;
            QObject::connect(networkReply, &QNetworkReply::finished, [&]{waitForNetworkReply.quit();});
            waitForNetworkReply.exec();

            // Put reply data to string
            std::string replyData = networkReply->readAll().toStdString();

            // Check if it is a valid Json
            if(!nlohmann::json::accept<std::string>(std::move(replyData))) {
                std::cerr << "online_translator::translate() failed, the reply data is not valid Json.\n";
                return {};
            }
            
            // Parse json data by using nlohmann_json api
            auto jsonData = nlohmann::json::parse(replyData);

            // Get translated string
            std::string translatedString;
            for(std::size_t i = 0; i < jsonData[0].size(); ++i) {
                translatedString += jsonData[0][i][0];
            }

            return translatedString;
        }
    }
}