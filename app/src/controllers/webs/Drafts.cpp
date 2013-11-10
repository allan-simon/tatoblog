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
//%%%NEXT_INC_MODEL_CTRL_MARKER%%%

namespace tatoblog {
namespace controllers {
namespace webs {

Drafts::Drafts(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{

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

// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog
