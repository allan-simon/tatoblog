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


#ifndef TATOBLOGCONTROLLERS_WEBS_DRAFTS_H
#define TATOBLOGCONTROLLERS_WEBS_DRAFTS_H

#include "Controller.h"


namespace tatoblog {

//needed to avoid to include models directly here,
//which would have the side effects to require to recompile the
// controller every time we modify a model. even though it does
// not affect the controller
namespace models {
    class Drafts;
    // %%%NEXT_CLASS_MODEL_CTRL_MARKER%%% 
}

namespace controllers {
namespace webs { 
/**
 * @class Drafts
 * @brief @TODO add a description
 * @since 10 November 2013
 */
class Drafts : public Controller {
    public:
        /**
         * @brief Constructor
         * @since 10 November 2013
         */
        Drafts(cppcms::service &serv);

        /**
         * @brief Destructor
         * @since 10 November 2013
         */
        ~Drafts();

    private:
        /**
         * @brief TODO
         * @since %%MODEL_CTRL_TODAY%%
         */
        models::Drafts *draftsModel;

        // %%%NEXT_VAR_MODEL_CTRL_MARKER%%%
    

        /**
         * @brief @TODO add a description
         * @since 10 November 2013
         */
        void show(const std::string slug);

        /**
         * @brief @TODO add a description
         * @since 16 November 2013
         */
        void edit(
            const std::string slug
        );

        /**
         * @brief @TODO add a description
         * @since 16 November 2013
         */
        void edit_treat();

// %%%NEXT_ACTION_MARKER%%% , do not delete

};

} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog

#endif
