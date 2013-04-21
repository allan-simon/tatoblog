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


#ifndef TATOBLOG_INSTALL
#define TATOBLOG_INSTALL


#include <cppcms/form.h>

namespace forms{
namespace admin {

/**
 * @struct install
 * @brief  @TODO
 * @since  22 April 2013
 *
 */
struct Install : public cppcms::form {

    //%%%NEXT_WIDGET_VAR_MARKER%%%

    /**
     * @brief button to submit the form
     */
    cppcms::widgets::submit submit;

    /**
     * @brief Constructor
     */
    Install() {

        //%%%NEXT_WIDGET_ADD_MARKER%%%

        add(submit);
        submit.name(
            cppcms::locale::translate("submit")
        );
        submit.value("submit");
    }


};


} // end of namespace admin
}// end of namespace forms


#endif


