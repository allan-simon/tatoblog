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
#include "Posts.h"


#include "contents/Posts.h"

#include "models/Posts.h"
//%%%NEXT_INC_MODEL_CTRL_MARKER%%%


namespace controllers {
namespace webs {

Posts::Posts(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{

    dispatcher().assign("/show", &Posts::show, this);
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
void Posts::show() {

    contents::posts::Show c;
    init_content(c);


    render("posts_show", c);
}

// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
