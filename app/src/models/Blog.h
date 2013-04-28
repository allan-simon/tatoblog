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
 * @package  Models
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */

#ifndef TATOBLOG_BLOG
#define TATOBLOG_BLOG



#include <cppcms_skel/models/SqliteModel.h>


namespace tatoblog {
namespace models {

#define BLOG_UPDATE_OK 1
#define BLOG_DELETE_ERROR -1
#define BLOG_INSERT_ERROR -2

/**
 * @class Blog Model class to manage the general informatoin about
 *             THe blog itself
 * 
 * @since 25 April 2013       
 *
 */
class Blog : public cppcmsskel::models::SqliteModel {
    public:
        /**
         * @brief Constructor
         * @since 25 April 2013
         */
        Blog();
        
        /**
         * @brief Used to save the information about the blog
         *        Note if there's already information, it will
         *        replace them
         *
         * @param blogTitle        The title of this blog
         * @param blogIntroduction A short text that introduce the blog
         * @param blogCopyright    A copyright notice about the content
         * 
         * @return int A number > 0 if no problems, < 0 otherwise
         *
         * @since 25 April 2013
         */
        int save_information(
            const std::string &blogTitle,
            const std::string &blogIntroduction,
            const std::string &blogCopyright
        );

};

} // end namespace models 
} // end namespace tatoblog

#endif
