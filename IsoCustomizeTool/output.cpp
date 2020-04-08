#include "output.h"

Output::Output(QWidget *parent) : QWidget(parent)
{
    DLabel *firstTitle = new DLabel("准备输出");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    firstTitle->setFont(font);
    firstTitle->setAlignment(Qt::AlignCenter);
    DFontSizeManager::instance()->bind(firstTitle, DFontSizeManager::T3);

    m_ptimer = new QTimer();
    m_ptimer->setInterval(100);
    connect(m_ptimer, &QTimer::timeout, this, &Output::slotTimerOut);

    m_pDWaterProgress = new DWaterProgress();

    nextButton = new DPushButton("下一步");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *waterLayout = new QHBoxLayout;
    QHBoxLayout *hnextLayout = new QHBoxLayout;

    mainLayout->addWidget(firstTitle);
    mainLayout->addStretch();

    waterLayout->addStretch();
    waterLayout->addWidget(m_pDWaterProgress);
    m_pDWaterProgress->setTextVisible(true);
    m_pDWaterProgress->setValue(m_valus);
    waterLayout->addStretch();


    hnextLayout->addSpacing(120);
    hnextLayout->addWidget(nextButton);
    hnextLayout->addSpacing(120);

    mainLayout->addLayout(waterLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(hnextLayout);


    this->setLayout(mainLayout);

    connect(nextButton, &DPushButton::clicked, [ = ]() {
        m_ptimer->start();
    });

}

void Output::slotTimerOut()
{
    m_valus++;
    if (m_valus == 100) {
        m_ptimer->stop();
    }
    m_pDWaterProgress->setValue(m_valus);
    update();
}
