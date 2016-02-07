#include <QtWidgets>
#include <QtSql>

#include "maindialog.h"
#include "declarations.h"
#include "mapperdialog.h"


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
    m_model->select();

    m_model->setHeaderData(ad_valid,       Qt::Horizontal, trUtf8("Действующий/\nНедействующий"));
    m_model->setHeaderData(ad_country_pid, Qt::Horizontal, trUtf8("Страна"));
    m_model->setHeaderData(ad_cityru,      Qt::Horizontal, trUtf8("Город"));
    m_model->setHeaderData(ad_nameru,      Qt::Horizontal, trUtf8("Аэродром"));
    m_model->setHeaderData(ad_name,        Qt::Horizontal, trUtf8("Aerodrome\n(EN)"));
    m_model->setHeaderData(ad_indx,        Qt::Horizontal, trUtf8("Индекс"));
    m_model->setHeaderData(ad_type,        Qt::Horizontal, trUtf8("Тип аэродрома"));
    m_model->setHeaderData(ad_intl,        Qt::Horizontal, trUtf8("Международный"));
    m_model->setHeaderData(ad_staff,       Qt::Horizontal, trUtf8("Организация"));
    m_model->setHeaderData(ad_reglament,   Qt::Horizontal, trUtf8("Регламент\nработы"));
    m_model->setHeaderData(ad_elevation,   Qt::Horizontal, trUtf8("Превышение"));
    m_model->setHeaderData(ad_magvar,      Qt::Horizontal, trUtf8("Магнитное\nсклонение"));
    m_model->setHeaderData(ad_email,       Qt::Horizontal, trUtf8("E-mail"));
    m_model->setHeaderData(ad_web,         Qt::Horizontal, trUtf8("Web-сайт"));
    m_model->setHeaderData(ad_note,        Qt::Horizontal, trUtf8("Примечание"));
    m_model->setHeaderData(ad_geog,        Qt::Horizontal, trUtf8("Координаты"));
}

void MainDialog::setupView()
{
    m_view->setModel(m_model);
//    m_view->setItemDelegate(new PersonModelDelegate(m_view));

    m_view->resizeColumnsToContents();
//    m_view->resizeRowsToContents();
    m_view->horizontalHeader()->setStretchLastSection(true);

    m_view->verticalHeader()->show();

    m_view->hideColumn(ad_pid);
    m_view->hideColumn(ad_reglament);
    m_view->hideColumn(ad_elevation);
    m_view->hideColumn(ad_magvar);
    m_view->hideColumn(ad_email);
    m_view->hideColumn(ad_web);
    m_view->hideColumn(ad_note);
    m_view->hideColumn(ad_geog);

    m_view->selectRow(0);
}

void MainDialog::setupMapperDialog()
{
    MapperDialog *mapperDialog = new MapperDialog(m_model, this);
    m_mapperDialog = static_cast<VyborgMapperDialog *>(mapperDialog);
    m_mapperDialog->resize(800, 480);
}

void MainDialog::setupFilterDialog()
{
//    filterDialog_->addColumn(trUtf8("ICAO code"), AC_ICAO);
//    filterDialog_->addColumn(trUtf8("IATA code"), AC_IATA);
//    filterDialog_->addColumn(trUtf8("Российский код"), AC_codeRu);
//    filterDialog_->addColumn(trUtf8("Callsign"), AC_CS);
//    filterDialog_->addColumn(trUtf8("Позывной а/к"), AC_CSru);
//    filterDialog_->addColumn(trUtf8("Company name"), AC_AC);
//    filterDialog_->addColumn(trUtf8("Название а/к"), AC_ACru);
//    filterDialog_->addColumn(trUtf8("Страна"), AC_country_id);
}

void MainDialog::setupSortDialog()
{
//    sortDialog_->addColumn(trUtf8("ICAO code"), AC_ICAO);
//    sortDialog_->addColumn(trUtf8("IATA code"), AC_IATA);
//    sortDialog_->addColumn(trUtf8("Российский код"), AC_codeRu);
//    sortDialog_->addColumn(trUtf8("Callsign"), AC_CS);
//    sortDialog_->addColumn(trUtf8("Позывной а/к"), AC_CSru);
//    sortDialog_->addColumn(trUtf8("Company name"), AC_AC);
//    sortDialog_->addColumn(trUtf8("Название а/к"), AC_ACru);
//    sortDialog_->addColumn(trUtf8("Страна"), AC_country_id);
}
