#include <iostream>
#include <random>
#include <thread>

#include <QtWidgets>

#include "english_assistance/config.h"
#include "english_assistance/info.h"
#include "english_assistance/lang.h"
#include "english_assistance/question.h"
#include "english_assistance/translate.h"
#include "english_assistance/ui/main_window.h"
#include "english_assistance/util.h"
#include "english_assistance/ui/xpm.h"

namespace english_assistance {
    namespace ui {
        namespace main_window {
            MainWindow::MainWindow(QTranslator *translator, Crawler *crawler)
                :translator(translator)
                ,crawler(crawler) {
                /******************************************************************************************
                * Init member
                ******************************************************************************************/
                // Menu
                mainMenuBar = this->menuBar();
                previousPanelAction = new QAction(mainMenuBar);
                settingMenu = new QMenu(mainMenuBar);
                languageMenu = new QMenu(settingMenu);
                enUsAction = new QAction(languageMenu);
                zhCnAction = new QAction(languageMenu);
                zhTwAction = new QAction(languageMenu);
                panelMenu = new QMenu(mainMenuBar);
                translateWindowAction = new QAction(panelMenu);
                switchToMenu = new QMenu(panelMenu);
                mainPanelAction = new QAction(switchToMenu);
                articleTypePanelAction = new QAction(switchToMenu);
                typingPanelAction = new QAction(switchToMenu);
                translatePanelAction = new QAction(switchToMenu);
                helpMenu = new QMenu(mainMenuBar);
                aboutAction = new QAction(helpMenu);

                // Translate window
                translateWindow = new QWidget();
                translateWindowLayout = new QGridLayout(translateWindow);
                translateWindowSrcGroupBox = new QGroupBox();
                translateWindowSrcGroupBoxLayout = new QVBoxLayout(translateWindowSrcGroupBox);
                translateWindowSrcTextEdit = new QTextEdit();
                translateWindowMidWidget = new QWidget();
                translateWindowMidWidgetLayout = new QVBoxLayout(translateWindowMidWidget);
                translateWindowToDestButton = new QPushButton(">>");
                translateWindowToSrcButton = new QPushButton("<<");
                translateWindowDestGroupBox = new QGroupBox();
                translateWindowDestGroupBoxLayout = new QVBoxLayout(translateWindowDestGroupBox);
                translateWindowDestTextEdit = new QTextEdit();

                // About window
                aboutWindow = new QWidget();
                aboutWindowLayout = new QVBoxLayout(aboutWindow);
                aboutWindowInfoLabel1 = new QLabel(aboutWindow);
                aboutWindowInfoLabel2 = new QLabel(aboutWindow);
                aboutWindowInfoLabel3 = new QLabel(aboutWindow);
                aboutWindowOkButton = new QPushButton(aboutWindow);

                // Central widget
                // this->setCentralWidget(new QWidget(this));
                // centralWidgetLayout = new QStackedLayout(this->centralWidget());

                // Main panel
                mainPanel = new QWidget();
                mainPanelLayout = new QGridLayout();
                articleTypePanelButton = new QPushButton(mainPanel);
                typingPanelButton = new QPushButton(mainPanel);
                testingPanelButton = new QPushButton(mainPanel);
                translatePanelButton = new QPushButton(mainPanel);

                // Article type panel
                articleTypePanel = new QWidget();
                articleTypePanelLayout = new QGridLayout(articleTypePanel);
                worldSubTypePanelButton = new QPushButton(articleTypePanel);
                businessArticlePanelButton = new QPushButton(articleTypePanel);

                // World sub type Panel
                worldSubTypePanel = new QWidget();
                worldSubTypePanelLayout = new QGridLayout(worldSubTypePanel);
                africaArticleTitlePanelButton = new QPushButton(worldSubTypePanel);

                // Article title panel
                articleTitlePanel = new QWidget();
                articleTitlePanelLayout = new QVBoxLayout(articleTitlePanel);

                // Article panel
                articlePanel = new QWidget();
                articlePanelLayout = new QGridLayout(articlePanel);
                articlePanelLeftPanel = new QWidget(articlePanel);
                articlePanelLeftPanelLayout = new QGridLayout(articlePanelLeftPanel);
                articlePanelTextBrowser = new QTextBrowser(articlePanelLeftPanel);
                articlePanelTranslateTextBrowser = new QTextBrowser(articlePanelLeftPanel);
                articlePanelRightPanel = new QWidget(articlePanel);
                articlePanelRightPanelLayout = new QGridLayout(articlePanelRightPanel);
                articlePanelStatisticsTextBrowser = new QTextBrowser(articlePanelRightPanel);

                // Typing panel
                typingPanel = new QScrollArea();
                typingInnerPanel = new QWidget();
                typingInnerPanelLayout = new QVBoxLayout();

                // Testing panel
                testingPanel = new QScrollArea();
                testingInnerPanel = new QWidget();
                testingInnerPanelLayout = new QVBoxLayout();
                testingInnerPanelSubmitButton = new QPushButton();

                // Testing result panel
                testingResultPanel = new QScrollArea();
                testingResultInnerPanel = new QWidget();
                testingResultInnerPanelLayout = new QVBoxLayout();
                testingResultScoreTitleLabel = new QLabel();
                testingResultReviewLabel = new QLabel();
                testingResultScoreLabel = new QLabel();
                testingResultOkButton = new QPushButton();

                // Translate panel
                translatePanel = new QWidget();
                translatePanelLayout = new QGridLayout(translatePanel);
                translatePanelSrcGroupBox = new QGroupBox();
                translatePanelSrcGroupBoxLayout = new QVBoxLayout(translatePanelSrcGroupBox);
                translatePanelSrcTextEdit = new QTextEdit();
                translatePanelMidWidget = new QWidget();
                translatePanelMidWidgetLayout = new QVBoxLayout(translatePanelMidWidget);
                translatePanelToDestButton = new QPushButton(">>");
                translatePanelToSrcButton = new QPushButton("<<");
                translatePanelDestGroupBox = new QGroupBox();
                translatePanelDestGroupBoxLayout = new QVBoxLayout(translatePanelDestGroupBox);
                translatePanelDestTextEdit = new QTextEdit();

                /******************************************************************************************
                * Set member information
                ******************************************************************************************/
                // Translate
                this->retranslate();

                // Setup language
                // translator->load(LanguageTypes::zh_TW);
                this->setLanguage(config::readLanguageType());

                // Set central widget
                this->setCentralWidget(mainPanel);

                // Setup icon
                this->setWindowIcon(QIcon(QPixmap(xpm::APP_ICON)));

                // Setup global style sheet
                this->setStyleSheet(R"(
                    QPushButton
                    {
                        font: bold 30px;
                    }
                    QTextEdit
                    {
                        font: 15px;
                    }
                )");

                // Setup menu
                mainMenuBar->addAction(previousPanelAction);
                previousPanelAction->setEnabled(false);
                mainMenuBar->addMenu(settingMenu);
                settingMenu->addMenu(languageMenu);
                languageMenu->addAction(enUsAction);
                languageMenu->addAction(zhCnAction);
                languageMenu->addAction(zhTwAction);
                mainMenuBar->addMenu(panelMenu);
                panelMenu->addAction(translateWindowAction);
                panelMenu->addMenu(switchToMenu);
                switchToMenu->addAction(mainPanelAction);
                switchToMenu->addAction(articleTypePanelAction);
                switchToMenu->addAction(typingPanelAction);
                switchToMenu->addAction(translatePanelAction);
                mainMenuBar->addMenu(helpMenu);
                helpMenu->addAction(aboutAction);

                // Setup translate window
                translateWindow->setStyleSheet(R"(
                    QPushButton
                    {
                        font: 15px;
                    }
                )");
                translateWindow->setWindowIcon(this->windowIcon());
                translateWindow->resize(800, 600);
                translateWindowLayout->addWidget(translateWindowSrcGroupBox, 0, 0);
                translateWindowSrcGroupBoxLayout->addWidget(translateWindowSrcTextEdit);
                translateWindowLayout->addWidget(translateWindowMidWidget, 0, 1);
                translateWindowMidWidgetLayout->addWidget(translateWindowToDestButton);
                translateWindowMidWidgetLayout->addWidget(translateWindowToSrcButton);
                translateWindowLayout->addWidget(translateWindowDestGroupBox, 0, 2);
                translateWindowDestGroupBoxLayout->addWidget(translateWindowDestTextEdit);

                // Setup about window
                aboutWindow->setWindowIcon(this->windowIcon());
                aboutWindow->resize(300, 150);
                aboutWindow->setLayout(aboutWindowLayout);
                aboutWindowLayout->addWidget(aboutWindowInfoLabel1);
                aboutWindowLayout->addWidget(aboutWindowInfoLabel2);
                aboutWindowLayout->addWidget(aboutWindowInfoLabel3);
                aboutWindowLayout->addWidget(aboutWindowOkButton);

                // Setup main panel
                mainPanel->setLayout(mainPanelLayout);
                mainPanelLayout->addWidget(articleTypePanelButton, 0, 0);
                articleTypePanelButton->setMaximumWidth(300);
                articleTypePanelButton->setMinimumHeight(200);
                mainPanelLayout->addWidget(typingPanelButton, 0, 1);
                typingPanelButton->setMaximumWidth(300);
                typingPanelButton->setMinimumHeight(200);
                mainPanelLayout->addWidget(testingPanelButton, 1, 0);
                testingPanelButton->setMaximumWidth(300);
                testingPanelButton->setMinimumHeight(200);
                mainPanelLayout->addWidget(translatePanelButton, 1, 1);
                translatePanelButton->setMaximumWidth(300);
                translatePanelButton->setMinimumHeight(200);

                // Setup article type panel
                articleTypePanel->setLayout(articleTypePanelLayout);
                articleTypePanelLayout->addWidget(worldSubTypePanelButton, 0, 0);
                worldSubTypePanelButton->setMaximumWidth(300);
                worldSubTypePanelButton->setMinimumHeight(200);
                articleTypePanelLayout->addWidget(businessArticlePanelButton, 0, 1);
                businessArticlePanelButton->setMaximumWidth(300);
                businessArticlePanelButton->setMinimumHeight(200);

                // Setup world sub type panel
                worldSubTypePanel->setLayout(worldSubTypePanelLayout);
                worldSubTypePanelLayout->addWidget(africaArticleTitlePanelButton);
                africaArticleTitlePanelButton->setMaximumWidth(300);
                africaArticleTitlePanelButton->setMinimumHeight(200);

                // Setup africa article panel
                articleTitlePanel->setLayout(articleTitlePanelLayout);

                // Setup article panel
                articlePanel->setLayout(articlePanelLayout);
                articlePanelLayout->setColumnStretch(0, 1);
                articlePanelLayout->addWidget(articlePanelLeftPanel, 0, 0);
                articlePanelLayout->addWidget(articlePanelRightPanel, 0, 1);
                articlePanelLeftPanel->setLayout(articlePanelLeftPanelLayout);
                articlePanelLeftPanelLayout->setRowStretch(0, 1);
                articlePanelLeftPanelLayout->addWidget(articlePanelTextBrowser, 0, 0);
                articlePanelLeftPanelLayout->addWidget(articlePanelTranslateTextBrowser, 1, 0);
                articlePanelRightPanel->setLayout(articlePanelRightPanelLayout);
                articlePanelRightPanelLayout->addWidget(articlePanelStatisticsTextBrowser);

                // Setup testing panel
                testingPanel->setStyleSheet(R"(
                    QPushButton
                    {
                        font: 12px;
                    }
                )");
                testingPanel->setWidget(testingInnerPanel);
                testingPanel->setWidgetResizable(true);
                testingInnerPanel->setLayout(testingInnerPanelLayout);
                testingInnerPanelLayout->setAlignment(Qt::AlignTop);

                // addQuestionGroupBox(Question("Time _____ like an arrow; fruit flies like a banana", {"fly", "flies", "flied"}, {1}));
                // addQuestionGroupBox(Question("Time flies _____ an arrow; fruit flies like a banana", {"like", "likes"}, {0}));
                // addQuestionGroupBox(Question("Time flies like _____ arrow; fruit flies like a banana", {"a", "an"}, {1}));
                // addQuestionGroupBox(Question("Time flies like an arrow; fruit _____ like a banana", {"fly", "flies"}, {1}));
                // addQuestionGroupBox(Question("Time flies like an arrow; fruit flies _____ a banana", {"like", "likes"}, {0}));
                // addQuestionGroupBox(Question("Time flies like an arrow; fruit flies like _____ banana", {"a", "an", "am"}, {0}));
                // addQuestionGroupBox(Question("Time flies like an arrow; fruit flies like _____ banana", {"a", "an", "am"}, {0}));
                // addQuestionGroupBox(Question("Time flies like an arrow; fruit flies like a _____", {"banana", "orange", "stone", "apple"}, {0, 1, 3}));
                testingInnerPanelLayout->addWidget(testingInnerPanelSubmitButton);

                // Setup testing result panel
                testingResultPanel->setStyleSheet(R"(
                    QLabel
                    {
                        font: 20px;
                    }
                    QPushButton
                    {
                        font: 12px;
                    }
                )");
                testingResultPanel->setWidget(testingResultInnerPanel);
                testingResultPanel->setWidgetResizable(true);
                testingResultInnerPanel->setLayout(testingResultInnerPanelLayout);
                testingResultInnerPanelLayout->setAlignment(Qt::AlignTop);

                testingResultReviewLabel->setStyleSheet(R"(
                    QLabel
                    {
                        margin-top: 30px;
                    }
                )");
                testingResultInnerPanelLayout->addWidget(testingResultScoreTitleLabel);
                testingResultInnerPanelLayout->addWidget(testingResultScoreLabel);
                testingResultInnerPanelLayout->addWidget(testingResultReviewLabel);

                // Setup typing
                typingPanel->setStyleSheet(R"(
                    QLabel
                    {
                        font: 20px;
                    }
                    QLineEdit
                    {
                        font: 20px;
                    }
                )");
                typingPanel->setWidget(typingInnerPanel);
                typingPanel->setWidgetResizable(true);
                typingInnerPanel->setLayout(typingInnerPanelLayout);
                typingInnerPanelLayout->setAlignment(Qt::AlignTop);

                // Setup translate panel
                translatePanel->setStyleSheet(R"(
                    QPushButton
                    {
                        font: 15px;
                    }
                )");
                translatePanelLayout->addWidget(translatePanelSrcGroupBox, 0, 0);
                translatePanelSrcGroupBoxLayout->addWidget(translatePanelSrcTextEdit);
                translatePanelLayout->addWidget(translatePanelMidWidget, 0, 1);
                translatePanelMidWidgetLayout->addWidget(translatePanelToDestButton);
                translatePanelMidWidgetLayout->addWidget(translatePanelToSrcButton);
                translatePanelLayout->addWidget(translatePanelDestGroupBox, 0, 2);
                translatePanelDestGroupBoxLayout->addWidget(translatePanelDestTextEdit);

                // Menu
                QObject::connect(previousPanelAction, &QAction::triggered, [this]{this->switchToPreviousPanel();});
                QObject::connect(enUsAction, &QAction::triggered, [this]{this->setLanguage(lang::EN_US);});
                QObject::connect(zhCnAction, &QAction::triggered, [this]{this->setLanguage(lang::ZH_CN);});
                QObject::connect(zhTwAction, &QAction::triggered, [this]{this->setLanguage(lang::ZH_TW);});
                QObject::connect(mainPanelAction, &QAction::triggered, [this]{switchToPanel(mainPanel);});
                QObject::connect(translateWindowAction, &QAction::triggered, [this]{translateWindow->show();});
                QObject::connect(articleTypePanelAction, &QAction::triggered, [this]{switchToPanel(articleTypePanel);});
                QObject::connect(typingPanelAction, &QAction::triggered, [this]{switchToPanel(typingPanel);});
                QObject::connect(translatePanelAction, &QAction::triggered, [this]{switchToPanel(translatePanel);});
                QObject::connect(aboutAction, &QAction::triggered, [this]{this->popUpAboutWindow();});

                // translateWindow
                QObject::connect(translateWindowToSrcButton, &QPushButton::clicked, [this]{translateWindowTranslateToSrc();});
                QObject::connect(translateWindowToDestButton, &QPushButton::clicked, [this]{translateWindowTranslateToDest();});

                // aboutWindow
                QObject::connect(aboutWindowOkButton, &QPushButton::clicked, [this]{this->aboutWindow->hide();});

                // mainWindow
                QObject::connect(articleTypePanelButton, &QPushButton::clicked, [this]{switchToPanel(articleTypePanel);});
                QObject::connect(typingPanelButton, &QPushButton::clicked, [this]{
                    switchToPanel(typingPanel);

                    // Clear panel
                    for(QWidget *widget : typingInnerPanel->findChildren<QWidget*>()) {
                    delete widget;
                    }

                    // Add labels and lineEdits
                    addRandomTypingPanelWords();

                    typingInnerPanel->findChildren<QLineEdit*>()[0]->setFocus();
                });
                QObject::connect(testingPanelButton, &QPushButton::clicked, [this, crawler]{
                    testingInnerPanelLayout->removeWidget(testingInnerPanelSubmitButton);

                    for(QGroupBox *questionGroupBox : testingInnerPanel->findChildren<QGroupBox*>()) {
                        delete questionGroupBox;
                    }

                    std::vector<question::Question> questions;
                    // questions = Questions::makeQuestions(crawler->fetchRandomArticle());
                    for(auto &question : question::makeQuestions(crawler->fetchRandomArticle())) {
                        if(question.isValid()) {
                            questions.push_back(question);
                        }
                    }

                    // questions.push_back(Question("Time _____ like an arrow; fruit flies like a banana", {"fly", "flies", "flied"}, {1}));
                    // questions.push_back(Question("Time flies _____ an arrow; fruit flies like a banana", {"like", "likes"}, {0}));
                    // questions.push_back(Question("Time flies like _____ arrow; fruit flies like a banana", {"a", "an"}, {1}));
                    // questions.push_back(Question("Time flies like an arrow; fruit _____ like a banana", {"fly", "flies"}, {1}));
                    // questions.push_back(Question("Time flies like an arrow; fruit flies _____ a banana", {"like", "likes"}, {0}));
                    // questions.push_back(Question("Time flies like an arrow; fruit flies like _____ banana", {"a", "an", "am"}, {0}));
                    // questions.push_back(Question("Time flies like an arrow; fruit flies like _____ banana", {"a", "an", "am"}, {0}));
                    // questions.push_back(Question("Time flies like an arrow; fruit flies like a _____", {"banana", "orange", "stone", "apple"}, {0, 1, 3}));

                    for(const question::Question &question : questions) {
                        addQuestionGroupBox(question);
                    }

                    testingInnerPanelLayout->addWidget(testingInnerPanelSubmitButton);

                    switchToPanel(testingPanel);
                });
                QObject::connect(translatePanelButton, &QPushButton::clicked, [this]{switchToPanel(translatePanel);});

                // articleTypeSelectPanel
                QObject::connect(worldSubTypePanelButton, &QPushButton::clicked, [this]{switchToPanel(worldSubTypePanel);});
                QObject::connect(businessArticlePanelButton, &QPushButton::clicked, [this, crawler] {
                    switchToPanel(articleTitlePanel);
                    // crawler->clear();
                    std::vector<std::string> articleTitles = crawler->fetchArticleTitles("business");
                    setArticleTitles(articleTitles);
                });

                // articlePanel
                // From: https://doc.qt.io/qt-5/qtextbrowser.html#highlighted
                connect(articlePanelTextBrowser, &QTextEdit::selectionChanged, [this]{
                    if((!articlePanelTextBrowser->textCursor().hasSelection())) {
                        return;
                    }

                    std::cout << "articlePanelTextBrowser selectionChanged\n";
                    // articlePanelTextBrowserLastSelectTime = std::chrono::steady_clock::now();

                    // Get translate after a period of time, too fast will be blacklisted by translate server
                    std::thread translateThread([=, this]{
                        // Use this id the check if the selection text is change
                        articlePanelTextBrowserSelectRequestID++;
                        int lastArticlePanelTextBrowserSelectRequestID = articlePanelTextBrowserSelectRequestID;
                        std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::seconds(1));

                        // If the selection text is changed
                        if(articlePanelTextBrowserSelectRequestID == lastArticlePanelTextBrowserSelectRequestID) {
                            std::cout << "Translate select text: " << articlePanelTextBrowser->textCursor().selection().toPlainText().toStdString();
                            const std::string &translatedString = translate::translate(articlePanelTextBrowser->textCursor().selection().toPlainText().toStdString(), this->translator->language().toStdString());

                            // From: https://stackoverflow.com/questions/63904176/qt-invokemethod-on-textedit-setpalette?rq=1
                            // From: https://doc.qt.io/qt-5/qmetaobject.html#inherits
                            QMetaObject::invokeMethod(articlePanelTranslateTextBrowser, "setText", Qt::QueuedConnection, Q_ARG(QString, QString::fromStdString(translatedString)));
                        }
                    });
                    translateThread.detach();
                });

                // worldSubTypePanel
                QObject::connect(africaArticleTitlePanelButton, &QPushButton::clicked, [this, crawler] {
                    switchToPanel(articleTitlePanel);
                    // crawler->clear();
                    std::vector<std::string> articleTitles = crawler->fetchArticleTitles("africa");
                    setArticleTitles(articleTitles);
                });

                // testingPanel
                QObject::connect(testingInnerPanelSubmitButton, &QPushButton::clicked, [this] {
                    switchToPanel(testingResultPanel);

                    double finalScore = 0;

                    double scorePerQuestion = 100.0 / testingPanel->findChildren<QGroupBox*>().size();
                    const auto groupBoxes = testingPanel->findChildren<QGroupBox*>();


                    // Init choosedAnswersIndexes, check what answer is choosed
                    choosedAnswersIndexes.clear();
                    for(int groupBoxIndex = 0; groupBoxIndex < groupBoxes.size(); ++groupBoxIndex) {
                        choosedAnswersIndexes.push_back(std::set<int>());
                        const auto groupBoxButtons = groupBoxes[groupBoxIndex]->findChildren<QAbstractButton*>();
                        // Single choice question 
                        if(testingPanelQuestions[groupBoxIndex].isSingleChoiceQuestion()) {
                        // Single choice question only have one answer
                        int questionAnswerIndex = (*testingPanelQuestions[groupBoxIndex].answerIndexes.begin());
                        if(groupBoxButtons[questionAnswerIndex]->isChecked()) {
                            // std::cout << "questionAnswerIndex: " << questionAnswerIndex << "\n"; //debug!!
                            choosedAnswersIndexes[groupBoxIndex].insert(questionAnswerIndex); // Record choosed answer, single choice question
                            finalScore += scorePerQuestion;
                        }
                        }
                        //Multiple choice question 
                        else {
                        for(auto buttonIndex = 0; buttonIndex < groupBoxButtons.size(); ++buttonIndex) {
                            // If there are nothing checked, no score
                            if(buttonIndex == 0) {
                                bool nothingChecked = true;
                                for(auto i = 0; i < groupBoxButtons.size(); ++i) {
                                    if(groupBoxButtons[i]->isChecked()) {
                                        choosedAnswersIndexes[groupBoxIndex].insert(i); // Record choosed answer, multiple choice question
                                        nothingChecked = false;
                                    }
                                }
                                if(nothingChecked) {
                                    break;
                                }
                            }

                            double scorePerAnswer = scorePerQuestion / groupBoxButtons.size();
                            if(testingPanelQuestions[groupBoxIndex].answerIndexes.contains(buttonIndex) && groupBoxButtons[buttonIndex]->isChecked()) {
                                finalScore += scorePerAnswer;
                            }
                            else if(!testingPanelQuestions[groupBoxIndex].answerIndexes.contains(buttonIndex) && !groupBoxButtons[buttonIndex]->isChecked()) {
                                finalScore += scorePerAnswer;
                            }
                            }
                        }
                    }

                    // Clear testing result panel
                    testingResultInnerPanelLayout->removeWidget(testingResultOkButton);
                    for(QGroupBox *questionGroupBox : testingResultInnerPanel->findChildren<QGroupBox*>()) {
                        delete questionGroupBox;
                    }
                    // QPushButton* okButton = testingResultInnerPanel->findChildren<QPushButton*>();

                    // Add questions to testing result panel
                    for(std::size_t i = 0; i < testingPanelQuestions.size(); ++i) {
                        bool currentQuestionAllCorrect = true; // Record if the question is all correct, only wrong question need to be appeared in testingResultPanel
                        if(testingPanelQuestions[i].answerIndexes.size() != choosedAnswersIndexes[i].size()) {
                            // std::cout << "Size not the same\n"; //debug!!
                            currentQuestionAllCorrect = false;
                        }
                        for(int choosedAnswerIndex : choosedAnswersIndexes[i]) {
                            if(!testingPanelQuestions[i].answerIndexes.contains(choosedAnswerIndex)) {
                                // std::cout << "Answer not correct in question " << i << ": " << choosedAnswerIndex << "\n"; //debug!!
                                currentQuestionAllCorrect = false;
                                break;
                            }
                        }

                        // If the current question not all correct, it should be list in the testing result panel
                        if(!currentQuestionAllCorrect) {
                            question::Question &question = testingPanelQuestions[i];
                            QGroupBox *questionGroupBox = new QGroupBox();
                            QVBoxLayout *questionGroupBoxLayout = new QVBoxLayout(questionGroupBox);
                            if(question.isSingleChoiceQuestion()) {
                                // Add question
                                questionGroupBox->setTitle(QString::fromStdString(question.question));

                                // Add candidate answer
                                for(std::size_t candidateAnswerIndex = 0; candidateAnswerIndex < question.candidateAnswers.size(); ++candidateAnswerIndex) {
                                    QRadioButton *button = new QRadioButton(questionGroupBox);
                                    button->setText(QString::fromStdString(question.candidateAnswers[candidateAnswerIndex]));
                                    questionGroupBoxLayout->addWidget(button);

                                    if(question.answerIndexes.contains(candidateAnswerIndex)) {
                                        // button->setCheckState(Qt::Checked);
                                        button->setChecked(true);
                                    }
                                    // button->setCheckable(false);
                                    button->setEnabled(false);
                                }
                            }
                            else if(question.isMultipleChoiceQuestion()) {
                                // Add question
                                questionGroupBox->setTitle(QString::fromStdString(question.question));

                                // Add candidate answer
                                for(std::size_t candidateAnswerIndex = 0; candidateAnswerIndex < question.candidateAnswers.size(); ++candidateAnswerIndex) {
                                    QCheckBox *button = new QCheckBox(questionGroupBox);
                                    button->setText(QString::fromStdString(question.candidateAnswers[candidateAnswerIndex]));
                                    questionGroupBoxLayout->addWidget(button);

                                    if(question.answerIndexes.contains(candidateAnswerIndex)) {
                                        button->setChecked(true);
                                        // button->setCheckState(Qt::Checked);
                                    }
                                    // button->setCheckable(false);
                                    button->setEnabled(false);
                                }
                            }

                            // //HERE
                            // std::string choosedAnswersString("Your Answer: ");
                            //
                            // if(choosedAnswersIndexes[i].size() == 0)
                            // {
                            //   // choosedAnswersString += "None";
                            // }
                            // else
                            // {
                            //   for(auto choosedAnswerIndex : choosedAnswersIndexes[i])
                            //   {
                            //     choosedAnswersString += testingPanelQuestions[i].candidateAnswers[choosedAnswerIndex];
                            //   }
                            // }
                            //
                            // QLabel *choosedAnswersLabel = new QLabel(QString::fromStdString(choosedAnswersString));
                            // choosedAnswersLabel->setStyleSheet(R"(
                            //   QLabel
                            //   {
                            //     font: 12px;
                            //   }
                            // )");
                            // questionGroupBoxLayout->addWidget(choosedAnswersLabel);

                            testingResultInnerPanelLayout->addWidget(questionGroupBox);
                        }
                    }
                    // Add back the ok button in the end
                    testingResultInnerPanelLayout->addWidget(testingResultOkButton);

                    std::cout << "finalScore: " << finalScore << "\n";
                    // testingResultScoreLabel->setText(QString::fromStdString(std::to_string(finalScore)));
                    testingResultScoreLabel->setText(QString::number(finalScore));

                    // scroll to top left
                    testingResultPanel->verticalScrollBar()->setValue(0);
                    testingResultPanel->horizontalScrollBar()->setValue(0);
                });

                // testingResultPanel
                QObject::connect(testingResultOkButton, &QPushButton::clicked, [this]{
                    // Clear questions
                    testingPanelQuestions.clear();
                    // Switch to main panel
                    this->switchToPanel(mainPanel);
                    // Scroll to top left
                    testingResultPanel->verticalScrollBar()->setValue(0);
                    testingResultPanel->horizontalScrollBar()->setValue(0);
                });

                // translatePanel
                QObject::connect(translatePanelToDestButton, &QPushButton::clicked, [this]{this->translatePanelTranslateToDest();});
                QObject::connect(translatePanelToSrcButton, &QPushButton::clicked, [this]{this->translatePanelTranslateToSrc();});
            }

            void MainWindow::keyPressEvent(QKeyEvent *event) {
                if(event->text() == "T") {
                    translateWindow->show();
                }
            }

            void MainWindow::retranslate() {
                // Main window
                this->setWindowTitle(QMainWindow::tr("English Assistant"));

                // Menu
                previousPanelAction->setText(QAction::tr("<-"));
                settingMenu->setTitle(QMenu::tr("Setting"));
                languageMenu->setTitle(QMenu::tr("Language"));
                enUsAction->setText(QAction::tr("English(US)"));
                zhCnAction->setText(QAction::tr("Chinese(China)"));
                zhTwAction->setText(QAction::tr("Chinese(Taiwan)"));
                panelMenu->setTitle(QMenu::tr("Panel"));
                translateWindowAction->setText(QAction::tr("Translate window"));
                switchToMenu->setTitle(QMenu::tr("Switch To"));
                mainPanelAction->setText(QAction::tr("Main Panel"));
                articleTypePanelAction->setText(QAction::tr("Article Type Select Panel"));
                typingPanelAction->setText(QAction::tr("Typing Panel"));
                translatePanelAction->setText(QAction::tr("Translate Panel"));
                helpMenu->setTitle(QMenu::tr("Help"));
                aboutAction->setText(QMenu::tr("About"));

                // Translate window
                translateWindowSrcGroupBox->setTitle(QTextEdit::tr("Source language"));
                translateWindowDestGroupBox->setTitle(QTextEdit::tr("Dest language"));

                // About window
                aboutWindow->setWindowTitle(QDialog::tr("English Assistant"));
                aboutWindowInfoLabel1->setText(QDialog::tr("English Assistant") + " " + QString::fromStdString(info::VERSION));
                aboutWindowInfoLabel2->setText(QDialog::tr("English translate & learning program"));
                aboutWindowInfoLabel3->setText(QDialog::tr("Published under GPLv3"));
                aboutWindowOkButton->setText(QPushButton::tr("OK"));

                // Main panel
                articleTypePanelButton->setText(QPushButton::tr("Article"));
                typingPanelButton->setText(QPushButton::tr("Typing"));
                testingPanelButton->setText(QPushButton::tr("Testing"));
                translatePanelButton->setText(QPushButton::tr("Translate"));

                // Article type panel
                worldSubTypePanelButton->setText(QPushButton::tr("World"));
                businessArticlePanelButton->setText(QPushButton::tr("Business"));

                // World sub type panel
                africaArticleTitlePanelButton->setText(QPushButton::tr("Africa"));

                // Testing panel
                testingInnerPanelSubmitButton->setText(QPushButton::tr("Submit"));

                // Testing result panel
                testingResultScoreTitleLabel->setText(QLabel::tr("Score: "));
                testingResultReviewLabel->setText(QLabel::tr("Error review: "));
                testingResultOkButton->setText(QLabel::tr("OK"));

                // Translate panel
                translatePanelSrcGroupBox->setTitle(QTextEdit::tr("Source language"));
                translatePanelDestGroupBox->setTitle(QTextEdit::tr("Dest language"));
            }

            void MainWindow::setLanguage(const std::string &languageType) {
                // Check if it is different with current language
                if(translator->language().toStdString() == languageType) {
                    std::cout << languageType << " is the current language, nothing changed\n";
                    return;
                }

                std::cout << "MainWindow::setLanguage(\"" << languageType << "\")\n";
                std::string languageFilePath = std::string("assets/lang/") + languageType;
                if(!translator->load(QString::fromStdString(languageFilePath))) {
                    std::cerr << "Failed to load MainWindow::translatior" << std::endl;
                    return;
                }
                std::cout << "The language after change is: " << translator->language().toStdString() << "\n"; //debug
                config::writeLanguageType(languageType);

                this->retranslate();
            }

            void MainWindow::setArticleTitles(const std::vector<std::string> &articleTitles) {
                // Delete previous buttons
                for(const auto button : articleTitlePanel->findChildren<QPushButton*>()) {
                    delete button;
                }

                // Add article title buttons
                for(std::string articleTitle : articleTitles) {
                    QPushButton *button = new QPushButton(articleTitlePanel);
                    button->setText(QString::fromStdString(articleTitle));
                    QObject::connect(button, &QPushButton::clicked, [=, this]{
                        std::string article = crawler->fetchArticle(button->text().toStdString());
                        std::cout << "Article title: " << button->text().toStdString() << "\n";
                        this->setArticle(article);
                        switchToPanel(articlePanel);
                    });
                    articleTitlePanelLayout->addWidget(button);
                }
            }

            void MainWindow::setArticle(const std::string &article) {
                std::cout << "void MainWindow::setArticle(const std::string &article)\n";
                articlePanelTextBrowser->setText(QString::fromStdString(article));
                articlePanelTranslateTextBrowser->setText("");

                std::string wordFrequencyString;
                auto bannedWords = config::readBannedWords();
                for(const auto &wordFrequency : util::wordFrequency(article, bannedWords))
                {
                    wordFrequencyString += wordFrequency.first + ": " + std::to_string(wordFrequency.second) + "\n";
                }
                articlePanelStatisticsTextBrowser->setText(QString::fromStdString(wordFrequencyString));
            }

            void MainWindow::translateWindowTranslateToDest() {
                std::cout << "MainWindow::translateWindowTranslateToDest()\n";
                const std::string &input = translateWindowSrcTextEdit->toPlainText().toStdString();
                const std::string &destLanguageType = translator->language().toStdString();
                const std::string &srcLanguageType = lang::EN_US;
                const std::string &reply = translate::translate(input, destLanguageType, srcLanguageType);
                translateWindowDestTextEdit->setText(QString::fromStdString(reply));
            }

            void MainWindow::translateWindowTranslateToSrc() {
                std::cout << "MainWindow::translateWindowTranslateToSrc()\n";
                const std::string &input = translateWindowDestTextEdit->toPlainText().toStdString();
                const std::string &srcLanguageType = translator->language().toStdString();
                const std::string &destLanguageType = lang::EN_US;
                const std::string &reply = translate::translate(input, destLanguageType, srcLanguageType);
                translateWindowSrcTextEdit->setText(QString::fromStdString(reply));
            }

            void MainWindow::translatePanelTranslateToDest() {
                std::cout << "MainWindow::translatePanelTranslateToDest()\n";
                const std::string &input = translatePanelSrcTextEdit->toPlainText().toStdString();
                const std::string &destLanguageType = translator->language().toStdString();
                const std::string &srcLanguageType = lang::EN_US;
                const std::string &reply = translate::translate(input, destLanguageType, srcLanguageType);
                translatePanelDestTextEdit->setText(QString::fromStdString(reply));
            }

            void MainWindow::translatePanelTranslateToSrc() {
                std::cout << "MainWindow::translatePanelTranslateToSrc()\n";
                const std::string &input = translatePanelDestTextEdit->toPlainText().toStdString();
                const std::string &srcLanguageType = translator->language().toStdString();
                const std::string &destLanguageType = lang::EN_US;
                const std::string &reply = translate::translate(input, destLanguageType, srcLanguageType);
                translatePanelSrcTextEdit->setText(QString::fromStdString(reply));
            }

            void MainWindow::popUpAboutWindow() {
                std::cout << "MainWindow::popUpAboutWindow()\n";
                aboutWindow->show();
            }

            void MainWindow::switchToPanel(QWidget *panel) {
                std::cout << "MainWindow::switchToPanel()\n";
                panelHistory.push(this->centralWidget());

                this->centralWidget()->setParent(nullptr);
                this->setCentralWidget(panel);

                previousPanelAction->setEnabled(true);
            }

            void MainWindow::switchToPreviousPanel() {
                std::cout << "MainWindow::switchToPreviousPanel()\n";
                if(panelHistory.size() <= 0)
                {
                    std::cout << "Error: There are no previous panel\n";
                    return;
                }

                this->centralWidget()->setParent(nullptr);

                this->setCentralWidget(panelHistory.top());
                panelHistory.pop();

                if(panelHistory.size() <= 0)
                {
                    std::cout << "Disable previousPanelAction\n";
                    previousPanelAction->setEnabled(false);
                }
            }

            void MainWindow::addRandomTypingPanelWords() {
                const std::string &article = crawler->fetchRandomArticle();
                const std::vector<std::string> &bannedWords = config::readBannedWords();
                std::vector<std::string> typingPanelWords;
                for(const auto &wordFrequency : util::wordFrequency(article, bannedWords))
                {
                    typingPanelWords.push_back(wordFrequency.first);
                }
                addTypingPanelWords(typingPanelWords);
            }

            void MainWindow::addTypingPanelWords(const std::vector<std::string> &words) {
                for(const std::string &word : words) {
                    QLabel *label = new QLabel(QString::fromStdString(word));
                    QLineEdit *lineEdit = new QLineEdit();

                    typingInnerPanelLayout->addWidget(label);
                    typingInnerPanelLayout->addWidget(lineEdit);

                    QObject::connect(lineEdit, &QLineEdit::returnPressed, [=, this]{
                        auto labels = typingInnerPanel->findChildren<QLabel*>();
                        auto lineEdits = typingInnerPanel->findChildren<QLineEdit*>();
                        int lineEditIndex = lineEdits.indexOf(lineEdit);
                        if(labels[lineEditIndex]->text() == lineEdits[lineEditIndex]->text()) {
                            if(lineEdits.size() > lineEdits.indexOf(lineEdit)+1) {
                                // Enter correct word, change to next line
                                // const QPoint point = lineEdits[lineEditIndex+1]->mapTo(testingInnerPanel, QPoint(0,0));
                                // std::cout << point.x() << ", " << point.y() << "\n";
                                // testingPanel->ensureWidgetVisible(lineEdits[lineEditIndex+1]);

                                // Ensure widget visible
                                // From: https://stackoverflow.com/questions/52450219/qscrollarea-ensurewidgetvisible-method-does-not-show-target-widget
                                // testingPanel->ensureWidgetVisible(lineEdits[lineEditIndex+1]);

                                lineEdits[lineEditIndex+1]->setFocus();
                            }
                            else {
                                switchToPanel(mainPanel);
                            }
                        }
                    });
                }
            }

            bool MainWindow::addQuestionGroupBox(const question::Question &question) {
                if(!question.isValid()) {
                    std::cerr << "Error on MainWindow::addQuestionGroupBox(const Question &question), not a valid question.";
                    return false;
                }

                testingPanelQuestions.push_back(question);

                QGroupBox *questionGroupBox = new QGroupBox();
                QVBoxLayout *questionGroupBoxLayout = new QVBoxLayout(questionGroupBox);
                if(question.isSingleChoiceQuestion()) {
                    // Add question
                    questionGroupBox->setTitle(QString::fromStdString(question.question));

                    // Add candidate answer
                    for(auto &candidateAnswer : question.candidateAnswers) {
                        QRadioButton *button = new QRadioButton(questionGroupBox);
                        button->setText(QString::fromStdString(candidateAnswer));
                        questionGroupBoxLayout->addWidget(button);
                    }
                }
                else if(question.isMultipleChoiceQuestion()) {
                    // Add question
                    questionGroupBox->setTitle(QString::fromStdString(question.question));

                    // Add candidate answer
                    for(auto &candidateAnswer : question.candidateAnswers) {
                        QCheckBox *button = new QCheckBox(questionGroupBox);
                        button->setText(QString::fromStdString(candidateAnswer));
                        questionGroupBoxLayout->addWidget(button);
                    }
                }

                testingInnerPanelLayout->addWidget(questionGroupBox);
                return true;
            }

            // bool MainWindow::addTestingResultGroupBox(const TestingResult &testingResult)
            // {
            //   if(!question.isValid())
            //   {
            //     std::cerr << "Error on MainWindow::addTestingResultGroupBox(const TestingResult &testingResult), not a valid testingResult.";
            //     return false;
            //   }
            //
            //   testingPanelQuestions.push_back(question);
            //
            //   QGroupBox *questionGroupBox = new QGroupBox();
            //   QVBoxLayout *questionGroupBoxLayout = new QVBoxLayout(questionGroupBox);
            //   if(question.isSingleChoiceQuestion())
            //   {
            //       // Add question
            //       questionGroupBox->setTitle(QString::fromStdString(question.question));
            //
            //       // Add candidate answer
            //       for(auto &candidateAnswer : question.candidateAnswers)
            //       {
            //         QRadioButton *button = new QRadioButton(questionGroupBox);
            //         button->setText(QString::fromStdString(candidateAnswer));
            //         questionGroupBoxLayout->addWidget(button);
            //       }
            //   }
            //   else if(question.isMultipleChoiceQuestion())
            //   {
            //       // Add question
            //       questionGroupBox->setTitle(QString::fromStdString(question.question));
            //
            //       // Add candidate answer
            //       for(auto &candidateAnswer : question.candidateAnswers)
            //       {
            //         QCheckBox *button = new QCheckBox(questionGroupBox);
            //         button->setText(QString::fromStdString(candidateAnswer));
            //         questionGroupBoxLayout->addWidget(button);
            //       }
            //   }
            //
            //   testingInnerPanelLayout->addWidget(questionGroupBox);
            //   return true;
            // }

            // QGroupBox* MainWindow::createSingleChoiceQuestion(const std::string &question, const std::vector<std::string> &candidateAnswers)
            // {
            //   QGroupBox *questionGroupBox = new QGroupBox();
            //   QVBoxLayout *questionGroupBoxLayout = new QVBoxLayout(questionGroupBox);
            //
            //   // Add question
            //   questionGroupBox->setTitle(QString::fromStdString(question));
            //
            //   // Add candidate answer
            //   for(auto candidateAnswer : candidateAnswers)
            //   {
            //     QRadioButton *button = new QRadioButton(questionGroupBox);
            //     button->setText(QString::fromStdString(candidateAnswer));
            //     questionGroupBoxLayout->addWidget(button);
            //   }
            //
            //   return questionGroupBox;
            // }
            //
            // QGroupBox* MainWindow::createMultipleChoiceQuestion(const std::string &question, const std::vector<std::string> &candidateAnswers)
            // {
            //   QGroupBox *questionGroupBox = new QGroupBox();
            //   QVBoxLayout *questionGroupBoxLayout = new QVBoxLayout(questionGroupBox);
            //
            //   // Add question
            //   questionGroupBox->setTitle(QString::fromStdString(question));
            //
            //   // Add candidate answer
            //   for(auto candidateAnswer : candidateAnswers)
            //   {
            //     QCheckBox *button = new QCheckBox(questionGroupBox);
            //     button->setText(QString::fromStdString(candidateAnswer));
            //     questionGroupBoxLayout->addWidget(button);
            //   }
            //
            //   return questionGroupBox;
            // }
        }
    }
}