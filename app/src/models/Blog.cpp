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
 * @package  Models
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */


#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
#include <cppdb/frontend.h>

#include "models/Blog.h"


namespace models {

/**
 *
 */
Blog::Blog() :
    SqliteModel()
{
}

/**
 *
 */
int Blog::save_information(
    const std::string &blogTitle,
    const std::string &blogIntroduction,
    const std::string &blogCopyright
) {
    // we first delete the previous information
    cppdb::statement statement = sqliteDb.prepare(
        "DELETE FROM blog" 
    );
    
    if (!execute_simple(statement)) {
        return BLOG_DELETE_ERROR;
    }
    // then we add the new ones 
    statement = sqliteDb.prepare(
        "INSERT INTO blog ("
        "   title, "
        "   introduction, "
        "   copyright "
        ") "
        "VALUES ( "
        "   ? ,"
        "   ? ,"
        "   ? "
        ")"
    );
    statement.bind(blogTitle);
    statement.bind(blogIntroduction);
    statement.bind(blogCopyright);
    
    if (!execute_simple(statement)) {
        return BLOG_INSERT_ERROR;
    }
    return BLOG_UPDATE_OK;
}


} // end namespace models


