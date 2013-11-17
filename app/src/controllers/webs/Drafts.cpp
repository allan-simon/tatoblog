/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @package  Controllers
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @link     https://github.com/allan-simon/tatoblog
 */

#include <cppcms/session_interface.h>
#include "Drafts.h"

#include "contents/Drafts.h"

#include "models/Drafts.h"
#include "generics/markdown.h"
//%%%NEXT_INC_MODEL_CTRL_MARKER%%%

#ifndef _
    #define _(X) cppcms::locale::translate(X)
#endif

namespace tatoblog {
namespace controllers {
namespace webs {

Drafts::Drafts(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{

    dispatcher().assign("/show/(.+)", &Drafts::show, this, 1);

    dispatcher().assign("/edit/(.+)", &Drafts::edit, this, 1);
    dispatcher().assign("/edit_treat", &Drafts::edit_treat, this);
    dispatcher().assign("/show-all", &Drafts::show_all, this);
    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete

    draftsModel = new models::Drafts();
    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%
}

/**
 *
 */
Drafts::~Drafts() {
    delete draftsModel;
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
}

/**
 *
 */
void Drafts::show(const std::string slug) {

    LOGIN_REQUIRED();

    contents::drafts::Show c;
    init_content(c);
    std::string lang = get_interface_lang();

    c.post  = draftsModel->get_from_lang_and_slug(
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



    render("drafts_show", c);
}

/**
 *
 */
void Drafts::edit(
    const std::string slug
) {

    LOGIN_REQUIRED();

    const std::string lang = get_interface_lang();

    results::Post post = draftsModel->get_from_lang_and_slug(
        lang,
        slug
    );

    if (!post.exists()) {
        add_error(_("This article does not exists"));
        go_to_main_page();
        return;
    }

    cache().rise(post.cache_key());

    contents::drafts::Edit c(post);
    init_content(c);


    render("drafts_edit", c);
}


/**
 *
 */
void Drafts::edit_treat() {

    TREAT_PAGE();
    LOGIN_REQUIRED();

    forms::drafts::Edit form;
    form.load(context());

    if (!form.validate()) {
        //TODO add a more precise message
        add_error(_("The form is not valid."));
        go_back_to_previous_page();
        return;
    }

    results::Post post = form.get_post();

    const int returnCode = draftsModel->edit(
        post
    );

    if (returnCode < 0) {
        add_error(_("Problem while saving draft."));
        go_back_to_previous_page();
        return;
    }

    if (form.publishAndShow.value()) {
        redirect(post.publish_url());
        return;
    }

    add_success(_("Draft edited"));
    redirect(post.draft_url());

}


/**
 *
 */
void Drafts::show_all() {

    contents::drafts::ShowAll c;
    init_content(c);


    render("drafts_show_all", c);
}

// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog
