/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @package  Contents
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @link     https://github.com/allan-simon/tatoblog
 */




#ifndef TATOBLOG_CONTENTS_DRAFTS_H
#define TATOBLOG_CONTENTS_DRAFTS_H

#include "contents/BaseContent.h"

//%%%NEXT_CONTENT_FORM_INCLUDE_MARKER%%%

namespace tatoblog {
namespace contents {
namespace drafts {

/**
 * @class Drafts
 * @brief Base content for every action of Drafts controller
 * @since 10 November 2013
 */
struct Drafts : public BaseContent {
};

/**
 * @struct Show
 * @since  10 November 2013
 * @brief 
 */
struct Show : public Drafts {

    Show() {

    }

};

//%%%NEXT_CONTENT_MARKER%%%

} // end of namespace drafts
} // end of namespace contents
} // end of namespace tatoblog

#endif
