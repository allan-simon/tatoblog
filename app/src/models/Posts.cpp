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

#include "models/Posts.h"


namespace models {

/**
 *
 */
Posts::Posts() :
    SqliteModel()
{
}

/**
 *
 */
int Posts::create(
    const std::string &title,
    const std::string &slug,
    const std::string &introduction,
    const std::string &main,
    const std::string &lang 
) {
    cppdb::statement statement = sqliteDb.prepare(
        "INSERT INTO posts("
        "    title,"
        "    slug,"
        "    introduction,"
        "    main,"
        "    lang"
        ") "
        "VALUES ( "
        "   ? ,"
        "   ? ,"
        "   ? ,"
        "   ? ,"
        "   ? "
        ")"
    );
    
    statement.bind(title);
    statement.bind(slug);
    statement.bind(introduction);
    statement.bind(main);
    statement.bind(lang);

    try {
        statement.exec();
    } catch (cppdb::cppdb_error const &e) {
        std::cerr << e.what();
        statement.reset();
        return POST_CREATION_ERROR;
    }

    const int id = statement.last_insert_id();
    statement.reset();
    return id;
}


} // end namespace models


