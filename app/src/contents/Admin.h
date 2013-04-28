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


#ifndef TATOBLOG_CONTENTS_ADMIN_H
#define TATOBLOG_CONTENTS_ADMIN_H


#include "contents/forms/install.h"
#include "contents/BaseContent.h"
//%%%NEXT_CONTENT_FORM_INCLUDE_MARKER%%%

namespace tatoblog {
namespace contents {
namespace admin {

/**
 * @class Admin
 * @brief Base content for every action of Admin controller
 * @since 22 April 2013
 */
struct Admin : public BaseContent {
};

/**
 * @struct Install
 * @since  22 April 2013
 * @brief 
 */
struct Install : public Admin {

    forms::admin::Install installForm;

    /**
     * @brief Constructor
     */
    Install() {
    }

};

//%%%NEXT_CONTENT_MARKER%%%

} // end of namespace admin
} // end of namespace contents
} // end of namespace tatoblog

#endif
