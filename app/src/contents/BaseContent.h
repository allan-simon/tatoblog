
#ifndef TATOBLOG_CONTENTS_BASECONTENT_H
#define TATOBLOG_CONTENTS_BASECONTENT_H

#include "cppcms_skel/contents/content.h"
#include "results/Blog.h"

namespace tatoblog {
namespace contents {

struct BaseContent : public ::contents::BaseContent {
    results::Blog blog;
};


} // end of namespace tatoblog
} // end of namespace contents




#endif
