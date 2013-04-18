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

#ifndef TATOBLOG_POSTS
#define TATOBLOG_POSTS

#define POST_CREATION_ERROR -1


#include "cppcms_skel/models/SqliteModel.h"
namespace models {


/**
 * @class Posts Class to store and retrieve data related
 *        to the post objects
 * 
 * @since 26 March 2013       
 *
 */
class Posts : public SqliteModel {
    public:
        /**
         * @brief Constructor
         * @since 26 March 2013
         */
        Posts();
        
        /**
         * @brief Create a new article in the database
         *
         * @param title         The title of the new post
         * @param slug          URL of the post
         * @param introduction  Text that will displayed in list
         *                      of posts 
         * @param main          The main text of the post
         * @param lang          Lang in which the article is written
         *
         * @return The id of the newly created Post, or a negative
         *         number in case of failure
         */
        int create(
            const std::string &title,
            const std::string &slug,
            const std::string &introduction,
            const std::string &main,
            const std::string &lang = "en"
        );
};

} // end namespace models 

#endif
