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
#include <cppcms_skel/generics/Config.h>
#include <cppcms_skel/models/Users.h>

#include "Admin.h"


#include "contents/Admin.h"


#include "models/Blog.h"
//%%%NEXT_INC_MODEL_CTRL_MARKER%%%


namespace controllers {
namespace webs {

Admin::Admin(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{


    dispatcher().assign("/install", &Admin::install, this);
    dispatcher().assign("/install_treat", &Admin::install_treat, this);
    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete


    blogModel = new models::Blog();
    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%
    usersModel = new cppcmsskel::models::Users();
}

/**
 *
 */
Admin::~Admin() {
    delete blogModel;
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
    delete usersModel;
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

    TREAT_PAGE();

    forms::admin::Install form;
    form.load(context());

    if (!form.validate()) {
        set_message(_("Error while validating form."));
        go_back_to_previous_page();
        return;
    }


    std::string blogTitle = form.blogTitle.value();
    std::string blogIntroduction = form.blogIntroduction.value();
    std::string blogCopyright = form.blogCopyright.value();
    std::string adminName = form.adminName.value();
    std::string password = form.password.value();
    

    const int blogResult = blogModel->save_information(
        blogTitle,
        blogIntroduction,
        blogCopyright
    );
    
    if (blogResult < 0 ) {
        set_message(_("Problem while trying to save the blog information"));
        go_back_to_previous_page();
        return;
    }



    // if we can't save because the admin already exists we don't consider it
    // as an error
    if (!usersModel->is_login_correct(adminName,password)) {
        const int adminResult = usersModel->add(
            adminName,
            password,
            "" // TODO: empty email, replace it by a field in the form
        );
                    
        if (adminResult < 0) {
            set_message(
                _("Problem while trying to save the admin information")
            );
            go_back_to_previous_page();
            return;
        }
    }
    const bool setAsAdmin = usersModel->change_permission_level(
        adminName,
        USERS_ADMIN
    );
    
    if (!setAsAdmin) {
        set_message(_("Problem while trying to set the user as admin"));
        go_back_to_previous_page();
        return;
    }
    set_message(_("Blog successfully configurated")); 
    go_to_main_page(); 

}


// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
