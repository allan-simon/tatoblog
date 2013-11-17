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

    dispatcher().assign("/edit", &Drafts::edit, this);
    dispatcher().assign("/edit_treat", &Drafts::edit_treat, this);
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
void Drafts::edit() {

    contents::drafts::Edit c;
    init_content(c);


    render("drafts_edit", c);
}


/**
 *
 */
void Drafts::edit_treat() {

    forms::drafts::Edit form;
    form.load(context());

    if (!form.validate()) {
        go_back_to_previous_page();
    }

}


// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog
