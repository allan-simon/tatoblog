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


#ifndef TATOBLOG_CONTENTS_USERS_H
#define TATOBLOG_CONTENTS_USERS_H

#include "contents/BaseContent.h"

#include "contents/forms/login.h"
//%%%NEXT_CONTENT_FORM_INCLUDE_MARKER%%%

namespace tatoblog {
namespace contents {
namespace users {

/**
 * @class Users
 * @brief Base content for every action of Users controller
 * @since 29 April 2013
 */
struct Users : public BaseContent {
};

/**
 * @struct Login
 * @since  29 April 2013
 * @brief 
 */
struct Login : public Users {

    forms::users::Login loginForm;

    /**
     * @brief Constructor
     */
    Login() {
    }

};

//%%%NEXT_CONTENT_MARKER%%%

} // end of namespace users
} // end of namespace contents
} // end of namespace tatoblog

#endif
