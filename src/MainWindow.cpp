
#include "MainWindow.h"
#include "OnlineTranslator.h"
#include "LanguageTypes.h"
#include "ProjectInfo.h"
#include "Solution.h"
#include <iostream> //debug
#include <thread>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QTranslator>
#include <QRadioButton>
#include <QCheckBox>
#include <QTextDocumentFragment>

MainWindow::MainWindow(QTranslator *translator, Crawler *crawler)
  :translator(translator)
  ,crawler(crawler)
{
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
  switchToMenu = new QMenu(mainMenuBar);
  mainPanelAction = new QAction(switchToMenu);
  articleTypePanelAction = new QAction(switchToMenu);
  typingPanelAction = new QAction(switchToMenu);
  translatePanelAction = new QAction(switchToMenu);
  helpMenu = new QMenu(mainMenuBar);
  aboutAction = new QAction(helpMenu);

  // About dialog
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
  testingResultTitleLabel = new QLabel();

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
  this->setLanguage(LanguageTypes::zh_TW);

  // Set central widget
  this->setCentralWidget(mainPanel);

  // Setup icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

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
  mainMenuBar->addMenu(switchToMenu);
  switchToMenu->addAction(mainPanelAction);
  switchToMenu->addAction(articleTypePanelAction);
  switchToMenu->addAction(typingPanelAction);
  switchToMenu->addAction(translatePanelAction);
  mainMenuBar->addMenu(helpMenu);
  helpMenu->addAction(aboutAction);

  // Setup about dialogl
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

  addQuestionGroupBox(Question("Time _____ like an arrow; fruit flies like a banana", {"fly", "flies", "flied"}, {1}));
  addQuestionGroupBox(Question("Time flies _____ an arrow; fruit flies like a banana", {"like", "likes"}, {0}));
  addQuestionGroupBox(Question("Time flies like _____ arrow; fruit flies like a banana", {"a", "an"}, {1}));
  addQuestionGroupBox(Question("Time flies like an arrow; fruit _____ like a banana", {"fly", "flies"}, {1}));
  addQuestionGroupBox(Question("Time flies like an arrow; fruit flies _____ a banana", {"like", "likes"}, {0}));
  addQuestionGroupBox(Question("Time flies like an arrow; fruit flies like _____ banana", {"a", "an", "am"}, {0}));
  addQuestionGroupBox(Question("Time flies like an arrow; fruit flies like _____ banana", {"a", "an", "am"}, {0}));
  addQuestionGroupBox(Question("Time flies like an arrow; fruit flies like a _____", {"banana", "orange", "stone", "apple"}, {0, 1, 3}));
  testingInnerPanelLayout->addWidget(testingInnerPanelSubmitButton);

  // Setup testing result panel
  testingResultPanel->setStyleSheet(R"(
    QLabel
    {
      font: 12px;
    }
  )");
  testingResultPanel->setWidget(testingResultInnerPanel);
  testingPanel->setWidgetResizable(true);
  testingResultInnerPanel->setLayout(testingResultInnerPanelLayout);
  testingInnerPanelLayout->setAlignment(Qt::AlignTop);

  testingResultInnerPanelLayout->addWidget(testingResultTitleLabel);
  testingResultInnerPanelLayout->addWidget(new QPushButton());
  testingResultInnerPanelLayout->addWidget(new QTextBrowser());

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
  QObject::connect(enUsAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::en_US);});
  QObject::connect(zhCnAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_CN);});
  QObject::connect(zhTwAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_TW);});
  QObject::connect(mainPanelAction, &QAction::triggered, [this]{switchToPanel(mainPanel);});
  QObject::connect(articleTypePanelAction, &QAction::triggered, [this]{switchToPanel(articleTypePanel);});
  QObject::connect(typingPanelAction, &QAction::triggered, [this]{switchToPanel(typingPanel);});
  QObject::connect(translatePanelAction, &QAction::triggered, [this]{switchToPanel(translatePanel);});
  QObject::connect(aboutAction, &QAction::triggered, [this]{this->popUpAboutWindow();});

  // aboutWindow
  QObject::connect(aboutWindowOkButton, &QPushButton::clicked, [this]{this->aboutWindow->hide();});

  // mainWindow
  QObject::connect(articleTypePanelButton, &QPushButton::clicked, [this]{switchToPanel(articleTypePanel);});
  QObject::connect(typingPanelButton, &QPushButton::clicked, [this]{
    switchToPanel(typingPanel);
    for(const std::string &word : {"apple", "banana"})
    {
      QLabel *label = new QLabel(QString::fromStdString(word));
      QLineEdit *lineEdit = new QLineEdit(QString::fromStdString(word));
      typingInnerPanelLayout->addWidget(label);
      typingInnerPanelLayout->addWidget(lineEdit);
      QObject::connect(lineEdit, &QLineEdit::textChanged, [=, this]{
        auto lineEdits = typingInnerPanel->findChildren<QLineEdit*>();

        if(lineEdits.size() > lineEdits.indexOf(lineEdit))
        {
          // std::cout << lineEdits.indexOf(lineEdit) << "\n";
          QLineEdit *lineEdit = lineEdits[lineEdits.indexOf(lineEdit)];
          QLineEdit *nextLineEdit = lineEdits[lineEdits.indexOf(lineEdit)+1];

          nextLineEdit->setFocus(); //HERE
        }
        else
        {
          // Last enter
        }
      });
    }
  });
  QObject::connect(testingPanelButton, &QPushButton::clicked, [this]{switchToPanel(testingPanel);});
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
    if((!articlePanelTextBrowser->textCursor().hasSelection()))
    {
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
      if(articlePanelTextBrowserSelectRequestID == lastArticlePanelTextBrowserSelectRequestID)
      {
        std::cout << "Translate select text: " << articlePanelTextBrowser->textCursor().selection().toPlainText().toStdString();
        const std::string &translatedString = OnlineTranslator::translate(articlePanelTextBrowser->textCursor().selection().toPlainText().toStdString(), this->translator->language().toStdString());

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
  QObject::connect(testingInnerPanelSubmitButton, &QPushButton::clicked, [this]{
    switchToPanel(testingResultPanel);

    double finalScore = 0;

    double scorePerQuestion = 100.0 / testingPanel->findChildren<QGroupBox*>().size();
    const auto groupBoxes = testingPanel->findChildren<QGroupBox*>();
    for(int groupBoxIndex = 0; groupBoxIndex < groupBoxes.size(); ++groupBoxIndex)
    {
      const auto groupBoxButtons = groupBoxes[groupBoxIndex]->findChildren<QAbstractButton*>();
      if(testingPanelQuestions[groupBoxIndex].isSingleChoiceQuestion())
      {
        if(groupBoxButtons[(*testingPanelQuestions[groupBoxIndex].answerIndexes.begin())]->isChecked())
        {
          finalScore += scorePerQuestion;
        }
      }
      else
      {
        for(int buttonIndex = 0; buttonIndex < groupBoxButtons.size(); ++buttonIndex)
        {
          // If there are nothing checked, no score
          if(buttonIndex == 0)
          {
            bool nothingChecked = true;
            for(int i = 0; i < groupBoxButtons.size(); ++i)
            {
              if(groupBoxButtons[i]->isChecked())
              {
                nothingChecked = false;
              }
            }
            if(nothingChecked)
            {
              break;
            }
          }

          double scorePerAnswer = scorePerQuestion / groupBoxButtons.size();
          if(testingPanelQuestions[groupBoxIndex].answerIndexes.contains(buttonIndex) && groupBoxButtons[buttonIndex]->isChecked())
          {
            finalScore += scorePerAnswer;
          }
          else if(!testingPanelQuestions[groupBoxIndex].answerIndexes.contains(buttonIndex) && !groupBoxButtons[buttonIndex]->isChecked())
          {
            finalScore += scorePerAnswer;
          }
        }
      }
    }


    std::cout << "finalScore: " << finalScore << "\n";
  });

  // translatePanel
  QObject::connect(translatePanelToDestButton, &QPushButton::clicked, [this]{this->translatePanelTranslateToDest();});
  QObject::connect(translatePanelToSrcButton, &QPushButton::clicked, [this]{this->translatePanelTranslateToSrc();});
}

void MainWindow::retranslate()
{
  // Main window
  this->setWindowTitle(QMainWindow::tr("English Assistant"));

  // Menu
  previousPanelAction->setText(QAction::tr("<-"));
  settingMenu->setTitle(QMenu::tr("Setting"));
  languageMenu->setTitle(QMenu::tr("Language"));
  enUsAction->setText(QAction::tr("English(US)"));
  zhCnAction->setText(QAction::tr("Chinese(China)"));
  zhTwAction->setText(QAction::tr("Chinese(Taiwan)"));
  switchToMenu->setTitle(QMenu::tr("Switch To"));
  mainPanelAction->setText(QAction::tr("Main Panel"));
  articleTypePanelAction->setText(QAction::tr("Article Type Select Panel"));
  typingPanelAction->setText(QAction::tr("Typing Panel"));
  translatePanelAction->setText(QAction::tr("Translate Panel"));
  helpMenu->setTitle(QMenu::tr("Help"));
  aboutAction->setText(QMenu::tr("About"));

  // About dialog
  aboutWindow->setWindowTitle(QDialog::tr("English Assistant"));
  aboutWindowInfoLabel1->setText(QDialog::tr("English Assistant") + " " + ProjectInfo::VERSION);
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
  testingResultTitleLabel->setText(QLabel::tr("Testing Result:"));

  // Translate panel
  translatePanelSrcGroupBox->setTitle(QTextEdit::tr("Source language"));
  translatePanelDestGroupBox->setTitle(QTextEdit::tr("Dest language"));
}

void MainWindow::setLanguage(const std::string &languageType)
{
  std::cout << "Current language is: " << translator->language().toStdString() << "\n"; //debug

  // Check if it is different with current language
  if(translator->language().toStdString() == languageType)
  {
    std::cout << languageType << " is the current language, nothing changed\n";
    return;
  }

  std::cout << "MainWindow::setLanguage(\"" << languageType << "\")\n";
  std::string languageFilePath = std::string("assets/lang/") + languageType;
  translator->load(QString::fromStdString(languageFilePath));
  std::cout << "The language after change is: " << translator->language().toStdString() << "\n"; //debug

  this->retranslate();
}

void MainWindow::setArticleTitles(const std::vector<std::string> &articleTitles)
{
  // Delete previous buttons
  for(const auto button : articleTitlePanel->findChildren<QPushButton*>())
  {
    delete button;
  }

  // Add article title buttons
  for(std::string articleTitle : articleTitles)
  {
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

void MainWindow::setArticle(const std::string &article)
{
  std::cout << "void MainWindow::setArticle(const std::string &article)\n";
  articlePanelTextBrowser->setText(QString::fromStdString(article));
  articlePanelTranslateTextBrowser->setText("");

  std::string wordFrequencyString;
  auto bannedWords = Solution::splitString(Solution::readFile("./config/bannedWords.txt"), '\n');
  for(const auto &wordFrequency : Solution::wordFrequency(article, bannedWords))
  {
    wordFrequencyString += wordFrequency.first + ": " + std::to_string(wordFrequency.second) + "\n";
  }
  articlePanelStatisticsTextBrowser->setText(QString::fromStdString(wordFrequencyString));
}

void MainWindow::translatePanelTranslateToDest()
{
  std::cout << "MainWindow::translatePanelTranslateToDest()\n";
  const std::string &input = translatePanelSrcTextEdit->toPlainText().toStdString();
  const std::string &destLanguageType = translator->language().toStdString();
  const std::string &srcLanguageType = LanguageTypes::en_US;
  const std::string &reply = OnlineTranslator::translate(input, destLanguageType, srcLanguageType);
  translatePanelDestTextEdit->setText(QString::fromStdString(reply));
}

void MainWindow::translatePanelTranslateToSrc()
{
  std::cout << "MainWindow::translatePanelTranslateToSrc()\n";
  const std::string &input = translatePanelDestTextEdit->toPlainText().toStdString();
  const std::string &srcLanguageType = translator->language().toStdString();
  const std::string &destLanguageType = LanguageTypes::en_US;
  const std::string &reply = OnlineTranslator::translate(input, destLanguageType, srcLanguageType);
  translatePanelSrcTextEdit->setText(QString::fromStdString(reply));
}

void MainWindow::popUpAboutWindow()
{
  std::cout << "MainWindow::popUpAboutWindow()\n";
  aboutWindow->show();
}

void MainWindow::switchToPanel(QWidget *panel)
{
  std::cout << "MainWindow::switchToPanel()\n";
  panelHistory.push(this->centralWidget());

  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(panel);

  previousPanelAction->setEnabled(true);
}

void MainWindow::switchToPreviousPanel()
{
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

bool MainWindow::addQuestionGroupBox(const Question &question)
{
  if(!question.isValidQuestion())
  {
    std::cerr << "Error on MainWindow::addQuestionGroupBox(const Question &question), not a valid question.";
    return false;
  }

  testingPanelQuestions.push_back(question);

  QGroupBox *questionGroupBox = new QGroupBox();
  QVBoxLayout *questionGroupBoxLayout = new QVBoxLayout(questionGroupBox);
  if(question.isSingleChoiceQuestion())
  {
      // Add question
      questionGroupBox->setTitle(QString::fromStdString(question.question));

      // Add candidate answer
      for(auto &candidateAnswer : question.candidateAnswers)
      {
        QRadioButton *button = new QRadioButton(questionGroupBox);
        button->setText(QString::fromStdString(candidateAnswer));
        questionGroupBoxLayout->addWidget(button);
      }
  }
  else if(question.isMultipleChoiceQuestion())
  {
      // Add question
      questionGroupBox->setTitle(QString::fromStdString(question.question));

      // Add candidate answer
      for(auto &candidateAnswer : question.candidateAnswers)
      {
        QCheckBox *button = new QCheckBox(questionGroupBox);
        button->setText(QString::fromStdString(candidateAnswer));
        questionGroupBoxLayout->addWidget(button);
      }
  }

  testingInnerPanelLayout->addWidget(questionGroupBox);
  return true;
}

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
