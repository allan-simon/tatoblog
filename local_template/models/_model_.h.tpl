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

#ifndef TATOBLOG_%%MODEL_INCLUDE%%
#define TATOBLOG_%%MODEL_INCLUDE%%

#include <cppcms_skel/models/SqliteModel.h>

namespace tatoblog {
namespace models {


/**
 * @class %%MODEL_NAME%% %%MODEL_DESCRIPTION%%
 *
 * @since %%MODEL_TODAY%%
 *
 */
class %%MODEL_NAME%% : public cppcmsskel::models::SqliteModel {
    public:
        /**
         * @brief Constructor
         * @since %%MODEL_TODAY%%
         */
        %%MODEL_NAME%%();

};

} // end namespace models
} // end namespace tatoblog

#endif
