#! /usr/bin/env python
from httpclient import Cookie, Session
import urllib


#we first try to access to a page that require login
#we're supposed to be redirected to the login page

def create_post(
    session = Session(print_cookies = False),
    title = 'test',
    slug = 'test',
    introduction = 'plop plop',
    main = 'tagada',
):
    WRITE_POST_URL = "/posts/write-new"
    WRITE_POST_TREAT = "/posts/write-new_treat"
    NEW_POST_URL ='/posts/show/'


    session.transmit(WRITE_POST_URL)
    if (session.status == 404):
        print("ERROR this page is supposed to exist")
        return None
    if (session.status != 200):
        print("ERROR supposed to access directly to it")
        return None

    postData = urllib.urlencode({
        'title' : title,
        'slug' : slug,
        'introduction' :introduction,
        'main' : main
    })
    writePostTreatHTML = session.transmit(
        url = WRITE_POST_TREAT,
        post_data = postData,
        headers = {'Cookie': session.received['cppcms_session'] }
    );


    if (session.status != 302):
        print("ERROR while trying to add a post")
        return None

    newAPostHTML = session.transmit(
        NEW_POST_URL + slug,
        headers = {'Cookie': session.received['cppcms_session'] }
    );
    #TODO

    return session

if __name__ == '__main__':
    create_post()




