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
#include "results/Posts.h"

#include "contents/forms/draft_edit.h"
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

    /**
     * @brief placeholder for the function that will be called
     *        when using  <%= variable | ext markdown %> in the
     *        template
     *
     * @since 10 November 2013
     */
    booster::function<
        std::string(
            const std::string &
        )
    > markdown;

    /**
     * @brief key used for caching the post section of the web
     *        page
     *
     * @since 10 November 2013
     *
     */
    std::string cacheKey;

    results::Post post;

    Show() {

    }

};

/**
 * @struct Edit content used by the draft/edit page
 * @since  16 November 2013
 */
struct Edit : public Drafts {

    ::tatoblog::forms::drafts::Edit editForm;

    /**
     * @brief Constructor
     */
    Edit() {
    }

};

//%%%NEXT_CONTENT_MARKER%%%

} // end of namespace drafts
} // end of namespace contents
} // end of namespace tatoblog

#endif
