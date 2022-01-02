#include "MainWindow.h"
#include "OnlineTranslator.h"
#include "LanguageTypes.h"
#include "ProjectInfo.h"
#include "Solution.h"
#include <iostream> //debug
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QTranslator>
#include <QRadioButton>
#include <QCheckBox>

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
  articlePanelTextBrowser = new QTextBrowser(articlePanel);

  // Typing panel
  typingPanel = new QWidget();
  typingPanelLayout = new QGridLayout(typingPanel);
  // typingPanelStatusWidget = new QWidget(typingPanel);
  typingPanelTypingWidget = new QWidget(typingPanel);
  typingPanelTypingWidgetLayout = new QVBoxLayout(typingPanelTypingWidget);

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

  // Setup africa article panel
  articleTitlePanel->setLayout(articleTitlePanelLayout);

  // Setup article panel
  articlePanel->setLayout(articlePanelLayout);
  // articlePanelLayout->setColumnMinimumWidth(0, 200);
  articlePanelLayout->addWidget(articlePanelTextBrowser, 1, 0);

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

  testingInnerPanelLayout->addWidget(createSingleChoiceQuestion("Time _____ like an arrow; fruit flies like a banana", {"fly", "flies", "flied"}));
  testingInnerPanelLayout->addWidget(createSingleChoiceQuestion("Time flies _____ an arrow; fruit flies like a banana", {"like", "likes"}));
  testingInnerPanelLayout->addWidget(createSingleChoiceQuestion("Time flies like _____ arrow; fruit flies like a banana", {"a", "an"}));
  testingInnerPanelLayout->addWidget(createSingleChoiceQuestion("Time flies like an arrow; fruit _____ like a banana", {"fly", "flies"}));
  testingInnerPanelLayout->addWidget(createSingleChoiceQuestion("Time flies like an arrow; fruit flies _____ a banana", {"like", "likes"}));
  testingInnerPanelLayout->addWidget(createMultipleChoiceQuestion("Time flies like an arrow; fruit flies like _____ banana", {"a", "an", "am"}));
  testingInnerPanelLayout->addWidget(testingInnerPanelSubmitButton);

  // Setup testing result panel
  testingResultPanel->setWidget(testingResultInnerPanel);
  testingPanel->setWidgetResizable(true);
  testingResultInnerPanel->setLayout(testingResultInnerPanelLayout);
  testingInnerPanelLayout->setAlignment(Qt::AlignTop);

  testingResultInnerPanelLayout->addWidget(testingResultTitleLabel);
  testingResultInnerPanelLayout->addWidget(new QPushButton());
  testingResultInnerPanelLayout->addWidget(new QTextBrowser());

  // Setup typing
  typingPanel->setLayout(typingPanelLayout);
  // typingPanelLayout->addWidget(typingPanelStatusWidget, 0, 0);
  typingPanelLayout->addWidget(typingPanelTypingWidget, 0, 1);

  // Setup typing panel status widget
  // QGridLayout *typingPanelStatusWidgetLayout = new QGridLayout();

  // Setup typing panel typing widget
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world1")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());



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



  // Connect action callback
  QObject::connect(previousPanelAction, &QAction::triggered, [this]{this->switchToPreviousPanel();});
  QObject::connect(enUsAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::en_US);});
  QObject::connect(zhCnAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_CN);});
  QObject::connect(zhTwAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_TW);});
  QObject::connect(mainPanelAction, &QAction::triggered, [this]{switchToPanel(mainPanel);});
  QObject::connect(articleTypePanelAction, &QAction::triggered, [this]{switchToPanel(articleTypePanel);});
  QObject::connect(typingPanelAction, &QAction::triggered, [this]{switchToPanel(typingPanel);});
  QObject::connect(translatePanelAction, &QAction::triggered, [this]{switchToPanel(translatePanel);});
  QObject::connect(aboutAction, &QAction::triggered, [this]{this->popUpAboutWindow();});

  // Connect button callback
  QObject::connect(aboutWindowOkButton, &QPushButton::clicked, [this]{this->aboutWindow->hide();});
  QObject::connect(articleTypePanelButton, &QPushButton::clicked, [this]{switchToPanel(articleTypePanel);});
  QObject::connect(worldSubTypePanelButton, &QPushButton::clicked, [this]{switchToPanel(worldSubTypePanel);});
  QObject::connect(africaArticleTitlePanelButton, &QPushButton::clicked, [this, crawler] {
    switchToPanel(articleTitlePanel);
    std::vector<std::string> articleTitles = crawler->fetchArticleTitles("africa");
    setArticleTitles(articleTitles);
  });
  QObject::connect(businessArticlePanelButton, &QPushButton::clicked, [this, crawler] {
    switchToPanel(articleTitlePanel);
    std::vector<std::string> articleTitles = crawler->fetchArticleTitles("business");
    setArticleTitles(articleTitles);
  });
  QObject::connect(typingPanelButton, &QPushButton::clicked, [this]{switchToPanel(typingPanel);});
  QObject::connect(testingPanelButton, &QPushButton::clicked, [this]{switchToPanel(testingPanel);});
  QObject::connect(testingInnerPanelSubmitButton, &QPushButton::clicked, [this]{switchToPanel(testingResultPanel);});
  QObject::connect(translatePanelButton, &QPushButton::clicked, [this]{switchToPanel(translatePanel);});
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
  testingResultTitleLabel->setText(QPushButton::tr("Testing Result:"));

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
    QObject::connect(button, &QPushButton::clicked, [this, button]{
      setArticle("");
      switchToPanel(articlePanel);
      std::string article = crawler->fetchArticle(button->text().toStdString());
      this->setArticle(article);
    });
    articleTitlePanelLayout->addWidget(button);
  }
}

void MainWindow::setArticle(const std::string &article)
{
  std::cout << "void MainWindow::setArticle(const std::string &article)\n";
  articlePanelTextBrowser->setText(QString::fromStdString(article));
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

QGroupBox* MainWindow::createSingleChoiceQuestion(const std::string &question, const std::vector<std::string> &candidateAnswers)
{
  QGroupBox *questionGroupBox = new QGroupBox();
  QVBoxLayout *questionGroupBoxLayout = new QVBoxLayout(questionGroupBox);

  // Add question
  questionGroupBox->setTitle(QString::fromStdString(question));

  // Add candidate answer
  for(auto candidateAnswer : candidateAnswers)
  {
    QRadioButton *button = new QRadioButton(questionGroupBox);
    button->setText(QString::fromStdString(candidateAnswer));
    questionGroupBoxLayout->addWidget(button);
  }

  return questionGroupBox;
}

QGroupBox* MainWindow::createMultipleChoiceQuestion(const std::string &question, const std::vector<std::string> &candidateAnswers)
{
  QGroupBox *questionGroupBox = new QGroupBox();
  QVBoxLayout *questionGroupBoxLayout = new QVBoxLayout(questionGroupBox);

  // Add question
  questionGroupBox->setTitle(QString::fromStdString(question));

  // Add candidate answer
  for(auto candidateAnswer : candidateAnswers)
  {
    QCheckBox *button = new QCheckBox(questionGroupBox);
    button->setText(QString::fromStdString(candidateAnswer));
    questionGroupBoxLayout->addWidget(button);
  }

  return questionGroupBox;
}
