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

    dispatcher().assign("/edit/(.*)", &Posts::edit, this, 1);
    dispatcher().assign("/edit_treat", &Posts::edit_treat, this);
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
    c.cacheKey = c.post.cache_key();



    render("posts_show", c);
}

/**
 *
 */
void Posts::write_new() {

    LOGIN_REQUIRED();

    contents::posts::WriteNew c;
    init_content(c);


    render("posts_write_new", c);
}


/**
 *
 */
void Posts::write_new_treat() {

    TREAT_PAGE();
    LOGIN_REQUIRED();

    forms::posts::WriteNew form;
    form.load(context());
    if (!form.validate()) {
        //TODO add a more precise message
        add_error(_("The form is not valid."));
        go_back_to_previous_page();
        return;
    }

    results::Post post = form.get_post();
    post.lang = get_interface_lang();

    //we save in the database
    const int postId = postsModel->create(
        post,
        get_current_user_id()
    );

    if (postId <= 0) {
        add_error(_("Error while trying to add the post"));
        go_back_to_previous_page();
        return;
    }

    if (form.saveAsDraft.value()){
        add_success(_("Post created and saved as draft"));
        redirect(post.show_url());
        return;
    }

    if (form.publishAndShow.value()) {
        add_success(_("Post created published"));
        redirect(post.show_url());
        return;
    }
    // we're not supposed to arrive here
    add_error(_("Unknown error"));
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

/**
 *
 */
void Posts::edit(
    const std::string slug
) {

    LOGIN_REQUIRED();

    const std::string lang = get_interface_lang();

    results::Post post = postsModel->get_from_lang_and_slug(
        lang,
        slug
    );

    cache().rise(post.cache_key());

    contents::posts::Edit c(post);

    init_content(c);

    render("posts_edit", c);
}


/**
 *
 */
void Posts::edit_treat() {

    TREAT_PAGE();
    LOGIN_REQUIRED();

    forms::posts::Edit form;
    form.load(context());

    if (!form.validate()) {
        //TODO add a more precise message
        add_error(_("The form is not valid."));
        go_back_to_previous_page();
        return;
    }

    results::Post post = form.get_post();

    const int returnCode = postsModel->edit(
        post
    );

    if (returnCode < 0) {
        add_error(_("Problem while saving post."));
        go_back_to_previous_page();
        return;
    }

    add_success(_("Post edited"));
    redirect(post.show_url());
}

// %%%NEXT_ACTION_MARKER%%% , do not delete

} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog
