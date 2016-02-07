#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "gis"
#define PGSQL_TABLENAME "ad.vw_ad"

enum Columns {
    ad_pid,
    ad_valid,
    ad_country_pid,
    ad_cityru,
    ad_nameru,
    ad_name,
    ad_indx,
    ad_type,
    ad_intl,
    ad_staff,
    ad_reglament,
    ad_elevation,
    ad_magvar,
    ad_email,
    ad_web,
    ad_note,
    ad_geog,
    ColumnsNumber
};

#endif // DECLARATIONS_H
