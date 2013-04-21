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
 * @package  Controllers
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */

#include <cppcms/session_interface.h>
#include "Admin.h"


#include "contents/Admin.h"

//%%%NEXT_INC_MODEL_CTRL_MARKER%%%


namespace controllers {
namespace webs {

Admin::Admin(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{


    dispatcher().assign("/install", &Admin::install, this);
    dispatcher().assign("/install_treat", &Admin::install_treat, this);
    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete


    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%
}

/**
 *
 */
Admin::~Admin() {
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
}

/**
 *
 */
void Admin::install() {

    contents::admin::Install c;
    init_content(c);


    render("admin_install", c);
}


/**
 *
 */
void Admin::install_treat() {

    forms::admin::Install form;
    form.load(context());

    if (!form.validate()) {
        go_back_to_previous_page();
    }

}


// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
