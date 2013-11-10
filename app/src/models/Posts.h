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
 * @link     https://github.com/allan-simon/tatoblog
 */

#ifndef TATOBLOG_POSTS
#define TATOBLOG_POSTS

#include "models/AbstractPosts.h"

namespace tatoblog {
namespace models {


/**
 * @class Posts Class to store and retrieve data related
 *        to the post objects
 * 
 * @since 26 March 2013       
 *
 */
class Posts : public AbstractPosts {
    public:
        /**
         * @brief Constructor
         * @since 26 March 2013
         */
        Posts();
       
};

} // end namespace models 
} // end namespace tatoblog

#endif
