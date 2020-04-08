#ifndef OUTPUT_H
#define OUTPUT_H

#include <DApplication>
#include <DLabel>
#include <DPushButton>
#include <DWaterProgress>
#include <DFontSizeManager>

#include <QWidget>
#include <QHBoxLayout>
#include <QTimer>

DWIDGET_USE_NAMESPACE

class Output : public QWidget
{
    Q_OBJECT
public:
    explicit Output(QWidget *parent = nullptr);
    void slotTimerOut();

signals:

public slots:
private:
    QTimer *m_ptimer;
    DWaterProgress *m_pDWaterProgress;

    int m_valus = 0;
    DPushButton *nextButton;
    DPushButton *finishButton;
    DPushButton *checkFileButton;
    DPushButton *closeButton;

    DLabel *firstTitle;
    DLabel *successIcon;
    DLabel *successTips;
    DLabel *failedIcon;
    DLabel *failedTips;
    DLabel *tips;
};

#endif // OUTPUT_H
