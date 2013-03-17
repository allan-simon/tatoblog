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
 * @package  Main
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */


#include <iostream>


#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <cppdb/frontend.h>
#include <cppcms/json.h>

#include "TatoBlog.h"

#include "cppcms_skel/generics/Config.h"

using namespace std;
using namespace cppcms;

int main(int argc,char ** argv)
{
    //TODO send notice message to logs instead of cout

    service app(argc, argv);
    /*load some conf defined variables*/
    Config *conf = Config::get_instance();

    conf->sqlite3Path = app.settings().get<string>(
        "tatoblog.sqlite3.path"
    );

    Config::set_css_path(
        app.settings().get<string>(
            "skel.cssPath"
        )
    );

    Config::set_img_path(
        app.settings().get<string>(
            "skel.imgPath"
        )
    );



    Config::set_inner_css_folder(
        app.settings().get<string>(
            "skel.innerCssFolder"
        )
    );

    Config::set_inner_img_folder(
        app.settings().get<string>(
            "skel.innerImgFolder"
        )
    );



        
    /*start the graph database*/

    //singletons::ActionId::get_instance();
    /*instantiate the website application*/
    cout << "[NOTICE] website to be launched" << endl;

    //booster::intrusive_ptr<apps::Tatoeba> tatoApp = new apps::Tatoeba(app);

    app.applications_pool().mount(
        cppcms::applications_factory<apps::TatoBlog>()
    );
    /*launch it */
    cout << "[NOTICE] website launched" << endl;
    app.run();
    cout << "[NOTICE] website stopped" << endl;

    /*time to destroy all the singletons*/
    //SearchEngine::kill();
    Config::kill();
}

