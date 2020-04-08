#include "selectkernel.h"



SelectKernel::SelectKernel(QWidget *parent) : QWidget(parent)
{
    DLabel *firstTitle = new DLabel("选择Kernel");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    firstTitle->setFont(font);
    DFontSizeManager::instance()->bind(firstTitle, DFontSizeManager::T3);

    DLabel *smallTitle1 = new DLabel("kernel");

    DLabel *smallTitle2 = new DLabel("initrd");

    DFileChooserEdit *kernelChooser = new DFileChooserEdit();
    kernelChooser->setNameFilters(QStringList("所有文件(*)"));

    DFileChooserEdit *initrdChooser = new DFileChooserEdit();
    initrdChooser->setNameFilters(QStringList("initrd(*.lz)"));

    DPushButton *nextButton = new DPushButton("下一步");
    nextButton->setEnabled(false);

    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(firstTitle);
    mainLayout->addWidget(smallTitle1);
    mainLayout->addWidget(kernelChooser);
    mainLayout->addWidget(smallTitle2);
    mainLayout->addWidget(initrdChooser);
    mainLayout->addStretch();

    hLayout->addSpacing(120);
    hLayout->addWidget(nextButton);
    hLayout->addSpacing(120);

    mainLayout->addLayout(hLayout);

    this->setLayout(mainLayout);

    connect(kernelChooser, &DFileChooserEdit::fileChoosed, [ = ](const QString & fileName) {
        if (!fileName.isEmpty() && !initrdChooser->text().isEmpty()) {
            nextButton->setEnabled(true);
        }
    });

    connect(initrdChooser, &DFileChooserEdit::fileChoosed, [ = ](const QString & fileName) {
        if (!fileName.isEmpty() && !kernelChooser->text().isEmpty()) {
            nextButton->setEnabled(true);
        }
    });

    connect(nextButton, &DPushButton::clicked, [ = ]() {
        emit sendSignal(6);
    });
}
