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

#include <cppcms_skel/models/Users.h>
#include <cppcms_skel/generics/Config.h>
#include "Users.h"


#include "contents/Users.h"




//%%%NEXT_INC_MODEL_CTRL_MARKER%%%

namespace tatoblog {
namespace controllers {
namespace webs {

Users::Users(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{


    dispatcher().assign("/logout", &Users::logout, this);
    
    dispatcher().assign("/login", &Users::login, this);
    dispatcher().assign("/login_treat", &Users::login_treat, this);
    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete


    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%

    usersModel = new cppcmsskel::models::Users();
}

/**
 *
 */
Users::~Users() {
    delete usersModel;
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
}

/**
 *
 */
void Users::logout() {
    current_user_logout();
    set_message(_("Logout"));
    go_back_to_previous_page();

}

/**
 *
 */
void Users::login() {

    contents::users::Login c;
    init_content(c);

    // we store in the hidden field of the login form
    // the page we wanted to access
    // in order to be able to redirect on it after login

    std::string wantedPage = request().get("from"); 
    if(wantedPage.empty()) {
        wantedPage = Config::get_base_host();
    }

    c.loginForm.previousUrl.value(
        wantedPage
    );

    render("users_login", c);
}


/**
 *
 */
void Users::login_treat() {
    TREAT_PAGE();

    forms::users::Login form;
    form.load(context());
    
    const std::string username = form.username.value();

    if (!form.validate()) {
        set_message(_("Form didn't validate"));
        go_back_to_previous_page();
    }

    if (
        usersModel->is_login_correct(
            username,
            form.password.value()
        )
    ) {
        set_current_username_and_id(
            username,
            usersModel->get_id_from_name<int>(username)
        );
        // we redirect to the page the user was before going
        // on the login page
        // TODO the message is not displayed try to see why
        // certainly due to successive redirection
        set_message(_("Login"));
        redirect(
            form.previousUrl.value()
        );
    } else {
        set_message(_("Password incorrect"));
        go_back_to_previous_page();
    } 



}


// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog
