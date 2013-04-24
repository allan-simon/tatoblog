{
	"service" : {
		"api" : "http",
		"port" : 8080
	},

    "cache" : {
        "backend" : "thread_shared"
    },
	"http" : {
		"script_names" : ["/"]
	},
	"localization" : {
		"encoding" : "utf-8",
		"messages" : {
			"paths" : [ "../locale" ],
			"domains" : [ "hello" ]
		},
		"locales" : [ "en_GB.UTF-8", "fr_FR.UTF-8" ]
	},
    "session" : {
        "expire" : "renew",
        "timeout" : 604800,
        "location" : "server",
        "server" : {
            "storage" : "memory"
        }
    },
    "skel" : {
        "baseHost" : "http://127.0.0.1:8080",
        "innerCssFolder" : "../resources/skins/responsive/css/",
        "innerImgFolder" : "../resources/skins/responsive/img/",
        "innerJsFolder" : "../resources/skins/responsive/js/",
        "imgPath" : "/img/",
        "cssPath" : "/css/",
        "jsPath" : "/js/"

    },
	"tatoblog" : {
        "interfacelangs" : [
            ["en"  , "en_GB.UTF-8", "English", "English"],
            ["fr"  , "fr_FR.UTF-8", "Français", "French"]
        ],
        "sqlite3" : {
            "path" : "../data/sqlite3.db"
        }
	},
   "views" : {
        "default_skin" : "responsive"
    },

}
