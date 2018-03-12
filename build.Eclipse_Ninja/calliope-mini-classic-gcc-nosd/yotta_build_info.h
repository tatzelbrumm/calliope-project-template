#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 12 // UTC day 1-31
#define YOTTA_BUILD_HOUR 1 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 43 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 11 // UTC second 0-61
#define YOTTA_BUILD_UUID 0404ed19-21ec-4c44-b3ae-7f4133504a4c // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 116c60e390a8eed3f55ff213c96c9dae67484e2f // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 116c60e // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
