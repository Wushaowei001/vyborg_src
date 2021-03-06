#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "declarations.h"
#include "mapperdialog.h"

#include <QDebug>


MainDialog::MainDialog(QWidget *parent)
    : VyborgMainDialog(parent)
{
    setupModel();
    setupView();
    setupMapperDialog();
    setupFilterDialog();
    setupSortDialog();
}

void MainDialog::setupModel()
{
    m_model->setTable(PGSQL_TABLENAME);
    bool ret = m_model->select();
    if (ret == false) {
        QString msgText("SELECT returned FALSE: " + m_model->lastError().text());
        QMessageBox::warning(this,
                             "ERROR",
                             msgText,
                             QMessageBox::Close);
        qApp->quit();
    }

    m_model->setHeaderData(shedule_fullname,       Qt::Horizontal, trUtf8("Имя"),             Qt::DisplayRole);
//    m_model->setHeaderData(shedule_middlename, Qt::Horizontal, trUtf8("Отчетсво"),        Qt::DisplayRole);
//    m_model->setHeaderData(shedule_surname,    Qt::Horizontal, trUtf8("Фамилия"),         Qt::DisplayRole);
    m_model->setHeaderData(shedule_innernum,   Qt::Horizontal, trUtf8("Табельный номер"), Qt::DisplayRole);
    m_model->setHeaderData(shedule_shiftnum,   Qt::Horizontal, trUtf8("Номер смены"),     Qt::DisplayRole);
    m_model->setHeaderData(shedule_sector_pid, Qt::Horizontal, trUtf8("Сектор"),          Qt::DisplayRole);
    m_model->setHeaderData(shedule_activity,   Qt::Horizontal, trUtf8("Активность"),      Qt::DisplayRole);
    m_model->setHeaderData(shedule_start,      Qt::Horizontal, trUtf8("Дата начала"),     Qt::DisplayRole);
    m_model->setHeaderData(shedule_stop,       Qt::Horizontal, trUtf8("Дата окончания"),  Qt::DisplayRole);
}


void MainDialog::setupView()
{
    m_view->setModel(m_model);

    m_view->resizeRowsToContents();
    m_view->resizeColumnsToContents();

    m_view->selectRow(0);

    m_view->resizeRowsToContents();
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(m_model);
    m_mapperDialog = static_cast<VyborgMapperDialog *>(mapperDialog);
}

void MainDialog::setupFilterDialog()
{
//    filterDialog_->addColumn(trUtf8("Дата"), trUtf8("date"));
//    filterDialog_->addColumn(trUtf8("Внутренние рейсы"), trUtf8("internal"));
//    filterDialog_->addColumn(trUtf8("Международные рейсы"), trUtf8("external"));
//    filterDialog_->addColumn(trUtf8("Транзитные рейсы"), trUtf8("transit"));
//    filterDialog_->addColumn(trUtf8("Рейсы вне расписания (чартерные) рейсы"), trUtf8("charter"));
//    filterDialog_->addColumn(trUtf8("Максимальная суточная интенсивность ВС секторов РДЦ рейсы"), trUtf8("maxday"));
//    filterDialog_->addColumn(trUtf8("Рейсы иностранных авиакомпаний"), trUtf8("foreigner"));
}

void MainDialog::setupSortDialog()
{
//    sortDialog_->addColumn(trUtf8("Дата"), statistics_date);
//    sortDialog_->addColumn(trUtf8("Внутренние рейсы"), statistics_internal);
//    sortDialog_->addColumn(trUtf8("Международные рейсы"), statistics_external);
//    sortDialog_->addColumn(trUtf8("Транзитные рейсы"), statistics_transit);
//    sortDialog_->addColumn(trUtf8("Рейсы вне расписания (чартерные) рейсы"), statistics_charter);
//    sortDialog_->addColumn(trUtf8("Максимальная суточная интенсивность ВС секторов РДЦ рейсы"), statistics_maxday);
//    sortDialog_->addColumn(trUtf8("Рейсы иностранных авиакомпаний"), statistics_foreigner);
}

