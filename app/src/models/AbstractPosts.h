/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @package  Models
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @link     https://github.com/allan-simon/tatoblog
 */

#ifndef TATOBLOG_ABSTRACT_POSTS
#define TATOBLOG_ABSTRACT_POSTS

#include <string>
#include <cppcms_skel/models/SqliteModel.h>
#include "results/Posts.h"

#define POST_CREATION_ERROR -1
#define POST_EDITION_ERROR -2
#define POST_NOT_INIT -3

namespace tatoblog {
namespace models {

class AbstractPosts : public cppcmsskel::models::SqliteModel {
        

    public:
        /**
         * @brief Constructor
         * @since 26 March 2013
         */
        AbstractPosts(const std::string &table);
 
        /**
         * @brief Create a new article in the database
         *
         * @param post          a post with all field filled, except post.id
         * @param userId        Id of the user who has written the article 
         *
         * @return The id of the newly created Post, or a negative
         *         number in case of failure
         */
        int create(
            const results::Post &post,
            const int userId = 0
        );
        
        /**
         * @brief Retrieve a post using the couple (lang,slug)
         *        that we extract from the URL
         * 
         * @param lang ISO code of the language in which the post
         *             is written
         * @param slug Slug of the post (i.e URL version of the
         *             title)
         *
         * @return The post corresponding to the criteria
         *
         * @since 21 Avril 2013
         */
        tatoblog::results::Post get_from_lang_and_slug(
            const std::string &lang,
            const std::string &slug
        );


        /**
         * @brief return all posts
         *
         * @return A list containing all the posts (without the main content)
         *
         * @since 22 Avril 2013
         */
        results::Posts get_all(void);

        /**
         * Update a post to new values
         * 
         * @param post Post containing the new values to reflect
         *             on the database
         * @return int a code to express if the update was
         *             successfull or not
         * @since 3 November 2013
         */
        int edit(
            const results::Post &post
        );
 
    protected:

        const std::string tableName;

        /**
         * @brief get a complete post out of a cppdb result
         *
         * @param res A cppdb result that was given after executing a query
         *
         * @return A post with every field filled
         *
         * @since 21 March 2013
         */
        results::Post get_from_result(
            cppdb::result &res
        );

};


} // end namespace models 
} // end namespace tatoblog

#endif

