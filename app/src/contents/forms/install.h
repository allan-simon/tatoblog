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

#define _(X) cppcms::locale::translate(X)

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
     * @brief Field to enter the global title of this blog
     */
    cppcms::widgets::text blogTitle;
    
    /**
     * @brief Field to enter the administrator's name
     */
    cppcms::widgets::text adminName;

    /**
     * @brief Field to enter the admin's password
     */
    cppcms::widgets::password password;
    
    /**
     * @brief Field to enter a second time the password (to avoid typo)
     */
    cppcms::widgets::password passwordTwice;
    
    /**
     * @brief Field use to precise what will be the introduction put on the
     *        main page to describe the blog's goal
     */
    cppcms::widgets::textarea blogIntroduction;

    /**
     * @brief Field that will be put at the bottom of the page
     */
    cppcms::widgets::text blogCopyright;

    /**
     * @brief button to submit the form
     */
    cppcms::widgets::submit submit;

    /**
     * @brief Constructor
     */
    Install() {

        //%%%NEXT_WIDGET_ADD_MARKER%%%
        blogTitle.name("blogtitle");
        blogTitle.message(_("Blog's title"));
        blogTitle.non_empty();
        add(blogTitle); 

        adminName.name("adminname");
        adminName.message(_("Admnistrator's name"));
        adminName.non_empty();
        add(adminName); 


        password.name("password");
        password.message(_("Admnistrator's password"));
        password.non_empty();
        add(password); 

        passwordTwice.name("passwordtwice");
        passwordTwice.message(_("Admnistrator's password, again"));
        passwordTwice.non_empty();
        add(passwordTwice); 


        blogIntroduction.name("blogintroduction");
        blogIntroduction.message(_("Blog's introduction"));
        blogIntroduction.non_empty();
        add(blogIntroduction); 

        blogCopyright.name("blogcopyright");
        blogCopyright.message(_("Blog's copyright"));
        blogCopyright.non_empty();
        add(blogCopyright); 

        add(submit);
        submit.name(
            cppcms::locale::translate("submit")
        );
        submit.value("submit");
    }

    /**
     *
     */
    virtual bool validate() {
        return form::validate() &&
            password.value().compare(passwordTwice.value()) == 0;
    }


};


} // end of namespace admin
}// end of namespace forms


#endif


