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

#ifndef TATOBLOG_BASEPOST_FORM
#define TATOBLOG_BASEPOST_FORM



#define _(X) cppcms::locale::translate(X)

#include <cppcms/form.h>

#include "results/Posts.h"

namespace tatoblog {
namespace forms{
namespace posts {

struct BasePost : public cppcms::form {

    /**
     * Widget to contain the language in which the article is  written
     *
     * @since 3 November 2013
     */
    cppcms::widgets::hidden lang;

    /**
     * Widget to contain the id of a post
     *
     * @since 3 November 2013
     */
    cppcms::widgets::hidden id;

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
     * button to not publish the post, but instead
     * saving it somewhere only the editor can see
     *
     * @since 2 November 2013
     */
    cppcms::widgets::submit saveAsDraft;

    /**
     * Initialize the different widgets of a form related to Post
     * without adding them
     *
     * @since 2 November 2013
     */
    void init() {
        //%%%NEXT_WIDGET_ADD_MARKER%%%

        lang.name("lang");

        id.name("id");
        id.value(std::to_string(POST_NOT_COMPLETELY_INIT));

        title.name("title");
        title.message(_("Title"));
        title.non_empty();
        
        slug.name("slug");
        slug.message(_("Slug (URL message)"));
        slug.non_empty();
        
        
        introduction.name("introduction");
        introduction.message(_("Introduction"));
        introduction.non_empty();

        main.name("main");
        main.message(_( "Main content"));

        publishAndShow.value(_("Publish and show"));
        publishAndShow.name("publishAndShow");
       
        saveAsDraft.value(_("Save as draft"));
        saveAsDraft.name("saveAsDraft");

    }

    /**
     * Initialize the common widgets of a form related to post
     * and add them
     *
     * @since 2 November 2013
     */
    void init_and_add() {
        init();

        add(id);
        add(lang);
        add(title); 
        add(slug);
        add(introduction);
        add(main);
        add(publishAndShow);
        add(saveAsDraft);
    }

    /**
     * Create a Post object out of the form
     * @since 3 November 2013
     */
    results::Post get_post() {
        return results::Post(
            std::stoi(id.value()),
            lang.value(),
            slug.value(),
            title.value(),
            introduction.value(),
            main.value()
        );
    }


};

} // end of namespace posts
} // end of namespace forms
} // end of namespace tatoblog


#endif

