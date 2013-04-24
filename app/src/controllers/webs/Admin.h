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

#ifndef TATOBLOGCONTROLLERS_WEBS_ADMIN_H
#define TATOBLOGCONTROLLERS_WEBS_ADMIN_H

#include <cppcms_skel/controllers/webs/Controller.h>

//needed to avoid to include models directly here,
//which would have the side effects to require to recompile the// controller every time we modify a model. even though it does// not affect the controller
namespace cppcmsskel {
namespace models {
    class Users;
}
}

namespace models {
    class Blog;
    // %%%NEXT_CLASS_MODEL_CTRL_MARKER%%% 
}

namespace controllers {
namespace webs { 
/**
 * @class Admin
 * @brief Controller to manage all the pages related to configurating the blog itself
 * @since 22 April 2013
 */
class Admin : public Controller {
    public:
        /**
         * @brief Constructor
         * @since 22 April 2013
         */
        Admin(cppcms::service &serv);

        /**
         * @brief Destructor
         * @since 22 April 2013
         */
        ~Admin();

    private:
        /**
         * @brief Model to manage the blog information
         * @since 25 April 2013
         */
        models::Blog *blogModel;

        // %%%NEXT_VAR_MODEL_CTRL_MARKER%%%
    
        
        cppcmsskel::models::Users* usersModel;

        /**
         * @brief Use the first time you launch the blog to
         *        set up the admin account, basic blog information etc.
         * @since 22 April 2013
         */
        void install();

        /**
         * @brief Treat page, display nothing, use to treat the information
         *        sent by the 'install' page
         * @since 22 April 2013
         */
        void install_treat();

// %%%NEXT_ACTION_MARKER%%% , do not delete

};

} // End namespace webs
} // End namespace controllers

#endif
