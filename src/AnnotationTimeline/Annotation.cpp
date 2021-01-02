//
// Created by rasmus on 2020-12-29.
//

#include "Annotation.h"

#include <utility>


Annotation::Annotation(QJsonObject data): m_itemData(std::move(data)) {
}
