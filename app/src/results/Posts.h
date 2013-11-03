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
 * @category Tatoblog
 * @package  Results
 * @author   Allan SIMON <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/sysko/tatowiki
 */

#ifndef TATOBLOG_RESULTS_POSTS_H
#define TATOBLOG_RESULTS_POSTS_H


#define POST_NOT_COMPLETELY_INIT -42

#include <vector>
#include <map>
#include <string>

namespace tatoblog {
namespace results {

    /**
     * @struct Post Structure to represent a post when doing
     *              models => constructor communication
     *
     * @since 18 April 2013
     *
     */
    struct Post {
        int id;
        std::string lang;
        std::string slug;
        std::string title;
        std::string introduction;
        std::string main;

        /**
         * @brief test if post is an existing one or not
         *
         * @return bool True if it exists, false otherwise
         *
         * @since 18 April 2013
         *
         */
        bool exists() {
            return id > 0;
        };


        /**
         * Get string used for cache to identify a post
         * @return string Key to identify a post
         * @since 3 November 2013
         */
        const std::string cache_key() {
            return lang + slug;
        }

        Post() {};
        Post(
            const int id,
            const std::string &lang,
            const std::string &slug,
            const std::string &title,
            const std::string &introduction = "",
            const std::string &main = ""
        ) :
            id(id),
            lang(lang),
            slug(slug),
            title(title),
            introduction(introduction),
            main(main)
        {
        };


        /**
         *
         */
        const std::string edit_url() const {
            return "/posts/edit/" + slug;
        }

        /**
         *
         */
        const std::string show_url() const {
            return "/posts/show/" + slug;
        }

    };

    typedef std::vector<results::Post> Posts;



}
}

#endif

