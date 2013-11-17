/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @package  Forms
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @link     https://github.com/allan-simon/tatoblog
 */

#ifndef TATOBLOG_DRAFT_EDIT
#define TATOBLOG_DRAFT_EDIT


#include "contents/forms/base_post_form.h"

namespace tatoblog {
namespace forms{
namespace drafts {

/**
 * @struct edit
 * @brief  @TODO
 * @since  16 November 2013
 *
 */
struct Edit : public posts::BasePost {

    /**
     * @brief Constructor
     */

    Edit() : BasePost() {
        init_and_add();
    }

    Edit(results::Post post) : BasePost() {
        init_and_add();
        id.value(std::to_string(post.id));
        lang.value(post.lang);
        title.value(post.title);
        slug.value(post.slug);
        introduction.value(post.introduction);
        main.value(post.main);
    }

};


} // end of namespace drafts
} // end of namespace forms
} // end of namespace tatoblog


#endif


