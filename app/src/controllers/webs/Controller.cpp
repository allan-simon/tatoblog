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
 * @category Tatoblog
 * @package  Controllers
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */

#include "Controller.h"
#include "models/Blog.h"
namespace tatoblog {
namespace controllers {
namespace webs {

/**
 *
 */
Controller::Controller(cppcms::service &serv) :
    ::controllers::webs::Controller(serv)
{
    blogModel = new models::Blog();
}

/**
 *
 */
Controller::~Controller() {
    delete blogModel;
}

/**
 *
 */
void Controller::init_content(tatoblog::contents::BaseContent& content) {
    ::controllers::webs::Controller::init_content(content);
    content.blog = blogModel->get();
}




} // end namespace webs
} // end namespace controllers
} // end namespace tatoblog
