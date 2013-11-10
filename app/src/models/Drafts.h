/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @package  Models
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @link     https://github.com/allan-simon/tatoblog
 */

#ifndef TATOBLOG_DRAFTS
#define TATOBLOG_DRAFTS

#include "models/AbstractPosts.h"

namespace tatoblog {
namespace models {

/**
 * @class Drafts Store and retrieve data related to draft object
 *               (i.e post that are not yet published)
 * 
 * @since 10 November 2013       
 *
 */
class Drafts: public AbstractPosts {
    public:
        /**
         * @brief Constructor
         * @since 10 November 2013
         */
        Drafts();

};

} // end namespace models 
} // end namespace tatoblog

#endif
