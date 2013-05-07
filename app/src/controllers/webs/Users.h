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

#ifndef TATOBLOGCONTROLLERS_WEBS_USERS_H
#define TATOBLOGCONTROLLERS_WEBS_USERS_H

#include "Controller.h"

namespace cppcmsskel {
namespace models {
    class Users;
}
}



namespace tatoblog {

//needed to avoid to include models directly here,
//which would have the side effects to require to recompile the// controller every time we modify a model. even though it does// not affect the controller
namespace models {
    // %%%NEXT_CLASS_MODEL_CTRL_MARKER%%% 
}

namespace controllers {
namespace webs { 
/**
 * @class Users Class to handle all the action related to users
 * @since 29 April 2013
 */
class Users : public Controller {
    public:
        /**
         * @brief Constructor
         * @since 29 April 2013
         */
        Users(cppcms::service &serv);

        /**
         * @brief Destructor
         * @since 29 April 2013
         */
        ~Users();

    private:
        /**
         * @brief User's model 
         * @since 8 May 2013
         */
        cppcmsskel::models::Users *usersModel;


        // %%%NEXT_VAR_MODEL_CTRL_MARKER%%%

        /**
         * @brief Page showing a form to login
         * @since 29 April 2013
         */
        void login();

        /**
         * @brief Page displaying nothing, only here to treat
         *        the login form
         * @since 29 April 2013
         */
        void login_treat();

// %%%NEXT_ACTION_MARKER%%% , do not delete

};

} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog

#endif
