/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan Simon <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @package  Contents
 *
 */

#ifndef TATOBLOG_CONTENTS_%%CONTROLLER_INCLUDE%%_H
#define TATOBLOG_CONTENTS_%%CONTROLLER_INCLUDE%%_H

#include "cppcms_skel/contents/content.h"

//%%%NEXT_CONTENT_FORM_INCLUDE_MARKER%%%

namespace tatoblog {
namespace contents {
namespace %%CONTROLLER_NS%% {

/**
 * @class %%CONTROLLER_NAME%%
 * @brief Base content for every action of %%CONTROLLER_NAME%% controller
 * @since %%CONTROLLER_TODAY%%
 */
struct %%CONTROLLER_NAME%% : public ::contents::BaseContent {
};

//%%%NEXT_CONTENT_MARKER%%%

} // end of namespace %%CONTROLLER_NS%%
} // end of namespace contents
} // end of namespace tatoblog

#endif
