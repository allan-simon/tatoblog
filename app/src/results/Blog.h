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
 * @link     https://github.com/sysko/tatoblog
 */

#ifndef TATOBLOG_RESULTS_BLOG_H
#define TATOBLOG_RESULTS_BLOG_H

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
    struct Blog {
        std::string title;
        std::string introduction;
        std::string copyright;
        
        Blog() {};
        Blog(
            const std::string &title,
            const std::string &introduction,
            const std::string &copyright
        ) :
            title(title),
            introduction(introduction),
            copyright(copyright)
        {
        };
    };

}
} // end namespace tatoblog
#endif

