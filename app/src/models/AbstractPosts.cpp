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

#include "models/AbstractPosts.h"

namespace tatoblog {
namespace models {

/**
 *
 */
AbstractPosts::AbstractPosts(const std::string &_tableName) :
    SqliteModel(),
    tableName(_tableName)
{
}

/**
 *
 */
int AbstractPosts::create(
    const results::Post &post,
    const int userId
) {
    cppdb::statement statement = sqliteDb.prepare(
        "INSERT INTO " + tableName + "("
        "    title,"
        "    slug,"
        "    introduction,"
        "    main,"
        "    lang,"
        "    user_id"
        ") "
        "VALUES ( "
        "   ? ,"
        "   ? ,"
        "   ? ,"
        "   ? ,"
        "   ? ,"
        "   ? "
        ")"
    );
    
    statement.bind(post.title);
    statement.bind(post.slug);
    statement.bind(post.introduction);
    statement.bind(post.main);
    statement.bind(post.lang);
    statement.bind(userId);

    if (!execute_simple(statement)) {
        return POST_CREATION_ERROR;
    }
    const int id = statement.last_insert_id();
    return id;
}

/**
 *
 */
results::Post AbstractPosts::get_from_lang_and_slug(
    const std::string &lang,
    const std::string &slug
) {
    cppdb::statement getFromLangAndSlug = sqliteDb.prepare(
        "SELECT "
        "   id as post_id, "
        "   * "
        "FROM " + tableName + " "
        "WHERE "
        "   lang = ? AND "
        "   slug = ? "
        "LIMIT 1"
    );
    getFromLangAndSlug.bind(lang);
    getFromLangAndSlug.bind(slug);

    cppdb::result res = getFromLangAndSlug.row();
    results::Post post = get_from_result(res);
    
    getFromLangAndSlug.reset();
    return post;
}

/**
 *
 */
results::Posts AbstractPosts::get_all(void) {
    results::Post post;
    cppdb::statement allPosts = sqliteDb.prepare(
        "SELECT "
        "   id,   "
        "   lang, "
        "   slug, "
        "   title, "
        "   introduction "
        "FROM " + tableName + " "
        "ORDER BY id DESC"
    );

    cppdb::result res = allPosts .query();
    results::Posts posts;
    while (res.next()) {
        results::Post tmpPost(
            res.get<int>("id"),
            res.get<std::string>("lang"),
            res.get<std::string>("slug"),
            res.get<std::string>("title"),
            res.get<std::string>("introduction")
        );
        posts.push_back(tmpPost);
    }
    allPosts.reset();
    return posts;
}

/**
 *
 */
results::Post AbstractPosts::get_from_result(
    cppdb::result &res
) {
    results::Post post;
    
    if (!res.empty()) {
        post.id = res.get<int>("post_id");
        post.lang = res.get<std::string>("lang");
        post.introduction = res.get<std::string>("introduction");
        post.main = res.get<std::string>("main");
        post.slug = res.get<std::string>("slug");
        post.title = res.get<std::string>("title");
    } else {
        post.id = 0;
    }
    return post;
}

/**
 *
 */
int AbstractPosts::edit(
    const results::Post &post
) {
    cppdb::statement statement = sqliteDb.prepare(
        "UPDATE " + tableName + " "
        "SET"
        "    title = ?,"
        "    slug = ?,"
        "    introduction = ?,"
        "    main = ?,"
        "    lang = ?"
        "WHERE "
        "    id = ? "
    );

    // update part
    statement.bind(post.title);
    statement.bind(post.slug);
    statement.bind(post.introduction);
    statement.bind(post.main);
    statement.bind(post.lang);

    // where part
    statement.bind(post.id);

    if (!execute_simple(statement)) {
        return POST_EDITION_ERROR;
    }
    return 1;
}

} // end namespace models
} // end namespace tatoblog




