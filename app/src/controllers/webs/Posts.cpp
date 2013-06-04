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

#include "Posts.h"

#include "contents/Posts.h"

#include "models/Posts.h"
//%%%NEXT_INC_MODEL_CTRL_MARKER%%%

#include "generics/markdown.h"

#define _(X) cppcms::locale::translate(X)

namespace tatoblog {
namespace controllers {
namespace webs {

Posts::Posts(cppcms::service& serv) : Controller(serv)
{

    dispatcher().assign("/show/(.+)", &Posts::show, this, 1);

    dispatcher().assign("/write-new", &Posts::write_new, this);
    dispatcher().assign("/write-new_treat", &Posts::write_new_treat, this);
    dispatcher().assign("/show-all", &Posts::show_all, this);
    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete


    postsModel = new models::Posts();
    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%
}

/**
 *
 */
Posts::~Posts() {
    delete postsModel;
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
}

/**
 *
 */
void Posts::show(const std::string slug) {

    contents::posts::Show c;
    init_content(c);
    std::string lang = get_interface_lang();

    
    c.post  = postsModel->get_from_lang_and_slug(
        lang,
        slug
    );
    
    if (!c.post.exists()) {
        add_error(_("This article does not exists"));
        go_to_main_page();
        return;
    }
    
    c.markdown = mymarkdown;
    c.cacheKey = lang + slug;
 


    render("posts_show", c);
}

/**
 *
 */
void Posts::write_new() {

    CHECK_PERMISSION_OR_GO_TO_LOGIN();
    
    contents::posts::WriteNew c;
    init_content(c);


    render("posts_write_new", c);
}


/**
 *
 */
void Posts::write_new_treat() {

    TREAT_PAGE();
    CHECK_PERMISSION_OR_GO_TO_LOGIN();

    forms::posts::WriteNew form;
    form.load(context());
    if (!form.validate()) {
        //TODO add a more precise message
        add_error(_("The form is not valid."));
        go_back_to_previous_page();
        return;
    }
    
    // we retrieve the information in the form
    const std::string title = form.title.value();
    const std::string slug = form.slug.value();
    const std::string introduction = form.introduction.value();
    const std::string main = form.main.value();

    
    //we save in the database
    const int postId = postsModel->create(
        title,
        slug,
        introduction,
        main,
        "en", // TODO replace this
        get_current_user_id()
    );

    if (postId <= 0) {
        add_error(_("Error while trying to add the post"));
        go_back_to_previous_page();
        return;
    } else if (form.saveAsDraft.value()){
        add_success(_("Post created and saved as draft"));
        //TODO replace this redirection
        redirect("/posts/show/"+slug);
        return;
    } else if (form.publishAndShow.value()) {
        add_success(_("Post created published"));
        redirect("/posts/show/"+slug);
        return;
    }
    // we're not supposed to arrive here
    add_success(_("Unknown error"));
    go_back_to_previous_page();
}

/**
 *
 */
void Posts::show_all() {

    contents::posts::ShowAll c;
    init_content(c);

    c.posts = postsModel->get_all();

    render("posts_show_all", c);
}

// %%%NEXT_ACTION_MARKER%%% , do not delete



} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog
