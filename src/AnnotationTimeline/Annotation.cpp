//
// Created by rasmus on 2020-12-29.
//

#include "Annotation.h"

#include <utility>


Annotation::Annotation(qlonglong startpos, qlonglong endpos, const QString &text) {
    _startpos=startpos;
    _endpos=endpos;
    _text=text;

}

qlonglong Annotation::startpos() const {
    return _startpos;
}

qlonglong Annotation::endpos() const {
    return _endpos;
}

QString Annotation::text() {
    return _text;
}


