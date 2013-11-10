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

namespace tatoblog {
namespace controllers {
namespace webs {

Drafts::Drafts(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{

    dispatcher().assign("/show/(.+)", &Drafts::show, this, 1);
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

// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog
