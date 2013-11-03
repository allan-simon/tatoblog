/**
 * Tatoblog  A blog platform in C++
 * Copyright (C) 2013 Allan Simon <allan.simon@supinfo.com> 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * @category Tatoblog
 * @package  Contents
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */


#ifndef TATOBLOG_CONTENTS_POSTS_H
#define TATOBLOG_CONTENTS_POSTS_H

#include "cppcms_skel/contents/content.h"

#include "contents/forms/write_new.h"
#include "contents/forms/edit.h"
//%%%NEXT_CONTENT_FORM_INCLUDE_MARKER%%%
#include "BaseContent.h"
#include "results/Posts.h"

namespace tatoblog {
namespace contents {
namespace posts {

/**
 * @class Posts
 * @brief Base content for every action of Posts controller
 * @since 17 March 2013
 */
struct Posts : public BaseContent {
};

/**
 * @struct Show Content used to transport the information used to display
 *         a post
 * @since  17 March 2013
 */
struct Show : public Posts {

    /**
     * @brief placeholder for the function that will be called
     *        when using  <%= variable | ext markdown %> in the
     *        template
     *
     * @since 18 April 2013
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
     * @since 18 April 2013
     *
     */
    std::string cacheKey;
 



    results::Post post;

    Show() {

    }

};

/**
 * @struct WriteNew used to transport the information used to display
 *         The page containing a form to create a new post
 * @since  26 March 2013
 */
struct WriteNew : public Posts {

    forms::posts::WriteNew writeNewForm;

    /**
     * @brief Constructor
     */
    WriteNew() {
    }

};

/**
 * @struct ShowAll
 * @since  21 April 2013
 * @brief 
 */
struct ShowAll : public Posts {

    results::Posts posts;

    ShowAll() {

    }

};


/**
 * @struct Edit
 * @since  02 November 2013
 * @brief 
 */
struct Edit : public Posts {

    forms::posts::Edit editForm;
    results::Post post;

    /**
     * @brief Constructor
     */
    Edit(const results::Post &_post) : editForm(_post), post(_post) {
    }

};

//%%%NEXT_CONTENT_MARKER%%%

} // end of namespace posts
} //end of namespace contents
} // end of namespace tatoblog

#endif
