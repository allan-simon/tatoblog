/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan Simon <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @package  Models
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
#include <cppdb/frontend.h>

#include "models/%%MODEL_NAME%%.h"


namespace tatoblog {
namespace models {

/**
 *
 */
%%MODEL_NAME%%::%%MODEL_NAME%%() :
    SqliteModel()
{
}


} // end namespace models
} // end namespace tatoblog


