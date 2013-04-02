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
 * @package  Form
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */


#ifndef TATOBLOG_WRITE_NEW
#define TATOBLOG_WRITE_NEW


#include <cppcms/form.h>

namespace forms{
namespace posts {

/**
 * @struct write_new Form to add a new post
 * @since  26 March 2013
 *
 */
struct WriteNew : public cppcms::form {

    //%%%NEXT_WIDGET_VAR_MARKER%%%
       
    /**
     * @brief text field to choose what will be the title
     *        of the post
     *
     * @since 2 April 2013
     */
    cppcms::widgets::text title;
     
    /**
     * @brief text field to choose what will be the slug
     *        of the post
     *
     * @since 26 March 2013
     */
    cppcms::widgets::text slug;
    cppcms::widgets::textarea introduction;
    cppcms::widgets::textarea main;

    /**
     * @brief button to publish the article and view it
     */
    cppcms::widgets::submit publishAndShow;

    /**
     * @brief Constructor
     */
    WriteNew() {

        //%%%NEXT_WIDGET_ADD_MARKER%%%

        add(publishAndShow);
        publishAndShow.name(
            cppcms::locale::translate("Publish and show")
        );
        publishAndShow.value("publishAndShow");
    }


};


} // end of namespace posts
}// end of namespace forms


#endif


