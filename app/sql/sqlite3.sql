pragma foreign_keys = off; -- required for import from C++ to work
begin;
    drop table if exists posts;
    drop table if exists users;
    drop table if exists salt;
    drop table if exists drafts;
    drop table if exists blog;

    -- table representing a user
    CREATE TABLE users (
        "id"          integer primary key autoincrement not null , 
        "username"    text    not null unique,             -- his nickname 
        "email"       text    not null unique,             -- his email address
        "image"       text    not null default "unknown" , -- his personnal image 
        "password"    text    not null,                    -- his password hashed
        "since"       integer not null,                    -- his registering date
        "homepage"    text    default "",                  -- his personnal webpage/website
        "description" text    default "",                  -- his self-written description
        "permission"  integer default 3                    -- which kind of user it is (admin, normal user etc.)
    );
    CREATE INDEX users_username_idx ON users (username);

    -- table representing a post (i.e a post written on the blog)
    -- TODO maybe have something to do a more precise restriction 
    --      (for example authorizing only some kind of users
    --      to edit a given pages (e.g only moderators/only admin)
    -- TODO same things for the visibility 
    create table posts (
        id integer primary key autoincrement not null,
        user_id  integer  not null default 0, 
        lang text not null,                            -- code iso 639-3 alpha 3 in which the articles is written
        slug text not null,                            -- "url" name of the article 
        title text not null,                           -- title of the article 
        introduction text not null,                         -- the content of the article itself
        main text not null,                         -- the content of the article itself
        unique(lang,slug)
    );
    create index posts_user_id_idx on posts(user_id);

    -- table to store draft, which are supposed to be exactly the same than a
    -- post. The rational to make it as a separate tables rathen than a field
    -- "is_draft" is that this way it does require to modify the Post model
    -- and it make easy to activate/deactivate this feature
    -- of course I'm open to discussion on that
    create table drafts (
        id integer primary key autoincrement not null,
        user_id  integer  not null default 0, 
        lang text not null,                            -- code iso 639-3 alpha 3 in which the articles is written
        slug text not null,                            -- "url" name of the article 
        title text not null,                           -- title of the article 
        introduction text not null,                         -- the content of the article itself
        main text not null,                         -- the content of the article itself
        unique(lang,slug)
    );
    create index drafts_user_id_idx on drafts(user_id);



    -- table to store the information about the blog
    create table blog (
        title text not null,
        introduction text not null,
        copyright text not null
    );

    -- table to store the salt used for the password encryption
    create table salt(
        value text not null 
    );


commit ;
