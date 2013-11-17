/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @package  Forms
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @link     https://github.com/allan-simon/tatoblog
 */

#ifndef TATOBLOG_DRAFT_EDIT
#define TATOBLOG_DRAFT_EDIT


#include <cppcms/form.h>

namespace tatoblog {
namespace forms{
namespace drafts {

/**
 * @struct edit
 * @brief  @TODO
 * @since  16 November 2013
 *
 */
struct Edit : public cppcms::form {

    //%%%NEXT_WIDGET_VAR_MARKER%%%

    /**
     * @brief button to submit the form
     */
    cppcms::widgets::submit submit;

    /**
     * @brief Constructor
     */
    Edit() {

        //%%%NEXT_WIDGET_ADD_MARKER%%%

        add(submit);
        submit.name(
            cppcms::locale::translate("submit")
        );
        submit.value("submit");
    }


};


} // end of namespace drafts
} // end of namespace forms
} // end of namespace tatoblog


#endif


