#include "output.h"

Output::Output(QWidget *parent) : QWidget(parent)
{
    firstTitle = new DLabel("准备输出");
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
    tips = new DLabel("正在制作，请稍后...");
    tips->hide();

    successIcon = new DLabel(this);
    successIcon->hide();
    successIcon->resize(110, 110);
    successIcon->setPixmap(QPixmap(":/icons/deepin/builtin/light/icons/iso_progress_111px.svg"));
    successTips = new DLabel("制作成功", this);
    successTips->hide();

    failedIcon = new DLabel(this);
    failedIcon->hide();
    failedIcon->resize(110, 110);
    failedIcon->setPixmap(QPixmap(":/icons/deepin/builtin/light/icons/fail_image_110px.svg"));
    failedTips = new DLabel("制作失败", this);
    failedTips->hide();

    nextButton = new DPushButton("下一步");

    finishButton = new DPushButton("完成");
    finishButton->hide();
    checkFileButton = new DPushButton("查看文件");
    checkFileButton->hide();

    closeButton = new DPushButton("关闭");
    closeButton->hide();

    connect(closeButton, &DPushButton::clicked, [ = ]() {
        this->close();
    });

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *waterLayout = new QHBoxLayout;
    QHBoxLayout *hnextLayout = new QHBoxLayout;

    mainLayout->addWidget(firstTitle);
    mainLayout->addStretch();
    mainLayout->addWidget(successIcon);
    mainLayout->addWidget(failedIcon);
    mainLayout->setAlignment(successIcon, Qt::AlignCenter);
    mainLayout->setAlignment(failedIcon, Qt::AlignCenter);

    waterLayout->addStretch();
    waterLayout->addWidget(m_pDWaterProgress);
    m_pDWaterProgress->setTextVisible(true);
    m_pDWaterProgress->setValue(m_valus);
    waterLayout->addStretch();


    hnextLayout->addSpacing(120);
    hnextLayout->addWidget(nextButton);
    hnextLayout->addWidget(finishButton);
    hnextLayout->addWidget(checkFileButton);
    hnextLayout->addWidget(closeButton);
    hnextLayout->addSpacing(120);



    mainLayout->addLayout(waterLayout);
    mainLayout->addWidget(tips, 0, Qt::AlignCenter);
    mainLayout->addWidget(successTips, 0, Qt::AlignCenter);
    mainLayout->addWidget(failedTips, 0, Qt::AlignCenter);
    mainLayout->addStretch();
    mainLayout->addLayout(hnextLayout);


    this->setLayout(mainLayout);

    connect(nextButton, &DPushButton::clicked, [ = ]() {
        m_ptimer->start();
        nextButton->setEnabled(false);
        firstTitle->setText("正在输出");
        tips->show();
    });
}

void Output::slotTimerOut()
{
    m_valus++;
    if (m_valus == 100) {
        m_ptimer->stop();
        m_pDWaterProgress->hide();
        tips->hide();
        nextButton->hide();
        successIcon->show();
        successTips->show();
        firstTitle->setText("输出成功");
        finishButton->show();
        checkFileButton->show();
    } /*else if (m_valus != 100) {*/
//        firstTitle->setText("输出失败");
//        failedTips->show();
//        failedIcon->show();
//        failedTips->show();
//        closeButton->show();
//    }
    m_pDWaterProgress->setValue(m_valus);
    update();
}
