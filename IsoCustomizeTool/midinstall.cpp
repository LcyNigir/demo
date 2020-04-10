#include "midinstall.h"

#include <QFileIconProvider>

MidInstall::MidInstall(QWidget *parent)
    : QWidget(parent)
{
    DLabel *topLabel = new DLabel("中期安装");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    topLabel->setFont(font);
    DFontSizeManager::instance()->bind(topLabel, DFontSizeManager::T3);

    QWidget *messageBox = new QWidget(this);
    QVBoxLayout *messageLayout = new QVBoxLayout;
    messageBox->setLayout(messageLayout);


    DLabel *midLabel = new DLabel("请选择中期安装");
    DFontSizeManager::instance()->bind(midLabel, DFontSizeManager::T2);
    midLabel->setAlignment(Qt::AlignCenter);
    midLabel->setEnabled(false);

    DCommandLinkButton *clearButton = new DCommandLinkButton(tr("全部清除"), this);
    clearButton->hide();

    DCommandLinkButton *commandLinkButton = new DCommandLinkButton(tr("选择脚本"));

    DPushButton *nextButton = new DPushButton("下一步");

    QHBoxLayout *firstLayout = new QHBoxLayout;
    QHBoxLayout *hnextLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;


    firstLayout->addWidget(topLabel);
    firstLayout->addWidget(clearButton);
    firstLayout->setAlignment(clearButton, Qt::AlignRight);

    mainLayout->addLayout(firstLayout);
    mainLayout->addWidget(messageBox);
    mainLayout->addStretch();

    connect(commandLinkButton, &DCommandLinkButton::clicked, [ = ]() {
        DFileDialog *fileDialog = new DFileDialog();
        fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
        fileDialog->setFileMode(QFileDialog::ExistingFiles);
        fileDialog->setNameFilter("*.job");

        if (fileDialog->exec() == QDialog::Accepted) {
            clearButton->show();
            QStringList strSelectedName = fileDialog->selectedFiles();

            for (int i = 0; i < strSelectedName.size(); i++) {
                floatMessage = new DFloatingMessage(DFloatingMessage::ResidentType, this);
                floatMessage->setIcon(getIcon(strSelectedName[i]));
                floatMessage->setMessage(strSelectedName[i]);
                floatMessage->show();
                m_floatingMessage.append(floatMessage);
                messageLayout->addWidget(floatMessage);
            }

            midLabel->hide();
            nextButton->setEnabled(true);

        }

    });

    mainLayout->addWidget(midLabel);
    mainLayout->addStretch();

    mainLayout->addWidget(commandLinkButton);
    mainLayout->setAlignment(commandLinkButton, Qt::AlignCenter);

    hnextLayout->addSpacing(120);
    hnextLayout->addWidget(nextButton);
    hnextLayout->addSpacing(120);

    mainLayout->addLayout(hnextLayout);

    this->setLayout(mainLayout);

    connect(clearButton, &DCommandLinkButton::clicked, [ = ]() {
        for (int i = 0; i < m_floatingMessage.size(); i++) {
            m_floatingMessage[i]->close();
        }
        midLabel->show();
        clearButton->hide();
    });

    connect(nextButton, &DPushButton::clicked, [ = ]() {
        emit sendSignal(4);
    });
}

QIcon MidInstall::getIcon(QString ico)
{
    QFileIconProvider provider;
    QIcon icon;
    icon = provider.icon(QFileInfo(ico));
    return icon;
}

