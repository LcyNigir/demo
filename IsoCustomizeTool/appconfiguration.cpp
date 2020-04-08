#include "appconfiguration.h"

#include <DFontSizeManager>



AppConfiguration::AppConfiguration(QWidget *parent) : QWidget(parent)
{
    DLabel *label = new DLabel("程序配置");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);

    QWidget *messageBox = new QWidget(this);
    QVBoxLayout *messageLayout = new QVBoxLayout;
    messageBox->setLayout(messageLayout);


    DLabel *label2 = new DLabel("请选择程序");
    DFontSizeManager::instance()->bind(label2, DFontSizeManager::T2);
    label2->setAlignment(Qt::AlignCenter);
    label2->setEnabled(false);

    DCommandLinkButton *clearButton = new DCommandLinkButton(tr("全部清除"), this);
    clearButton->hide();

    DCommandLinkButton *commandLinkButton = new DCommandLinkButton(tr("选择程序deb包"));

    DPushButton *nextButton = new DPushButton("下一步");
    nextButton->setEnabled(false);

    QHBoxLayout *firstLayout = new QHBoxLayout;
    QHBoxLayout *hnextLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    firstLayout->addWidget(label);
    firstLayout->addWidget(clearButton);
    firstLayout->setAlignment(clearButton, Qt::AlignRight);

    mainLayout->addLayout(firstLayout);
    mainLayout->addWidget(messageBox);
    mainLayout->addStretch();
    connect(commandLinkButton, &DCommandLinkButton::clicked, [ = ]() {
        DFileDialog *fileDialog = new DFileDialog();
        fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
        fileDialog->setNameFilter("*.deb");
        if (fileDialog->exec() == QDialog::Accepted) {
            clearButton->show();
            QStringList strSelectedName = fileDialog->selectedFiles();
            floatMessage = new DFloatingMessage(DFloatingMessage::ResidentType, this);
            floatMessage->setIcon(QIcon::fromTheme("iso_progress"));
            floatMessage->setMessage(strSelectedName[0]);
            floatMessage->show();
            m_floatingMessage.append(floatMessage);
            label2->hide();
            nextButton->setEnabled(true);
            messageLayout->addWidget(floatMessage);
        }
    });
    mainLayout->addWidget(label2);
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
        label2->show();
        clearButton->hide();
    });

    connect(nextButton, &DPushButton::clicked, [ = ]() {

        emit sendSignal(2);
    });
}
