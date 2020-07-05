// =-=-=-=-=-=-=-
// irods includes

#include "irods_error.hpp"
#include "irods_ms_plugin.hpp"

#include "icatHighLevelRoutines.hpp"
#include "rcMisc.h"

#include "irods_re_structs.hpp"

// =-=-=-=-=-=-=-
// stl includes

#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <cstring>
#include <sys/time.h>
#include <regex.h>

#include "boost/format.hpp"
#include "string_functions.hpp"


int msiget_precise_time(
    msParam_t*      accum,
    msParam_t*      osec,
    msParam_t*      ousec,
    msParam_t*      sec,    // out - current time
    msParam_t*      usec,   //       in sec & usec
    ruleExecInfo_t* rei )
{
    char *s = NULL;
    char fmtnum [80];
    int status = 0;
    if ( ( s = parseMspForStr(accum ) ) == NULL ) {
        rodsLog( LOG_ERROR, "msiget_precise_time: 'accum' string parameter is NULL." );
        return USER__NULL_INPUT_ERR;
    }
    rodsLong_t old_sec;
    if ((old_sec = parseMspForPosInt( osec )) < 0) {
        rodsLog( LOG_ERROR, "msiget_precise_time: old-seconds parameter is negative." );
        return INPUT_ARG_NOT_WELL_FORMED_ERR;
    }
    int old_usec ;
    if ((old_usec = parseMspForPosInt( ousec )) < 0) {
        rodsLog( LOG_ERROR, "msiget_precise_time: old-usecs parameter is negative." );
        return INPUT_ARG_NOT_WELL_FORMED_ERR;
    }
    timeval tv;
    gettimeofday( &tv, NULL );
    rodsLog(LOG_NOTICE, " %ld sec + %d usec ", (long) (tv.tv_sec), (int) (tv.tv_usec));
    fillDoubleInMsParam (sec,  tv.tv_sec);
    fillIntInMsParam    (usec, tv.tv_usec);
    if (0 == strlen(s))  {
      sprintf (fmtnum,"%ld", (long) tv.tv_sec);
      fillStrInMsParam (accum, fmtnum);
    }
    else{
      char *ends;
      long double elapsed = (long double)( tv.tv_sec - old_sec ) + 1e-06L * (tv.tv_usec - old_usec);
      long double intv = strtold (s, &ends);
      if (s != ends) { elapsed += intv; }
      sprintf (fmtnum,"%Lf", elapsed);
      fillStrInMsParam (accum, fmtnum);
    }
    rei->status = 0;
    return 0;
}

extern "C"
irods::ms_table_entry* plugin_factory() {
    irods::ms_table_entry* msvc = new irods::ms_table_entry(5);
    msvc->add_operation<
        msParam_t*,
        msParam_t*,
        msParam_t*,
        msParam_t*,
        msParam_t*,
        ruleExecInfo_t*>("msiget_precise_time",
                         std::function<int(
                             msParam_t*,
                             msParam_t*,
                             msParam_t*,
                             msParam_t*,
                             msParam_t*,
                             ruleExecInfo_t*)>(msiget_precise_time));
    return msvc;
}

