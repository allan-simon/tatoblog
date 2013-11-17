/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan Simon <allan.simon@supinfo.com> 
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @package  Apps
 *
 */

#ifndef TATOBLOG_H 
#define TATOBLOG_H

/**
 * @file TatoBlog.h
 */
#include <map>

#include <cppcms/application.h>
#include <cppdb/frontend.h>

#include <cppcms_skel/controllers/webs/Img.h>
#include <cppcms_skel/controllers/webs/Css.h>
#include <cppcms_skel/controllers/webs/Js.h>

//%%%NEXT_CONTROLLER_INCLUDE_MARKER%%%, do not delete
#include "controllers/webs/Pages.h"

/** 
 * @namespace apps
 */
namespace tatoblog {
namespace apps {

/** 
 * @class TatoBlog 
 * Application class representing the website
 * All http request will be dispatched by this class
 */
class TatoBlog : public cppcms::application {

private:
    //%%%NEXT_MAIN_APP_CTRL_ATTR%%%
    ::controllers::webs::Img img;
    ::controllers::webs::Css css;
    ::controllers::webs::Js js;
    ::controllers::webs::Pages pages;

    /**
     * @brief Based on http header, we will try to guess the most suitable
     *        interface language
     *
     * @return The interface language code
     *
     * @since 5 September 2011
     *
     * @TODO for the moment it's a very naive algo
     */  
    std::string get_default_interface_lang();

public:
    /**
     * Constructor
     * Will connect every controllers to their respective paths
     * @param serv
     */
	TatoBlog(cppcms::service &serv);

    /**
     * Method who receive all web requests
     * get the user language of interface from url
     * @param url : url asked by user
     */
	void main(std::string url);
}; 

} // namespace apps
} // end namespace tatoblog
#endif
