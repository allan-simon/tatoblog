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

#ifndef TATOBLOGCONTROLLERS_WEBS_POSTS_H
#define TATOBLOGCONTROLLERS_WEBS_POSTS_H

#include "Controller.h"
#include "results/Posts.h"



namespace tatoblog {
//needed to avoid to include models directly here,
//which would have the side effects to require to recompile the
// controller every time we modify a model. even though it does
// not affect the controller
namespace models {
    class Posts;
    // %%%NEXT_CLASS_MODEL_CTRL_MARKER%%% 
}



namespace controllers {
namespace webs { 
/**
 * @class Posts
 * @brief Module that deals with blog post
 * @since 17 March 2013
 */
class Posts : public Controller {
    public:
        /**
         * @brief Constructor
         * @since 17 March 2013
         */
        Posts(cppcms::service &serv);

        /**
         * @brief Destructor
         * @since 17 March 2013
         */
        ~Posts();

    private:
        /**
         * @brief TODO
         * @since %%MODEL_CTRL_TODAY%%
         */
        models::Posts *postsModel;

        // %%%NEXT_VAR_MODEL_CTRL_MARKER%%%
    

        /**
         * @brief Page to display a given article
         *
         * @param slug The article slug
         *
         * @since 17 March 2013
         */
        void show(const std::string slug);

        /**
         * @brief Page to add a new post
         * @since 26 March 2013
         */
        void write_new();

        /**
         * @brief Display nothing, page to treat a form used to
         *        add a new post
         * @since 26 March 2013
         */
        void write_new_treat();

        /**
         * @brief Display all the articles (actually only titles+introductions)
         * @since 21 April 2013
         */
        void show_all();


        /**
         * @brief Display a page to edit a given post
         * @param slug The article slug
         * @since 02 November 2013
         */
        void edit(const std::string slug);

        /**
         * @brief Display nothing, only here to treat the form
         * used to edit a post
         * @since 02 November 2013
         */
        void edit_treat();


        /**
         * Take a post and get the url to show it
         *
         * @param post The post to get the url from
         * @since 3 November 2013
         */
        const std::string post_show_url (
            const results::Post post
        ) const;

// %%%NEXT_ACTION_MARKER%%% , do not delete

};

} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog

#endif
