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
 * @package  Form
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */


#ifndef TATOBLOG_EDIT
#define TATOBLOG_EDIT


#include "contents/forms/base_post_form.h"

namespace tatoblog {
namespace forms{
namespace posts {

/**
 * @struct edit
 * @brief  @TODO
 * @since  02 November 2013
 *
 */
struct Edit : public BasePost {

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


} // end of namespace posts
} // end of namespace forms
} // end of namespace tatoblog


#endif


