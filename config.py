

# where the application code will be generated
# relative to the "tools" directory
APP_ROOT = "../app"

# this represent the logical structure of your code
# the script init will use this to generate a skeleton
# of code
ARCHITECTURE = {
    'controllers' : {
        'Posts' : {
            'description': 'Module that deals with blog post',
            'methods' : {
                'show' : {}
            }
        }
    },

    'models': {
        'Posts' : {}
    },

    'models_controllers': [
        ('Posts','Posts')
    ]



}


# placeholders, replace the value by those specific to your
# projet
REPLACEMENTS = {
    '@AUTHOR@' : 'Allan Simon',
    '@EMAIL@': 'allan.simon@supinfo.com',
    '@PROJECT_NAME_CODE@' : 'tatoblog',
    '@PROJECT_NAME_HUMAN@': 'Tatoblog',
    '@MAIN_CLASS@' : 'TatoBlog',
    '@MAIN_CLASS_HEADER@' : 'TATOBLOG',
    '@DESCRIPTION@' : 'A blog platform in C++',
    '@PROJECT_WEBSITE' : 'https://github.com/allan-simon/tatoblog',
    '@YEARS@' : '2013',
    '    ' : '    '
}

